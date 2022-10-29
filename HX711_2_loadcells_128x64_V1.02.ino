/*
 Basic 2 loadcell program measuring belt tesion for 3D printers
 Optimized for Arduino Nano board
 Maximum loadcell weight 2 Kg
 HX711.DOUT  - we use digital pins
 HX711.PD_SCK - we use digital pins
 HX711 XWF is set @ 10 samples/second (standard setting)
 pin A4 I2C SDA for Oled display
 pin A5 I2C SLC for Oled display
 Versiion V1.02 15-10-2022
 */
 
#include <U8glib.h>             //https://code.google.com/p/u8glib/
#include <Wire.h>               //inbox
#include <EEPROM.h>             //inbox
#include <HX711.h>              //BOGDE HX711 from Github https://github.com/bogde/HX711
#include <Button.h>             //https://github.com/JChristensen/Button

HX711 Scale1; // Loadcell_1
HX711 Scale2; // Loadcell_2

// HX711 circuit wiring
const int Loadcell_1_DOUT_PIN = 7;
const int Loadcell_1_SCK_PIN = 6;
const int Loadcell_2_DOUT_PIN = 4;
const int Loadcell_2_SCK_PIN = 5;

int ValueA1, ValueA2;               // stores the low value of the ramp
int ValueB1, ValueB2;               // stores the high value of the ramp
int ValueATemp1, ValueATemp2;       // stores the temp low value of the ramp
int ValueOut1, ValueOut2;           // the output value in grams
int ForceValueRaw1, ForceValueRaw2; // the raw value from the HX711
int ForceTemp1, ForceTemp2;         // Value without zero-ing value
int ForceZero1, ForceZero2;         // Zero-ing value
int CalibWeight = 100;              // Calibration weight at first calibration. Can be altered during calibration sequence and stored in EEprom
long Address = 0;                   // Starting at the first byte on the eeprom
int CountValue = 1;
bool Reverse =  0;                  // Reverse is used for swapping the loadcell collums in the display
//int LoadBRX;                        // calibration value coming from serial read //debug

//---button settings -----------

#define RIGHT_PIN 8        //from Arduino pin to ground
#define DOWN_PIN 9         //from Arduino pin to ground
#define LEFT_PIN 10        //from Arduino pin to ground
#define SELECT_PIN 11      //from Arduino pin to ground
#define UP_PIN 12          //from Arduino pin to ground
//-
#define PULLUP true        //To keep things simple, we use the Arduino's internal pullup resistor.
#define INVERT true        //Since the pullup resistor will keep the pin high unless the switch is closed, this is negative logic, i.e. a high state means the button is NOT pressed. (Assuming a normally open switch.)
#define DEBOUNCE_MS 20     //A debounce time of 20 milliseconds usually works well for tactile button switches.
//-
#define REPEAT_FIRST1 500   //ms required before repeating on long press
#define REPEAT_INCR1 100    //repeat interval for long press
#define MIN_COUNT1 0
#define MAX_COUNT1 20000
#define REPEAT_FIRST2 500   //ms required before repeating on long press
#define REPEAT_INCR2 100    //repeat interval for long press
#define MIN_COUNT2 0
#define MAX_COUNT2 20000
//-
enum {WAIT1, INCR1, DECR1, WAIT2, INCR2, DECR2};         //The possible states for the state machine
uint8_t STATE1, STATE2;                                  //The current state machine state
int PulseCounter1, PulseCounter2, PulseCounter3;         //The number that is adjusted
int lastPulseCounter1, lastPulseCounter2 = 0;            //Previous value of count (initialized to ensure it's different when the sketch starts)
unsigned long rpt1 = REPEAT_FIRST1;                      //A variable time that is used to drive the repeats for long presses
unsigned long rpt2 = REPEAT_FIRST2;                      //A variable time that is used to drive the repeats for long presses

// buttons used for calibration and tare function
Button btnUP(UP_PIN, PULLUP, INVERT, DEBOUNCE_MS);         //raise the calibration weight value
Button btnDOWN(DOWN_PIN, PULLUP, INVERT, DEBOUNCE_MS);     //lower the calibration weight value
Button btnLEFT(LEFT_PIN, PULLUP, INVERT, DEBOUNCE_MS);     //controlling calibration step value from 1-10-50-200
Button btnRIGHT(RIGHT_PIN, PULLUP, INVERT, DEBOUNCE_MS);   //step through calibration sequence
Button btnSELECT(SELECT_PIN, PULLUP, INVERT, DEBOUNCE_MS); //return to main menu and tare function

//---------------------------------------end button-------------------------------------------

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0); //I2C OLED display driver line

void setup()
{
  Scale1.begin(Loadcell_1_DOUT_PIN, Loadcell_1_SCK_PIN);
  Scale2.begin(Loadcell_2_DOUT_PIN, Loadcell_2_SCK_PIN);
 
  //read the data from the EEprom and put it in the variables
  ValueA1 = (EEPROMReadlong(0)); // read the EEprom value
  ValueB1 = (EEPROMReadlong(4)); // read the EEprom value
  ValueA2 = (EEPROMReadlong(8)); // read the EEprom value
  ValueB2 = (EEPROMReadlong(12)); // read the EEprom value
  CalibWeight = (EEPROMReadlong(16)); // read the EEprom value
  //------------------------------------------------------------

  Serial.begin(9600);
  Serial.println("2 x LOAD CELL READER");
  Serial.println("Version 1.02     ");
  Serial.println("Jupa Creations");
  Serial.println("The Netherlands");
  Serial.print("CalibWeight-"); Serial.println(CalibWeight);
  Serial.print("ValueA1 "); Serial.println(ValueA1);
  Serial.print("ValueB1 "); Serial.println(ValueB1);
  Serial.print("ValueA2 "); Serial.println(ValueA2);
  Serial.print("ValueB2 "); Serial.println(ValueB2);

  PulseCounter1 = 0;  // for calibration value up or down
  PulseCounter2 = 0;  // for calibration sequence
  PulseCounter3 = 0;  // for calibration value up/down counter pre set
  
  ForceZero1 = 0;
  ForceZero2 = 0;
  ValueOut1 = 0;
  ValueOut2 = 0;
  Reverse = 1; // Reverse is used for swapping the collums in the display. If value is 0 we look from the rear of the machine. If value is 1 we look from the front of the machine.
}

void loop()//---------------------------------------------------------------
{
  // picture loop
  u8g.firstPage();
  do
  {
    draw();
  } while ( u8g.nextPage() );

  // rebuild the picture after some delay
  delay(10);

  if (CalibWeight >= 10000 && CalibWeight < 0 )
{
  CalibWeight = 9999; //prevention for corrupted eeprom value
}
// do we need a negative trap too?
//read the push buttons
btnUP.read();
btnDOWN.read();
btnLEFT.read();
btnRIGHT.read();
btnSELECT.read();

// a counter to raise or lower the calibration value step by step or quickly
if (PulseCounter1 != lastPulseCounter1)
{ //print the count if it has changed
  lastPulseCounter1 = PulseCounter1;
  //Serial.println(PulseCounter1, DEC); //debug
}

switch (STATE1)
{
  case WAIT1:                              //wait for a button event
    if (btnUP.wasPressed())
        STATE1 = INCR1;
      else if (btnDOWN.wasPressed())
        STATE1 = DECR1;
      else if (btnUP.wasReleased())         //reset the long press interval
        rpt1 = REPEAT_FIRST1;
      else if (btnDOWN.wasReleased())
        rpt1 = REPEAT_FIRST1;
      else if (btnUP.pressedFor(rpt1))
      { //check for long press
        rpt1 += REPEAT_INCR1;                //increment the long press interval
        STATE1 = INCR1;
      }
      else if (btnDOWN.pressedFor(rpt1))
      {
        rpt1 += REPEAT_INCR1;
        STATE1 = DECR1;
      }
      break;

    case INCR1:                                //increment the counter
      PulseCounter1 = min(PulseCounter1++, MAX_COUNT1);      //but not more than the specified maximum
      STATE1 = WAIT1;
      CalibWeight = CalibWeight + CountValue;
      break;

    case DECR1:                                //decrement the counter
      PulseCounter1 = max(PulseCounter1--, MIN_COUNT1);      //but not less than the specified minimum
      STATE1 = WAIT1;
      CalibWeight = CalibWeight - CountValue;
      break;
  }

  if (btnRIGHT.wasReleased()) // calibration menu counter
{ //If the button was released pulse counter
  PulseCounter2++;
}

if (btnLEFT.wasReleased()) //
{ //If the button was released
  PulseCounter3++;
}

if (PulseCounter3 == 0)
{
  CountValue = 1;
}

if (PulseCounter3 == 1)
{
  CountValue = 10;
}

if (PulseCounter3 == 2)
{
  CountValue = 50;
}

if (PulseCounter3 == 3)
{
  CountValue = 100;
}

if (PulseCounter3 == 4)
{
  CountValue = 200;
}

if (PulseCounter3 == 5)
{
  PulseCounter3 = 0;
}

if (btnSELECT.wasReleased()) // reset to main screen and zero the counters
{ //If the button was released
  PulseCounter2 = 0;
  PulseCounter3 = 0;
}
  //----------------------------------------------------

  // force calculation in grams //////////////////////
  ForceValueRaw1 = (Scale1.read() / 128); // raw value from loadcell divided by 128
                   ForceTemp1 = ((CalibWeight - 0.0) / (ValueB1 - ValueA1)) * ((ForceValueRaw1) - ValueA1) + 0.0;
                   ValueOut1 = ForceTemp1 - ForceZero1;
                   if (ValueOut1 <= 2 && ValueOut1 >= -2) //zero point blockout
{
  ValueOut1 = 0;
}

// force calculation in grams //////////////////////
ForceValueRaw2 = (Scale2.read() / 128); // raw value from loadcell divided by 128
                 ForceTemp2 = ((CalibWeight - 0.0) / (ValueB2 - ValueA2)) * ((ForceValueRaw2) - ValueA2) + 0.0;
                 ValueOut2 = ForceTemp2 - ForceZero2;
                 if (ValueOut2 <= 2 && ValueOut2 >= -2) //zero point blockout
{
  ValueOut2 = 0;
}
}  // end void loop---------------------------------------------------------------------------------------------------------

//  ++++++ functions +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//This function will write a 4 byte (32bit) long to the eeprom at the specified Address to adress + 3.
void EEPROMWritelong(int Address, long value)
{
  //Decomposition from a long to 4 bytes by using bitshift. One = Most significant -> Four = Least significant byte
  byte four = (value & 0xFF);
  byte three = ((value >> 8) & 0xFF);
  byte two = ((value >> 16) & 0xFF);
  byte one = ((value >> 24) & 0xFF);

  //Write the 4 bytes into the eeprom memory.
  EEPROM.write(Address, four);
  EEPROM.write(Address + 1, three);
  EEPROM.write(Address + 2, two);
  EEPROM.write(Address + 3, one);
}

//This function will return a 4 byte (32bit) long from the eeprom at the specified Address to adress + 3.
long EEPROMReadlong(long Address)
{
  //Read the 4 bytes from the eeprom memory.
  long four = EEPROM.read(Address);
  long three = EEPROM.read(Address + 1);
  long two = EEPROM.read(Address + 2);
  long one = EEPROM.read(Address + 3);
  //Return the recomposed long by using bitshift.
  return ((four << 0) & 0xFF) + ((three << 8) & 0xFFFF) + ((two << 16) & 0xFFFFFF) + ((one << 24) & 0xFFFFFFFF);
}

//--------====================================================================================================================================================================================================================
void draw(void)
{
  // graphic commands to redraw the complete screen should be placed here
  u8g.setFont(u8g_font_6x12); //set font type and size
 
  if (PulseCounter2 == 1)
    // we have pushed the ">" button the first time.
    // in this state if needed you can change the calibration weight.
    // use the up and down button to change the value.
    // single press for one step
    // hold press for quick steps
    // if the value is correct just proceed to next step
    // use ">" button when ready
  {
    u8g.setPrintPos(0, 10);
    u8g.print("Calibration weight ");
    u8g.setPrintPos(0, 25);
    u8g.print(CalibWeight, 1);
    u8g.setPrintPos(40, 25);
    u8g.print("Grams");
    u8g.setPrintPos(76, 25);
    u8g.print("CV=");
    u8g.setPrintPos(95, 25);
    u8g.print(CountValue);
    u8g.setPrintPos(0, 40);
    u8g.print("Use + - < button");
    u8g.setPrintPos(0, 60);
    u8g.print("Ready? > button");
    ValueA1 = ForceValueRaw1; //read the current value LC1 without load
  }

  //Calib loadcell 1
  if (PulseCounter2 == 2) // we have pushed the ">" button once with no load.
  {
    u8g.setPrintPos(0, 10);
    u8g.print("Place Weight on LC 1");
    u8g.setPrintPos(0, 23);
    u8g.print("Raw value LC 1");
    u8g.setPrintPos(0, 36);
    u8g.print(ForceValueRaw1);
    u8g.setPrintPos(0, 60);
    u8g.print("Press > button");
    ValueB1 = ForceValueRaw1; //read the current value LC1 with load
  }

  if (PulseCounter2 == 3) // We have pushed the ">" button with a calibration weight on the loadcell.
  {
    u8g.setPrintPos(0, 10);
    u8g.print("LC 1 finished");
    u8g.setPrintPos(0, 23);
    u8g.print("Raw value LC 1");
    u8g.setPrintPos(0, 36);
    u8g.print(ForceValueRaw1);
    u8g.setPrintPos(0, 49);
    u8g.print("Remove Weight");
    u8g.setPrintPos(0, 60);
    u8g.print("Press > button");
    ValueA2 = ForceValueRaw2; //read the current value LC2 without load
  }

  //Calib loadcell 2
  if (PulseCounter2 == 4) // Push the ">" button once with no weight.
  {
    u8g.setPrintPos(0, 10);
    u8g.print("Place Weight on LC 2");
    u8g.setPrintPos(0, 23);
    u8g.print("Raw value LC 2");
    u8g.setPrintPos(0, 36);
    u8g.print(ForceValueRaw2);
    u8g.setPrintPos(0, 60);
    u8g.print("Press > button");
    ValueB2 = ForceValueRaw2; //read the current value LC2 with load
  }

  if (PulseCounter2 == 5) // Push the ">" button once with a calibration weght on the loadcell.
  {
    u8g.setPrintPos(0, 10);
    u8g.print("LC 2 finished");
    u8g.setPrintPos(0, 23);
    u8g.print("Raw value LC 2");
    u8g.setPrintPos(0, 36);
    u8g.print(ForceValueRaw2);
    u8g.setPrintPos(0, 49);
    u8g.print("Remove Weight");
    u8g.setPrintPos(0, 60);
    u8g.print("Press > button");
  }

  if (PulseCounter2 == 6)
  {
    u8g.setPrintPos(0, 10);
    u8g.print("Calibration finished");
    u8g.setPrintPos(0, 28);
    u8g.print("to save values");
    u8g.setPrintPos(0, 60);
    u8g.print("Press > button");
  }

  if (PulseCounter2 == 7)
  {
    PulseCounter2 = 0;
    // store data to the eeprom
    EEPROMWritelong(Address, ValueA1);  //Save calibration value A1 to the internal EEprom
    Address += 4;
    EEPROMWritelong(Address, ValueB1);  //Save calibration value B1to the internal EEprom
    Address += 4;
    EEPROMWritelong(Address, ValueA2);  //Save calibration value A2 to the internal EEprom
    Address += 4;
    EEPROMWritelong(Address, ValueB2);  //Save calibration value B2 to the internal EEprom
    Address += 4;
    EEPROMWritelong(Address, CalibWeight);  //Save calibration weigth value to the internal EEprom
    Address += 4;
    delay(10);
  }

  if (PulseCounter2 == 0)
  {
    if (Reverse == 0) // display mounted with view from the front is Reverse (0) mode with view from rear = normal (1)
    {
    u8g.setPrintPos(20, 10);
    u8g.print("LC-L");
    u8g.setPrintPos(20, 25);
    u8g.print(ValueOut1);
    u8g.setPrintPos(20, 40);
    u8g.print("grams");
    
    u8g.setPrintPos(76, 10);
    u8g.print("LC-R");
    u8g.setPrintPos(76, 25);
    u8g.print(ValueOut2);
    u8g.setPrintPos(76, 40);
    u8g.print("grams");
    }
    else
    {
    u8g.setPrintPos(20, 10);
    u8g.print("LC-L");
    u8g.setPrintPos(20, 25);
    u8g.print(ValueOut2);
    u8g.setPrintPos(20, 40);
    u8g.print("grams");
    
    u8g.setPrintPos(76, 10);
    u8g.print("LC-R");
    u8g.setPrintPos(76, 25);
    u8g.print(ValueOut1);
    u8g.setPrintPos(76, 40);
    u8g.print("grams");
    }

    u8g.setPrintPos(60, 10);
    u8g.print("I");
    u8g.setPrintPos(60, 20);
    u8g.print("I");
    u8g.setPrintPos(60, 30);
    u8g.print("I");
    u8g.setPrintPos(60, 40);
    u8g.print("I");
    u8g.setPrintPos(60, 50);
    u8g.print("I");

    u8g.setPrintPos(20, 60);
    u8g.print("Jupa Creations");
  }
  
  if (btnSELECT.pressedFor(3000))// && (PulseCounter2 == 0))
  {
   ForceZero1 = ForceTemp1; // write current value to compensate the zero offset.
   ForceZero2 = ForceTemp2; // write current value to compensate the zero offset.
   u8g.setPrintPos(120, 10);
   u8g.print("T");
      u8g.setPrintPos(120, 20);
   u8g.print("a");
      u8g.setPrintPos(120, 30);
   u8g.print("r");
      u8g.setPrintPos(120, 40);
   u8g.print("e");
   PulseCounter2 = 0;
  }
}

// Copyright by Jupa Creations The Netherlands 2022
// www.jupacreations.com

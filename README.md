# Belt-Balance-System
BBS
Belt Balance System
What is BBS?
BBS is a device that can be used inside a 3D printer to measure 2 independed belt tensions.
With readily available electronic components you can make this DIY device with small effort and skills.
The base BBS is in base designed for a RatRig V-Core 3 300mm 3D printer

Feel free to use this project in NON COMMERCIAL DIY products. The project comes as is and there is no warranty or questions to be answered, sorry.

Parts needed:
2 x HX711 XFW version ADC board
1 x 5 way switch
1 x Arduino Nano
1 x 128x64 OLED I2C display
1 x pre made JLC Jupa Creations BBS board
1 x JST connector (male)
1 x Dupont 2 pin (male)
1 x Dupont 2 pin short (female)
4 x GT2 10 mm idler without tooth
2 x GT2 10 mm idler with tooth
2 x 28x28 (3030 profile) corner brackets
4 x M5x40 mm countersunk hexagon head
2 x  M5x20 mm low flat hexagon head
2 x M6x12 mm hexagon head
2 x M5x12 mm hexagon head
4 x M6 1mm washer
10 x M5 conical washer
8 x JST-XH 4 pins
1 x JST-XH 2 pins
6 x M5 lock nut
6 x washer M5x 1 mm thickness
6 x printed parts (STL) available for download
1 x 1 m 18AWG 2 wire cable
1 x calibration weight 200 gram

Tools needed:
1 x soldering iron
1 x solder
1 x side cutter (small)
1 x 4.5 mm drill
1 x 5 mm thread tapper
JST-XH crimping tool
PC
USB Mini cable

Building instructions:
Solder the electronic components and connectors on the correct position on the BBS board.
Drill a 4.5 mm hole in the side of the load cell. (see drawing)
Tap a M5 thread in the 4.5 mm hole.
Crimp the 4 pin JST-XH connector to the red, black, green, white wire of the loadcells.
Place the loadcells with the 3030 corner brackets and screws on a 3030 profile.
Make sure the arrow of the loadcell is pointing down.

Load with the Arduino IDE “BBS-2022.ino“ the sketch to the Arduino Nano.
Power up the BBS board with 5 volt.

Calibration:
Calibration screen 1
Press the > key one time and the calibration start screen appears.
By standard the calibration weight is set to 200 grams.
Press the + key to raise the calibration weight value.
Press the – key to lower the calibration weight value.
To change the calibration +/- step value press the < key each time to rotate through the step value 1, 10, 25, 100, 200.
When the correct calibration value is set, press the > key.
Calibration screen 2
Place the calibration weight on the LC-1 loadcell.
Press the > key.
Calibration screen 3
Remove the calibration weight from the LC-1
Press the > key.
Calibration screen 4
Place the calibration weight on the LC-2
Press the > key.
Calibration screen 5
Remove the calibration weight on the LC-2
Press the > key.
Calibration screen 6
Press the > key to save the values to the EEprom.
Now mount the loadcells in the printer but do not route the belts along the loadcell idlers or put any pressure or force on the loadcell.
Power up the BBS and press the select key for more then 3+ seconds and the loadcell TARE option will zero out to 0.
Now route the belts along the loadcells.
Adjust the belt tension to the proper value equal for each side. Use 300 grams as a base setting for GT2 9mm width belts for Vcore 3-300. 
When you are ready with your adjustments and setup belt tension you can unpower the BBS.
If you suspect belt tension has changed over time and differ from your base setting, power on the BBS and read the display to check.
Do not use the TARE option to reset the load cells to zero once the belts are routed through the tension system! In case you do,unroute the belts and press the select key for 3+ seconds.

Enjoy your DIY BBS.



 

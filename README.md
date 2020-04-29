# D-workx 234
CoreXY 3D printer 200-300-400 XYZ build volume

Work in progress! 99.9% is ready. Parts are ready and approoved for printing.
Instruction manual is more work as expected and time issues are a common thing.
I let you know when ALL is finished.

For comments please use the facebook group.

https://www.facebook.com/groups/2417500851660171/

How it works.....and the facts
D-workx 234 by JupaCreations Printed parts all designed with Tinkercad and born out of experience after building
HEVO by Scott_3D 			https://www.thingiverse.com/thing:2254103
V-king 3D-pro by Roy Berentsen 	https://www.thingiverse.com/thing:2921021.
Different in certain areas where both other designs were not up to my way of tinkering. Knowledge learned along the way and now put into this project. Enjoy the same way as I did during the prototype phase. 
Outside dimensions 540 x 540 x 540 mm.
Buildplate dimensions XY 400 x 400 mm maximum.
Currently used heatbed 328 x 328 mm Z height maximum 385 mm (540 mm cube with E3D V6) 
Sides can be easily enclosed for airdraft reduction for those who want to print filaments that need it. In a later stage the printer can be enclosed fully for heatchamber printing. All parts gathered by shopping all around the world. 

D-workx CORE XYZ 234 is based on the proven CORE XYZ concept. This means the printhead is moving in XY directions but the printbed does not move (stationary) in horizontal positions like I3 based cartesian printers. Due to the reduced XY mass movement, less ringing, resonation and artefacts are the result at higher print speeds if needed.

The D-workx XYZ 234 is a very simple to build DIY concept not using special parts or tools and in my opinion clever way when it comes to the use of some technical details like the Z-belt bed lifting in all four corners of the printer. No leadscrews, linear rails or rods are used which enhanced the noise reduction witout compromising print quality. 
Gathering in my personal opinion the best solutions to get a silent and stable as possible printer with high print quality at a reasonable DIY price level. Also easy for regular maintenance or troubleshooting. 
 
234 in the D-workx CORE XYZ 234 name is the reference to a 200, 300 and 400 mm print volume area in the XY directions. So we are not talking about a fixed design but highly adaptable to your own needs. With the standard 500 x 500 x 500 mm V-slot profiles and 20 mm corner cubes a maximum 400 x 400 mm horizontal print area can be achieved. 

If you reduce all horizontal V-slot profiles with 100 mm base length you get the next step maximum print volume area in X and Y direction. 
500 mm V-slot profiles > maximum 400 mm horizontal print area.
400 mm V-slot profiles > maximum 300 mm horizontal print area.
300 mm V-slot profiles > maximum 200 mm horizontal print area. 
The X-carriage will always reduce the XY print size with 100mm from any chosen length. 
The maximum height of Z is 385 mm. But it is up to your choice if you make the maximum Z build size lower or higher. So you can make a 200 x 200 x 385 mm or 400 x 400 x 200 mm print volume. We also try to reduce the weight of the printhead unit by using a short bowden setup. We have not tried higher volumes as we do think they are not needed for 99% of the 3D printers in use. 

The difference............4 corner lifting. The Z system is a 4 corner lifting system. It is based on a coupled dual (left, right, front and rear) belt/idler drive system (closed loop with push/pull) with two separate stepper motors and 1:40 brass worm gear reductions. This system ensures a smooth up and down step with 1.8 degree stepper motors even with smaller NEMA 17 stepper motors as the load is divided over two motors. 

Worm gears also prevent the bed to go down on its own weigth when the Z steppers are de-energized. 
As the Z belt system is directly located in the 4 corners of the profile cube there is no fear of the profiles being bent/distorted under Z belt pressure. Also the belts are not in the way when access to the build plate is needed from the front. 

6 mm GT2 belts are used and sufficient for a maximum build size of 500 x 500 x 500 mm. XY and Z belts tension can be adjusted independed and easily with a hex screw driver. 


 
For those who want to print (enclosed and draft free) for example ABS, the printer is designed with a flush profile outside. All parts are inside the vertical V-slot profile cube sides. This means covering panels like wood, foam, polycarbonate, plexiglass or even cheap cardboard can be attached in rectangled sizes without the need of any post cut outs.

STL
All parts can be printed for best result as oriented in the STL files. I have taken care that supports are very simple to remove or as less as possible. If you feel other orientation is better please do so and adapt your supports. STL filename explanation: NS= No support BS= Bed support only FS= Full support

Filament choices
If you need the printer for printing regular PLA prints you can print all parts in PLA. If you need the printer for printing PETG and ABS prints you better opt to print the parts in PETG or ABS from the start.PETG is sufficient. PLA parts on heat stressed places can be swapped afterwards for PETG or ABS parts when a PLA printer is running fine. In general if you print all parts in PETG your good to go. Our prototype is fully printed in PLA and with a maximum heat bed temp of 65 degrees Celsius and XYZ motors that barely get warm there is no need for other filament choices. The parts to be printed are not under severe mechanical stress so only heat is a thing to take care of. 25% infill is enough for all parts used. I used REAL filaments PLA.
https://cdn.thingiverse.com/assets/9a/78/26/fe/6c/real_filament.JPG


Slicer
I used Ideamaker version 3.5.1 Beta from 13 December 2019 as slicer. Slicer profiles are included in the Thingiverse download. Download link for Raise 3D Ideamaker https://www.raise3d.com/download/

Firmware Marlin
Marlin 2.0 http://marlinfw.org/meta/download/ Marlin 2.0 firmware download is used for the SKR V1.4 Turbo XY TMC2209 ZE LV8729 with ANTCSLABS BL-Touch V2.0 bedleveling.

Firmware Klipper
Klipper https://www.klipper3d.org/?fbclid=IwAR2Xs89hibwmlvQmLw1_Okc9E5MRss-Y1GQ027LGihiaJBT2jU6R4sbGTbg We will install Klipper in a later stage.

V-slot profiles
20x20mm only V-slot profiles used in this printer. The use of T-slot profiles is not advised for a long lasting printer but it COULD work. Ratrig.com starter kit with some extra profiles for the bed frame and extruder bridge. https://www.ratrig.com/aluminium-profiles/starter-kit-1.html The starter kit from ww.ratrig.com by standard has M5 thread tapping at each end of the profiles. If you need other size of the profiles for the cube you can add the option to add M5 tapping for 50 Euro cent per profile. I advise you to do so if you do not have tapping tools.


Cube corners
The cube is build with the kit provided black aluminium cube corners and the use of M5 x 8 mm countersunk hexagon screws.This ensures a square and very strong cube without the need for special alignment tools. Aluminium 2028 corner brackets can be installed for additional strenght at a few spots if you think it is not enough. Do not use the kit supplied M5 x 8 mm flathead hexagon screws for the corner cubes!


Z motors
Each Z belt axle is driven by a NEMA17 38 Nm motor. One in the front and one in the rear. Worm gear drive 1:40 reduction with 5mm drive axle running in 10x5x4 mm ball bearings. Left and right are coupled with a 5mm steel axle with a length of 498 mm. The 500 mm length axle need to be shortened with a high speed cutting tool with 2 mm for fittng in-between the profiles.


XY idler brackets
XY idler brackets incorporate independed belt tension adjusting for X and Y belt.


Z belt tensioners
Easy Z belt independed adjustment at each side. This part has been redesigned and is part of the download as D-workx Z belt tensioner 2x - NS. If needed ans belt slippage through the tensioners a M3 screw/nut combination can prevent this.


Enclosure
The printer can be enclosed at the sides and rear easily with different material options. Think about polycarbonate, wood, foam or even cardboard panels/plates in rectangle sizes. By standard panel clamp parts for 3mm thick panel material are included. The panels can slide in from the top of the printer easily without using tools so you have a quick and easy access when maintenance on the inside of the printer might be needed.


Heater
We designed the printer to be used with E3D V6 (or clone) heater units. The maximum Z height with this standard 500 mm configuration is 385 mm. If you like to mount other heaters like a E3D Vulcano (or clone) Z height Is reduced. We currently as test use the machine with a BP6 HEXAGON print head which gives 18 mm less Z heigth.


Aircooling
We use a standard 30x10 mm axial low noise ball bearing fan for the heater body cooling. This is sufficient to prevent filament clog due to heat creep with PTFE equipped heat breaks. If you use other types of heat breaks a step up to a 40 x 10 mm axial fan might be a better solution. For the layer fan cooling we use two 30 x 10 mm @ 90 degrees angled radial ball bearing fans. if you set up and dial in your printer correctly layer fan cooling is not needed or only in extreme cases of very long and wide overhangs. In the latest design the printlayer duct is a 3 part design which gives more flexibility.


Belts
We use standard GT2 6 mm belts. Nothing special. Steel core wire equipped belts are not advised due to reduced life cycle of this type of belts due to the small GT2 core diameter of the idler and drive pulleys.


Idler pulleys
By standard 3 mm ball bearing idler pulleys over 5mm versions are used for a reason. First of all 3 mm screws as a rotation point is strong enough in the size of these kinds of printers we use. It gives less material reduction on mechanical stressed parts. The pressed in ball bearings in the idlers are less prone to tolerance issues compared to 5 mm versions as the size of the balls In the 3 mm bearings are larger compared to the 3 mm versions . Don’t ask how I know this 😉 We use 20T (toothed) and 0T (smooth) versions in our build.


Heatbed
Heatbed used is 24 volt 400W - 300 x 300 mm size but actually 328 x 328 mm. 3mm thick aluminium. On top of this heatbed is a regular glass plate of 3 mm thickness from a local glass store. Glass plate edges are sanded to prevent cuttting your hands.


Mini wheels
The printer runs on “Open Builds” design mini wheels. They perform the same as the more known larger size version but take less size in a printer design like this, where you want to maximize build print sizes. The wheels are fixed to the printer parts with countersunk M5 x 30 mm hexagon screws. A small 5 x 7 x 1 mm shim washer is in-between the bearing and the printed part. For the X carrier we purchased a complete mini wheel set and used our own printed X carrier bracket with the parts.


Z axles
The GT2 6 mm Z belt is driven by two 498 x 5 mm steel axles, one at the front and one at the rear of the printer. This axle runs on 10 x 5 x 4 mm ball bearings.

Z bracket
The Z brackets are attached to the bed frame V-slot profiles and are equipped with a single mini wheel and run at the inside of the vertical V-slot profiles. The Z belts are also connected to this Z bracket. The mini wheel use a small 5 x 8 x 1 mm shim washer and a 5 x 10 x 1 mm washer in-between the bearing and the Z bracket. The Z belt routing is a single GT2- 6mm belt connecting the front and rear drive axle to keep all in sync and level.


E motor bridge
3 V-slot profiles make a bridge from front to rear of the printer and contains the NEMA 17 40 Nm extruder motor with dual gear (BMG) extruder unit. This bridge makes it possible to use a shorter bowden tube over the full width of the print bed size. The Bowden length is 40 cm. Also the filament spool holder is attached to the rear V-slot profile. The spoolholder can be mounted horizontal too.


X carrier
The X carrier uses the hardware from a Mini V-slot wheel base plate.


Display
To control the printer by display we use the FYSETC MINIPANEL 12864. We use this panel only for adjusting BABYSTEPS in Marlin firmware if a bedleveling device like a BL-touch is used. In all other situations we use OCTOPRINT https://octoprint.org/ and Printoid https://printoid.net/ to control the printer.


Power supply
A 24 volt 25 Ampere 600W power suply to power the whole printer is used.


Stepper motors
Nema17 Sepper motor 42mm 1.5A / 38 Nm 17HS4401 Motor


Controller board
The printer is equipped with a Big Tree Tech BIQU SKR V1.4 Turbo 32 bits controller board. Stepper drivers used: X = BTT TMC2209 UART Vref 800 mA - Stallguard activated - Stealthchop Y = BTT TMC2209 UART Vref 800 mA - Stallguard activated - Stealthchop Z1 = BTT LV8729 Vref 700 mV Z2 = BTT LV8729 Vref 700 mV E = BTT TMC2208 UART Vref 800 mV - Spreadcycle


Remix
Following parts are used as they are or partly remixed. Customisable T-Slot or V-Slot Rail Cover (DDevine_au) https://www.thingiverse.com/thing:2034738 Bedlevel parts (V-baby by 3D-Pro Roy Berntsen) https://www.thingiverse.com/thing:3863246 Spoolholder(CreativeTools) https://www.thingiverse.com/thing:508896

Optional parts
Z belt tension measuremnt with a load cell XY belt tension measurement with a load cell Raspberry Pi3B with Octoprint Printoid

Building tools
Drill bits 3-4-5-7 mm Cordless drill Ball tip hexagon screw drivers 2.5-3 mm Hexagon tip screw drivers 1.5-2 mm 8 mm wrench Plyers Break-off knife Wire cutter Wire stripper Wire connector crimptools Soldering iron Soldering wire

Documents
BOM = Bill Of Materials http://www.jupacreations.com/d-workx/d-workx234/bom/D-workx_234_BOM_18-1-2020.xlsx profile size calculator http://www.jupacreations.com/d-workx/d-workx234/bom/D-work_profile_size_calculator.xlsx

Change log
24-4-2020 removed D-workx_Z_belt_retainer_3x_-_NS.stl 
24-4-2020 added D-workx Z brace cover 4x - NS.stl 
24-4-2020 added D-workx Z brace cover + switch 1x -BS.stl 
12-4-2020 reworked and updated D-workx XY idler bracket top 2x - FS.stl 
12-4-2020 reworked and updated D-workx XY idler bracket 2x - FS.stl 
12-4-2020 added missing D-workx Z worm gear drive 2x - NS.stl 
30-3-2020 reworked and uploaded D-workx Z belt tensioner 2x - NS.stl 
30-1-2020 reworked and uploaded D-workx XY bushing idler 4x - NS.stl 
30-1-2020 reworked and uploaded D-workx XY idler bracket 2x - FS.stl 
30-1-2020 reworked and uploaded D-workx Z drive pulley bracket 2x - NS.stl 
30-1-2020 reworked and uploaded D-workx Z idler brackets 2x - NS.stl 
20-1-2020 Added D-workx XY bushing idler 4x - NS.stl 
19-1-2020 Added http://www.jupacreations.com/d-workx/d-workx234/bom/D-work_profile_size_calculator.xlsx 
18-1-2020 reworked and uploaded D-workx cable bracket 1x - NS.stl 
18-1-2020 reworked and uploaded D-workx X upper bracket 1x - NS.stl 
18-1-2020 added BOM D-workx_234_BOM_18-1-2020.xlsx 
16-1-2020 reworked and uploaded D-works XY idler bracket right - 1x - FS.stl 
16-1-2020 reworked and uploaded D-works XY idler bracket left - 1x - FS.stl 
14-1-2020 reworked and uploaded D-workx Z idler brackets 2x - NS.stl 
12-1-2020 Added D-work electronics base plate 1x - NS.stl 
12-1-2020 Added D-workx display 12864 fysetc 1x - NS.stl 
9-1-2020 Changed D-workx_XY_idler_bracket_2x_-_FS.stl to use 3 mm instead of 4 mm screw. 
9-1-2020 Changed D-workx_XY_idler_bracket_top_2x_-_FS.stl to use 3 mm instead of 4 mm screw. 
8-1-2020 Added stl files



# Module 2

We will make a basic electric circuit. Q: do you know what is an electric circuit? Components: power source, conductive path, load. NB! please do not short your circuits.

The stuff we will use: jumper wires, breadboard, resistor, button, LED
A more details on the internals of the breadboard - between the red and blue lines it is vertical along the long axis of the breadboard (this is for the positive and the ground), and the middle parts are transverse along the long axis, with the two halves being split. If the line is not continuous (the holes have a break between them).

How do LEDs work? The D stands for diode - meaning that current travels only in one direction (look at the circuit symbol, the triangle indicates the direction.
We need a current limiting resistor to protect the resistor, as w/o the resistor the LED overdraws current/power - it will get very bright for a short time, either stops working, splits into two, and sometimes even shoots out a tiny flame (the guys do NOT encourage
The Ohm's law can say what resistor you need, but usually better to use bigger ones (200-300 ohm) If you use even 1 kOhm, still fine, but with 10 kOhm the LED might be a bit dim.
So for instance we would be doing R = (V_supply - V_LED) / I_LED. So an example is

## Task 1

This task was executed by myself. The question task:
**What is an electric circuit (what are the basic properties)?** - a closed, continuous current consisting of a power source, conductive path, and a load
**What is a breadboard for electronic prototyping?** - a convenient tool for connecting (jumper) cables, with holes, and inside there being metal bars running vertical (ground and positive) and transverse (the stuff) to the horizontal axis
**Describe a breadboard - include at least 2 remarkable/memorable features** - nowadays it is white, used to be literally a breadboard (from wood), also other details see previous
**Name one (or two) convention(s) for color coding for cables.** - ground is black (or brown), positive is red. The other color coding I don't really know.
**How do you wire a Light Emitting Diode (LED) to 5V?** - make sure that you connect the correct direction (anode/shorter wire connected to positive), and must have a resistor (caluclate Ohm's law as above, so about 200-300 ohms)
**Describe an LED** - light-emitting diode, has two metal wires from a transparent container. The shorter wire is the anode, the longer is the cathode.
**What is special about (light-emitting) diodes?** - has to be in the single direction
**One thing that seemed unclear (or something very important)** - what differentiates LED from just a regular lightbulb?


## Task 2
This task was executed by me and my partner. The task was to collect the hardware for our next tasks.
We collected:
- 1 blue bag
- 2 long breadboard
- 2 USB-microUSB cable
- ~20 female-to-female jumper cables
- ~30 male-to-female jumper cables
- ~15 male-to-male jumper cables
- 1 12V 1.0A adapter
- 1 Y-cable
- 4 LEDs
- 9 resistors
- 6 buttons
- 2 Wemos D1 Mini
- Dallas temp sensor
- gesture sensor
- touch sensor
- dht22
- rfid + receiver
- solenoid lock
- relay

We are missing:
- 1 medium sized breadboard
- 1 multimeter

A picture of our bag
It is [here](https://github.com/partner/iot-portfolio/Module02/Readme.md#task-2).

## Reflection 2
[Reflection 2](/Reflections/ref02.md)

## Task 3
In task 3 we are building the "Hello World" of electronic prototyping - making the microcontroller's in-built LED blink, making an LED on a breadboard blink, and then tuning their blinking ordering.
The very first thing was getting the proper board on the Arduino IDE, which at first I struggled with since I was going a roundabout way (some nonsense cloning a git repo into the Arduino sketches folder). However, the proper way to do this was to go File -> Preferences -> Additional boards managers URLs: https://arduino.esp8266.com/stable/package_esp8266com_index.json. These instructions can be found [here](https://github.com/esp8266/Arduino?tab=readme-ov-file#installing-with-boards-manager).


## Task 8
PWMRANGE is 0 to 1023



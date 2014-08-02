Padawan360
====

Still to come, full set up instructions.


## Intro
This is a control system for 1:1 scale remote control R2-D2 powered by Arduinos and controlled with an Xbox 360 Controller. It triggers lights, sounds, and controls foot drive and dome drive motors. It also supports I2C to trigger events in the dome lights or can be extended to interact with anything else that supports I2C

These sketches are heavily based on DanF's Padawan control system that uses Playstation 2 controllers. I found the PS2 controllers to become a bit unreliable and they are increasingly more difficult to come by.

I developed Padawan360 (named with permission from DanF) to use some more easily accessible components with no soldering, wire stripping, etc. It's a bit more plug and play.

A lot of the instructions here are relevant to the original [Padawan PS2](http://astromech.net/droidwiki/index.php?title=PADAWAN) setup instructions. A good chunk of the documentation is reproduced here.

## Components

- ### Arduino Uno
	For the body. Main Arduino that runs everything. Receivers, code, connection to MP3 trigger, etc runs through here. SparkFun, RadioShack, Amazon, you can find these everywhere these days.

- ### USB Shield
	Sourced from [Circuits@Home](http://www.circuitsathome.com). It comes in two variants, one without shield headers soldered, and one without them soldered. Difference in $5.

	[Assembled USB Shield](https://www.circuitsathome.com/products-page/arduino-shields/usb-host-shield-2-0-for-arduino-assembled) $30

	[Unassebled USB Shield](https://www.circuitsathome.com/products-page/arduino-shields/usb-host-shield-2-0-for-arduino) $25

- ### Xbox 360 Wireless USB Receiver
	You can probably source this from Best Buy or something local but it's available on [NewEgg here](http://www.newegg.com/Product/Product.aspx?Item=0NS-000Z-00003)
	I bought a generic one from Microcenter that works fine.

- ### Xbox 360 Wireless Controller
	[Controller via Amazon](http://www.amazon.com/Xbox-360-Wireless-Controller-Glossy-Black/dp/B003ZSP0WW).  I have a nice blue one to match R2 personally ;)

	**Note:** I have seen the controller bundled with the USB receiver together. It was in the gaming peripheals department in my local Microcenter. It's marketed for PC gaming. It's the same stuff though. Nice to get it in one package if you can if you don't have an extra 360 controller to spare.

- ### MP3 Trigger
	[Sourced from SparkFun](https://www.sparkfun.com/products/11029). Be sure to get a microSD card too. Nothing too big, it's just MP3s.

- ### Sabertooth Motor Controller - Feet
	Depending on your motors you'll want a [Sabertooth 2x25](https://www.dimensionengineering.com/products/sabertooth2x25) or [2x12](https://www.dimensionengineering.com/products/sabertooth2x12). My styrene droid with Jaycar motors uses 2x12. Most people tend to use 2x25 for scooter motors and NPC motors. Consult with Dimension Engineering to make sure you get the right one you need.	 Either one will work with the code

- ### Syren Motor Controller - Dome
	[Syren 10](https://www.dimensionengineering.com/products/syren10)

- ### Amp and Speakers
	Up to you and how big and loud you want. I have a small speaker and a $20 amp from Pyle. A ground loop isolator might be necessary to protect the MP3 trigger and eliminate buzzing from the speaker.

- ### Slipring
  Used to pass power up from the body to the dome and also signa for I2C.

- ### Teeces lights
	The sketch provided here will work for version 3. Use the regular setup and installation instructions but include pinouts for pins A4 and A5 if you want I2C control.

- #### Optional
	- ##### RSeries RGB HPs.
	Sketches provided are for I2C holoprojector boards. The front uses the one with the servo pinouts although the sketch doesn't servo control of the HPs. The top and rear HP are just the regular I2C controlled boards.

## Setup

### USB Shield

Solder the headers on the USB Shield if you purchased the unassembled version. Fit the shield over the Arduino UNO by lining up the pins and pushing in. It should fit snugly. Plug the Xbox 360 Wireless Receiver USB cable into the USB port. That was easy.


### Sound

Connect the following pins from the MP3 Trigger to the Body Arduino

|MP3 Trigger Pin   |Arduino UNO   |
|---|---|
| RX  |1   |
| USBVCC  |5v   |
| GND  |GND   |

**There is a small switch at the bottom of the board labled USB - EXT, make sure that it is pointing to the USB side in order to power it via the Arduino**

In order to load the sounds onto the MP3 Trigger, you will need to grab the sounds files either from [here](http://host-a.net/u/DanF/Padawan_R2_sounds.zip) or [here](http://www.tjcomputers.us/padawan/Padawan_R2_sounds.zip)

Connect the Micro SD card to your computer and upload the files one by one in the numbered order. If you don't do this, you will not be able to control which sound files are triggered. It's picky about file names and ordering. It's annoying but really, do transfer them over one file at a time.

Now, insert it into the MP3 Trigger and hook up either the Ground Loop Isolator / Amp / Speaker using the 3.5mm jack on the board.

For anyone with an older version of the MP3Trigger board, you may need to upgrade your firmware before you can use the Arduino to trigger sounds. If your board has the date 3-1-10 on the back (and possibly others) you have the retired version WIG-09715. You can use the board, but it's likely that you'll need updated firmware.

1. Download and unzip the the firmware file available [here](http://astromech.net/droidwiki/images/8/8f/MP3TRIGR.zip).
2. Copy the resulting hex file to a microSD card and rename it to: “MP3TRIGR.HEX”. It does not need to be the only file on the card – it just needs to have that precise filename.
3. Insert the microSD card into your MP3 Trigger and turn the power on while holding down the center navigation switch. Wait for the Status LED to go solid, then cycle the power.
4. You’re now running the new firmware.


### Dome
Connect the pins for the Syren Motor Controller

|Syren10   |Arduino UNO   |
|---|---|
| S1  |5   |
| 0v  |GND   |

|Syren10   |Battery   |
|---|---|
| B+  |Positve   |
| B-  |Negative   |

|Syren10   |Dome Motor   |
|---|---|
| M1  |1 (Positve)   |
| M2  |2 (Negative)   |

If you find that the dome spins the opposite direction, flip M1 and M2. When standing behind the droid, moving left on the left analog stick should rotate the dome left.

If using a Syren speed controller for the dome, you will have choose what type of serial connection to use.
Packetized is the best choice for the Syren, but you might need to change the baud rate . This is done by changing the value of int domeBaudeRate at the beginning of the sketch. All supported rates are listed there.
If you can't get packetized to work, (and some people have had problems) you will have 2 options

#### Option 1
Simplified serial- easy to setup, proven to work, BUT a chance that the dome could start spinning if power is lost to the arduino but not the syren. While I haven't seen this happen without physically yanking the power wire or pressing the reset button the risk is there. I would say now that we know of this possibility, do not use this option if people, especially children, will be close enough to the droid to be injured. To use simplified serial, delete the // in front of the line #define SYRENSIMPLE at the beginning of the sketch.

#### Option 2 (Best Option)
Send the syren to Dimension Engineering to be flashed with the Ver. 2 firmware- This allows the syren to be locked in to a set baud rate and eliminates the auto-bauding problem. I have had this done to my own syren and have tested it with several types of arduinos with no problems. All new syrens are being shipped with this new firmware.

The dip switches on the Syren should be set to 1 and 2 off for Packetized, or 2 and 4 off for Simple.

In some cases, we've noticed that the dome may behave eratically after starting up. If this is the case plugging a 10k resister between the S1 and 0V screw terminals. Simply bend the pins and screw them in along with the wires.

Make sure that you use at least a 14 Guage wire between the motor and the Syren 10. Anything hire can cause problems (fire!)


### Foot Drive

|Sabertooth (2x25 or 2x12)   |Arduino UNO   |
|---|---|
| S1  |7   |
| S2  |6   |
| 0v  |GND   |

|Sabertooth (2x25 or 2x12)   |Battery   |
|---|---|
| B+  |Positve   |
| B-  |Negative   |

|Sabertooth (2x25 or 2x12)   |Foot Motors   |
|---|---|
| M1A	  |Right Motor Terminal 1   |
| M1B	  |Right Motor Terminal 2   |
| M2A  |Left Motor Terminal 1  |
| M2B  |Left Motor Terminal 2  |

People often seem to get stuck here once they power everything up and find that they push forward on the stick and it drives to left, stick to the left drives drives backwards, etc. Don't fret, motors can be wired positive/negative. It doesn't matter. Start flipping the motor connections to the Sabertooth. First flip  M1A and M1B. If that doesn't fix it, flip it back and try the other. If it still isn't right, then try flipping both sets. R2 is driven like a tank. Spin the right motor forward to go left, left motor forward to go right. Both motors forward, drive forward. Keep that in mind as you troubleshoot.


Please use a maximum of 12 Gauge for the wires going to the Sabertooth and motors/power.


Sabertooth 2x25 / 2x12 dip switches should 1 & 2 OFF and all others ON if using a regular SLA battery

If you're using 5v to power some components on your I2C device chain, you can use the 5V terminal on the Sabertooth and connect to the positive I2C pin header on the slipring board and 0V on the Sabertooth to GND on the slipring board.

**Note:** If you're using Lithium-Ion batteries (you oddball!) set switch #3 off also.


### Arduino UNO 
Upload the padawan360_body sketch to the UNO.


####I2C
This is optional. If you want to trigger light effects in the dome via slipring, connect A4 SLC to SLC on the slipring board and A5 SDA on the Arduino to SDA on the slipring board.

Arduino UNO R3 has separate I2C pins which is really nice but the Circuits@Home USB Shield covers them up. The R3 Board still has I2C pins at A4 and A5.


### Controller Pairing
Power the Arduino up. It will also power up the Receiver.  Press the big button on the receiver, it will blink. Press the center Guide button the controller to turn the controller too. It will blibk. Press the little sync button located on the top edge of the controller. The controller blink too, then they should sync up and the blinking pattern on the controller will change and swirl. This indicates a connection and that they are paired.

There's also the [Xbox Support Guide](http://support.xbox.com/en-US/xbox-on-other-devices/connections/xbox-360-wireless-gaming-receiver-windows).

### Teeces Logics

Upload the padawan360_dome sketch on the Teeces arduino. Connect I2C on the dome end of slipring board. SDA to A4 and SLC to A5.

### HoloProjectors I2C

Mike Erwin put out some great boards with Arduino bootloaders on them. Programmable! I wasn't personally thrilled with some of the lighting effects. I thought some of the colored lights didn't look too authentic. Certainly not entirely fil accurate, but that's ok. Some colored lights didn't really seem to fit random idling and blinking. Using an ISP programmer I tweaked the events more to my liking. Alarms flash yellow and red, otherwise everything else is just white or a cyan color for the Leia message. If you don't want to program them with my versions, you can tweak the `triggerI2C()` function calls in the body sketch to match the original event numbers. The originals are found on the RSeries code repo on google code.

## Controls

Controller guide coming soon. 

## Coming Soon

Dome servos via I2C support.
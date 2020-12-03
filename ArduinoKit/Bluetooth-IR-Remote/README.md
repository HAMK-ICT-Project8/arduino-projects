# Connect Arduino to Unreal via Bluetooth and handle IR signals

In this project it is demonstrated how to connnect the arduino to the unreal engine via the bluetooth-port and handle IR Signals on the arduino board.


Requirements:
- Arduino UNO
- Sparksfun Bluetooth-Shield
- IR Receiver and IR Remote
- Connection Cables and Breadboard
- Unreal Engine (v 4.25)
- Arduino Kit Plugin (https://github.com/HAMK-ICT-Project8/ArduinoKit)

Tested on:
 - Mac OS ✅

## Setup

### Arduino

#### Hardware

1. Download the IR Library from https://github.com/z3t0/Arduino-IRremote/archive/master.zip and add it to your Arduino Library folder.
2. Setup the IR Receiver module on the arduino according to this image: https://image.dfrobot.com/image//Blog/Arduino%2014/Fig.%2014-1%20IR%20Receiver%20Diagram.png (in depth guide you can find here: https://www.dfrobot.com/blog-648.html)
3. Setup the bluetooth module according to this image: https://cdn.sparkfun.com/assets/0/c/d/3/a/521bceb9757b7f63278b4567.png (in depth guide you can find here: https://learn.sparkfun.com/tutorials/using-the-bluesmirf?_ga=2.13681651.518416888.1604914763-1339665885.1604914763)
4. Download the code from this repository and flash it on the arduino
5. Try to connect to it via your devices bluetooth menu.
6. Once connected, you need to find the port-name assigned to it and remember it / write it down / copy it.

#### Find bluetooth portname on Mac OS
Open up a terminal an type in `cd /dev` and then run `ls` and in this list you should find something starting with `tty.` and then something relatable to bluetooth/arduino.

7. There should now be a consistent yellow led on the bluetooth module.

### Unreal Engine
As the bluetooth connection is also handled via the communication ports the same way the usb ports are handled, you can just paste the bluetooth port-name from the arduino setup in the connection blueprint component.

In the screenshot provided it also handles the input received via the communication port and branches according to it.

### Caveat
Because the bluetooth.send method adds a linebreak character at the end of every message, it must be stripped before checking the received string in unreal engine.
This is done with the "left chop" component in the screenshot.

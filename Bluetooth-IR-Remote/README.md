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
Flash the arduino script provided in this repository on the arduino board and then try to connect to it via your devices bluetooth menu.
Once connected, you need to find the port-name assigned to it and remember it / write it down / copy it.
There should now be a consistent yellow led on the bluetooth module.

### Unreal Engine
As the bluetooth connection is also handled via the communication ports the same way the usb ports are handled, you can just paste the bluetooth port-name from the arduino setup in the connection blueprint component.

In the screenshot provided it also handles the input received via the communication port and branches according to it.

#### Caveat
Because the bluetooth.send method adds a linebreak character at the end of every message, it must be stripped before checking the received string in unreal engine.
This is done with the "left chop" component in the screenshot.

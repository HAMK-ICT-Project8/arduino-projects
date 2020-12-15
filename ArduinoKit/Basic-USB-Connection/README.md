# Connect Arduino to Unreal via Bluetooth and handle IR signals

In this project it is demonstrated how to connnect the arduino to the unreal engine via the usb port and send signals back and forth.


Requirements:
- Arduino UNO
- Unreal Engine (v 4.25)
- Arduino Kit Plugin (https://github.com/HAMK-ICT-Project8/ArduinoKit)
- LED for the Arduino
- Button for the Arduino
- Breadboard and connection cables

Tested on:
 - Mac OS ✅

## Setup

### Arduino

#### Hardware
1. Connect the LED to port 13 and the Button to Port 2 on the Arduino board

`if you use different ports, remember to update them in the code provided`

#### Software
1. Download the code from this repository and make sure to set the correct pins flash it on the arduino.
2. Look up the port name assigned to your arduino board.

### Unreal Engine
1. Download the ArduinoKit plugin from here: https://github.com/HAMK-ICT-Project8/ArduinoKit and follow its instructions.
2. Open the blueprint edit menu and set it up as shown in the screenshot.
3. Run it

## Usage
Press the 1-key on your computer to turn on the light and the 0-key to turn it off again.
You should see a message from the arduino board in-game every time you push the button.
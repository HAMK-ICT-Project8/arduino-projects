# TCP Plugin simple connection
This project connects the arduino board with the sparksfun wifi shield as a tcp server to the unreal engine using the tcp-plugin.

Requirements:
- Arduino UNO
- Sparksfun wifi shield
- Unreal engine (v 4.25)
- TCP Plugin

Tested on:
- Mac OS ✅

## Setup

### Arduino
Edit the wifi.ino to set the wifi credentials for your wifi on line 36 and 37 and then flash it on the arduino.
Open the serial monitor and follow the instructions to start the tcp server.

### Unreal engine
Create a new asset in the content manager and select blueprint class and search then for tcp (see screenshots). Add the newly created component to the scene and then edit its blueprint by double-clicking the component according to the screenshot. you should then see the html code sent from the arduino-tcp-server printed as a string.

## Caveat
The school network prevents setting up tcp servers, so there is no chance for that to work in the HAMKVisitor or Eduroam networks.

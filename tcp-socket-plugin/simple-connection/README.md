# TCP-Socket Plugin simple connection
This project connects the arduino board with the sparksfun wifi shield as a tcp server to the unreal engine using the tcp-plugin. The unreal engine project will connect to the tcp server using the TCP-Socket Plugin and will send a request to the server running on the arduino board which then will respond with a simple message and then close the connection.

## Dependencies
### Hardware
* Arduino UNO
* Sparkfun ESP8266 WiFi shield

### Software

#### Unreal Engine
* TCP Plugin from unreal engine marketplace

#### Arduino Uno
* [Arduino IDE](https://www.arduino.cc/en/software)

#### Sparkfun ESP8266 WiFi shield
* [Library and instructions for Sparkfun ESP8266 WiFi shield](https://learn.sparkfun.com/tutorials/esp8266-wifi-shield-hookup-guide?_ga=2.232777183.154801248.1606463257-1158639612.1605182896#installing-the-esp8266-at-library)

## Setup

### Arduino

#### Hardware
1. Attach WiFi shield in top of Arduino board

#### ARDUINO IDE
1. Download library for [Sparkfun ESP8266 WiFi shield](https://learn.sparkfun.com/tutorials/esp8266-wifi-shield-hookup-guide?_ga=2.232777183.154801248.1606463257-1158639612.1605182896#installing-the-esp8266-at-library)
2. Add Sparkfun library to Arduino directory `<Path to your arduino folder>\Arduino\libraries`
3. Open [code](https://github.com/HAMK-ICT-Project8/arduino-projects/blob/main/tcp-socket-plugin/simple-connection/tcp-server.ino) in Adruino IDE
4. Replace network settings to match yours: values of mySSID[] & myPSK[]
4. Plugin USB cable and upload the code
5. Start serial monitor
6. If your network settings are correct server should start automatically
7. Notify IP address that is shown, you need to apply it later to blueprint node

### Unreal engine
1. Download the TCP-Socket Plugin from the unreal engine marketplace. https://www.unrealengine.com/marketplace/en-US/product/tcp-socket-plugin#
2. Create a new project and start it.
3. Open Unreal Engine and enable plugin `Edit/Plugins` and restart Unreal Engine
4. Create a new asset in the content manager and select blueprint class and search then for tcp (see screenshots).
5. Add the newly created component to the scene
6. Then edit its blueprint by double-clicking the component according to the screenshot.
7. Make sure to replace the IP Address to match the previously noted IP Address from the arduino server.
8. Run it
9. You should then see the html code sent from the arduino-tcp-server printed as a string.

## Caveat
The school network prevents setting up tcp servers, so there is no chance for that to work in the HAMKVisitor or Eduroam networks.

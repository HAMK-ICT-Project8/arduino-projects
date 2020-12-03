# 2-way connection between Unreal Engine and Arduino
Documentation is for Arduino <-> Unreal Engine project.

This is a proof of concept of communication between Arduino and Unreal Engine. In this demo, a Pushbutton and a LED is connected to a Arduinos GPIO interface. You can turn LED on and off by pressing 1 and 0 within Unreal Engine. You can print '2' and '3' into Unreal Engine by pressing and releasing Pushbutton in Arduino.

Data transfer between Arduino and computer is made via USB cable. To do this, a plugin for COM communication is needed. This demo uses [UE4Duino 2.2.5 plugin](https://github.com/RVillani/UE4Duino) and [Unreal Engine 4.25.4](https://www.unrealengine.com/en-US/)

## Table of contents
* [Dependencies](#dependencies)
* [Installation](#installation)
* [Usage](#usage)

## Dependencies

### Hardware
* Pushbutton
* 5mm LED
* Resistor
* Jumper cables x 6
* Breadboard

### Software

#### Unreal Engine
* [UE4Duino Plugin](https://github.com/RVillani/UE4Duino)

#### Arduino Uno
* [Arduino IDE](https://www.arduino.cc/en/software)

## Installation

### Arduino

#### Hardware
1. Connect Pushbutton and LED to breadboard using jumper cables.
2. Connect breadboard to Arduino using jumper cables.  Pushbutton is connected to pin 2 in Arduino, and LED in pin 4.

#### ARDUINO IDE
1. Open UE4Connect.ino in Adruino IDE
2. Check the port to match your Arduino connection port.
3. Plugin Arduino via USB cable and upload the code


### Unreal Engine
1. Download UE4Duino Plugin from [Github]((https://github.com/RVillani/UE4Duino))
2. Start a new project in Unreal Engine
3. Create a folder named "Plugins" in the project directory and add UE4Duino plugin folder there
4. Open Unreal Engine and enable plugin `Edit/Plugins` and restart Unreal Engine
5. Add FirstPersonExampleMap_BuiltData.uasset and FirstPersonExampleMap.umap to `<your project>\Content`
6. Open level blueprint. Change Serial port number to match your Arduino connection port.

## Usage

1. Start Unreal Engine game level.
2. Use keyboard numbers 1 and 0 to turn LED on and off.
3. Use Pushbutton to send data to Unreal Engine.
4. Values of keyboard and pushbutton presses are printed in the screen.

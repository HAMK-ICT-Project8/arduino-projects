# 2-way connection between Unreal Engine and Arduino
Documentation is for Arduino <-> Unreal Engine project.

This is a proof of concept of communication between Arduino and Unreal Engine. In this demo, a Pushbutton and a LED is connected to a Arduinos GPIO interface. You can turn LED on and off by pressing 1 and 0 within Unreal Engine. You can print 'ArduinoButton pressed' and 'ArduinoButton released' into Unreal Engine by pressing and releasing Pushbutton in Arduino.

Data transfer between Arduino and computer is made via USB cable. To do this, a plugin for COM communication is needed. This demo uses [Cluster Communication Port plugin](https://www.unrealengine.com/marketplace/en-US/product/cluster-communication-port) and [Unreal Engine 4.25.4](https://www.unrealengine.com/en-US/)

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
* [Cluster Communication Port plugin](https://www.unrealengine.com/marketplace/en-US/product/cluster-communication-port)

#### Arduino Uno
* [Arduino IDE](https://www.arduino.cc/en/software)

## Installation

### Arduino

#### Hardware
1. Connect Pushbutton and LED to breadboard using jumper cables. 
2. Connect breadboard to Arduino using jumper cables. Connect Pushbutton to pin 2 in Arduino, and LED pin 4.

#### ARDUINO IDE
1. Open UE4Connect.ino in Adruino IDE
2. Check the port to match your Arduino connection port.
3. Plugin Arduino via USB cable and upload the code


### Unreal Engine
1. Create a Game project with blank template in Unreal Engine
2. Open Unreal Engine and enable plugin `Edit/Plugins` and restart Unreal Engine
5. Add ClusterCommunication.uasset to `<your project>\Content\Blueprints`
6. Add ClusterCommunication class into your game world.

## Usage

1. Start Unreal Engine game level.
2. Use keyboard numbers 1 and 0 to turn LED on and off.
3. Use Pushbutton to send data to Unreal Engine.
4. Values of keyboard and pushbutton presses are printed in the screen.

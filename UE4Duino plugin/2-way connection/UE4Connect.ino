/*
  Button
  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.
  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground
  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.
  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe
  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  4;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int tempButtonState = 0;

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  checkAnalogState();
  readSeriealPort();
}

void checkAnalogState() {
  tempButtonState = digitalRead(buttonPin);
  if (buttonState != tempButtonState) {
    buttonState = tempButtonState;
    reactToAnalogState();
  }
}

void reactToAnalogState() {
  if (buttonState == HIGH) {
    Serial.println(2);
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    Serial.println(3);
    digitalWrite(LED_BUILTIN, LOW);
  }
}

char inChar;
void readSeriealPort() {
  while(Serial.available()) {
    inChar = Serial.read();
    Serial.print(inChar);
    reactToSerialInput();
  }
}

void reactToSerialInput() {
  if (inChar == '1') {
    digitalWrite(ledPin, HIGH);
  } else if(inChar == '0') {
    digitalWrite(ledPin, LOW);
  }
}

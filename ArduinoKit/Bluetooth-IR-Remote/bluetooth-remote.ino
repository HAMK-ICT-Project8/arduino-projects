/*
  Example Bluetooth Serial Passthrough Sketch
 by: Jim Lindblom
 SparkFun Electronics
 date: February 26, 2013
 license: Public domain

 This example sketch converts an RN-42 bluetooth module to
 communicate at 9600 bps (from 115200), and passes any serial
 data between Serial Monitor and bluetooth module.
 */
#include <SoftwareSerial.h>  
#include <IRremote.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

int bluetoothTx = 2;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 3;  // RX-I pin of bluetooth mate, Arduino D3

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  Serial.begin(9600);  // Begin the serial monitor at 9600bps
  Serial.print("Setup");

  bluetooth.begin(115200);  // The Bluetooth Mate defaults to 115200bps
  bluetooth.print("$");  // Print three times individually
  bluetooth.print("$");
  bluetooth.print("$");  // Enter command mode
  delay(100);  // Short delay, wait for the Mate to send back CMD
  bluetooth.println("U,9600,N");  // Temporarily Change the baudrate to 9600, no parity
  // 115200 can be too fast at times for NewSoftSerial to relay the data reliably
  bluetooth.begin(9600);  // Start bluetooth serial at 9600
  bluetooth.print("$");
  bluetooth.print("$");
  bluetooth.print("$");

  irrecv.enableIRIn();
}

void loop()
{
  if(bluetooth.available())  // If the bluetooth sent any characters
  {
    // Send any characters the bluetooth prints to the serial monitor
    int input = (int)bluetooth.read();
    Serial.println(input);
  }
  if(Serial.available())  // If stuff was typed in the serial monitor
  {
    // Send any characters the Serial monitor prints to the bluetooth
    bluetooth.print((char)Serial.read());
  }
  
  if (irrecv.decode(&results)) {
    if (results.value == 0xFFFFFFFF) { // if the value is equal to 0xFFFFFFFF
      results.value = key_value; // set the value to the key value
    }
    switch (results.value) { // compare the value to the following cases
      case 0xFD00FF: 
        Serial.println("POWER"); // print "POWER" in the Serial Monitor
        bluetooth.println("POWER");
        break;
      case 0xFD807F:
        Serial.println("VOL+");
        break;
      case 0xFD40BF:
        Serial.println("FUNC/STOP");
        break;
      case 0xFD20DF:
        Serial.println("|<<");
        break;
      case 0xFDA05F:
        Serial.println(">||");
        break ;
      case 0xFD609F:
        Serial.println(">>|");
        break ;
      case 0xFD10EF:
        Serial.println("DOWN");
        break ;
      case 0xFD906F:
        Serial.println("VOL-");
        break ;
      case 0xFD50AF:
        Serial.println("UP");
        break ;
      case 0xFD30CF:
        Serial.println("0");
        break ;
      case 0xFDB04F:
        Serial.println("EQ");
        break ;
      case 0xFD708F:
        Serial.println("ST/REPT");
        break ;
      case 0xFD08F7:
        Serial.println("1");
        break ;
      case 0xFD8877:
        Serial.println("2");
        break ;
      case 0xFD48B7:
        Serial.println("3");
        break ;
      case 0xFD28D7:
        Serial.println("4");
        break ;
      case 0xFDA857:
        Serial.println("5");
        break ;
      case 0xFD6897:
        Serial.println("6");
        break ;
      case 0xFD18E7:
        Serial.println("7");
        break ;
      case 0xFD9867:
        Serial.println("8");
        break ;
      case 0xFD58A7:
        Serial.println("9");
        break ;
    }
    key_value = results.value;
    irrecv.resume();
    delay(100);
  }
  // and loop forever and ever!
}

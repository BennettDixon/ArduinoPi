#include "SoftwareSerial.h"
#define RELAY1  7   // Creates Variable RELAY1, assigns it pin 7

// RX: Arduino pin2, XBee pin DOUT.  TX: Arduino pin3, Xbee pin DIN
SoftwareSerial XBee(2,3);

void setup() 
{
  //Start XBee on baud rate 9600
  XBee.begin(9600);  
  pinMode(RELAY1, OUTPUT);
}

void loop() 
{
  
  if (XBee.available() > 0) 
  {
    char rx_byte = XBee.read();
    delay(50);
    if (rx_byte == '1')
    {
      digitalWrite(RELAY1,0);         // Turns ON Relay1
      XBee.write('O');
      delay(50);
    }
    else if(rx_byte == '0')
    {
      digitalWrite(RELAY1,1);         // Turns OFF Relay1
      XBee.write('F');
      delay(50);    
    }
  }
}

    
  

#include "SoftwareSerial.h"
#define ON  "ON"
#define OFF  "OFF"
#define ledPin  13
// RX: Arduino pin 2, XBee pin DOUT.  TX: Arduino pin3, XBee pin DIN
SoftwareSerial XBee(2,3);

void setup()
{    
  //BAUD rates must match XBee settings, and serial settings
  Serial.begin(9600);   
  pinMode(ledPin, OUTPUT);   
}

void loop()
{
   if (Serial.available() > 0)
   {
     light(Serial.read());
   }
   delay(100);
}

//send xbee_byte 0=OFF, 1=ON
void light(int n)
{
  for (int i = 0; i < n; i++) 
  {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
}

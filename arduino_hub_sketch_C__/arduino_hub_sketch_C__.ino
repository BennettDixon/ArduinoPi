#include "SoftwareSerial.h"
#define ON  "ON"
#define OFF  "OFF"
// RX: Arduino pin 2, XBee pin DOUT.  TX: Arduino pin3, XBee pin DIN
SoftwareSerial XBee(2,3);

void setup()
{    
  //BAUD rates must match XBee settings, and serial settings
  Serial.begin(9600);   
  XBee.begin(9600);   
}

void loop()
{
   if (Serial.available() > 0)
   {
     relay_switch(Serial.read());
   }
}

//send xbee_byte 0=OFF, 1=ON
void relay_switch(char on_off) 
{
  if (XBee.available())
  {
    if (on_off == "O") 
    { 
      XBee.write('O');
      Serial.println("Light ON");
    }
    else if (on_off == "F") 
    {
      XBee.write('F');
      Serial.println("Light OFF");
    }
    else
    {
      Serial.println("ERROR: Command invalid");
    }
  }
  else
  {
    Serial.println("ERROR: XBEE NOT AVAILABLE");
  }
}


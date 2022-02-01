#include <Wire.h>
#include <Adafruit_MCP4725.h>

int potPort = A0;
int minOut = 1550;
int maxOut = 3100;
int potMax = 1023;
// calculate x value in y=mx + b where b = minOut, assumes potMin is 0
float x = (float)(maxOut-minOut)/potMax;

Adafruit_MCP4725 dac;

void setup() {
  Serial.begin(115200);
  //Start DAC. DAC address 0x60 or 0x61
  dac.begin(0x60);
}

int normPot(){
  // Map the potentiometer value to minOut - maxOut scale
  int potRaw = analogRead(potPort);
  return (int)(x*potRaw + minOut);
}


void loop(){
  Serial.println(normPot());
  dac.setVoltage(normPot(), false);
  delayMicroseconds(1);
}

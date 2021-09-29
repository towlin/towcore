#include <Wire.h>
//MCP4725 library
#include <Adafruit_MCP4725.h>

int potPort = A0;

Adafruit_MCP4725 dac;

void setup() {
  //Start Serial
  Serial.begin(9600);
  //Start DAC. DAC address 0x60 or 0x61
  dac.begin(0x60);
}

int normPot(){
  int potRaw = analogRead(potPort);
  return (int)(2.48*potRaw + 655);
}

void loop(){
  Serial.println(normPot());
  dac.setVoltage(normPot(), false);
  delayMicroseconds(1);
}

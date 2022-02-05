#include <Wire.h>
#include <Adafruit_MCP4725.h>

int potPort = A0;
int outLow = 1600; // min output to account for boatmode
int outHigh1 = 3100; // max output for mode 1
int outHigh2 = 3500; // max output for mode 2
int potMax = 1023; // potentiometer maximum value
int switchPin = 11; // pin for initial on switch
int selectorPin1 = 6; // mode 1 pin
int selectorPin2 = 7; // mode 2 pin
float x = 0; // multiplier in y=mx+b

Adafruit_MCP4725 dac;

void setup() {
  Serial.begin(115200);
  Serial.println("test");
  pinMode(switchPin, INPUT_PULLUP); 
  pinMode(selectorPin1, INPUT_PULLUP);
  pinMode(selectorPin2, INPUT_PULLUP);
  dac.begin(0x60);
}

bool isOn() {
  return digitalRead(switchPin);
}

void checkSelector() {
  // calculate x value in y=mx + b where b = minOut, assumes potMin is 0
  if (!digitalRead(selectorPin2)){
    x = (float)(outHigh2-outLow)/potMax;
  } else if (!digitalRead(selectorPin1)){
    x = (float)(outHigh1-outLow)/potMax;
  }
  
}

int sendSpeed(){
  if (isOn()) {
    return outLow;
  }
  // Map the potentiometer value to minOut - maxOut scale
  int potRaw = analogRead(potPort);
  return (int)(x*potRaw + outLow);
}

void loop(){
  checkSelector(); // continually check selector
  Serial.println(sendSpeed());
  dac.setVoltage(sendSpeed(), false);
  delayMicroseconds(1);
}

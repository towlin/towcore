#include <Arduino.h>

const byte hal1 = 2;
const byte hal2 = 3;
const byte hal3 = 4;
const int halCount = 3;
int hal1Count = 0;
int hal2Count = 0;
int hal3Count = 0;

volatile byte signal1;
volatile byte signal2;
volatile byte signal3;

void signal1_ISR() {
  Serial.println(1);
  hal1Count += 1;
}

void signal2_ISR() {
  Serial.println(2);
  hal2Count +=1;
}

void signal3_ISR() {
  Serial.println(3);
  hal3Count +=1;
}

void setup() {
  Serial.begin(9600);
  pinMode(hal1, INPUT_PULLUP);
  pinMode(hal2, INPUT_PULLUP);
  pinMode(hal3, INPUT_PULLUP);

  signal1 = digitalRead(hal1);
  signal2 = digitalRead(hal2);
  signal3 = digitalRead(hal3);

  attachInterrupt(digitalPinToInterrupt(hal1),signal1_ISR,CHANGE);
  attachInterrupt(digitalPinToInterrupt(hal2),signal2_ISR,CHANGE);
  attachInterrupt(digitalPinToInterrupt(hal3),signal3_ISR,CHANGE);
}

void loop() {
  /*
  Serial.print(hal1Count);
  Serial.print(", ");
  Serial.print(hal2Count);
  Serial.print(", ");
  Serial.print(hal3Count);
  Serial.println("");
  */
}




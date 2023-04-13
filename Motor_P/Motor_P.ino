// #include <Wire.h>
#include "MotorControl.hpp"
#include "Receiver.hpp"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // Wire.begin(1);
  // Wire.onReceive(receiveEvent);  
  while(!Serial);
}

void loop() {
  // put your main code here, to run repeatedly:
  SerialEvent();
  for(int i = 0; i < 1; i++)
    Motors[i].Play(MotorHeight[i]);
}
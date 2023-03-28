#include <Wire.h>
#include "MotorControl.hpp"
#include "Receiver.hpp"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin(1);
  Wire.onReceive(receiveEvent);  
  while(!Serial);
}

void loop() {
  // put your main code here, to run repeatedly:
  Motor1.Play(M1Height);
  Motor2.Play(M2Height);
  Motor3.Play(M3Height);
  Motor4.Play(M4Height);
  Motor5.Play(M5Height);
  Motor6.Play(M6Height);
  Motor7.Play(M7Height);
  Motor8.Play(M8Height);
  Motor9.Play(M9Height);
  Motor10.Play(M10Height);
  Motor11.Play(M11Height);
  Motor12.Play(M12Height);
  Motor13.Play(M13Height);
  Motor14.Play(M14Height);
  Motor15.Play(M15Height);
  Motor16.Play(M16Height);
}
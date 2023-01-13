#include<Wire.h>

char *buff = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available())
  {
    int MachineNum = Serial.parseInt();
    while(Serial.available())
    {
      char inChar = (char)Serial.read();
      buff += inChar;
      if(inChar == '\n')
      {
        Wire.beginTransmission(MachineNum);
        Wire.write(buff);
        Wire.endTransmission();
        buff = "";
        break;
      }
    }
  }
  buff = "";
}

#include<ArduinoJson.h>
#include "MotorControl.hpp"

const int LedPin = 13;

String buff = "";
const byte machine_id = 1;
const size_t capacity = JSON_OBJECT_SIZE(4) + JSON_ARRAY_SIZE(16) + 7;
StaticJsonDocument<capacity> jb;

Motor Motor1(Motor_1_P, Motor_1_N, Sensor_1, Switch_1);
Motor Motor2(Motor_2_P, Motor_2_N, Sensor_2, Switch_2);
int M1Height;
int M2Height;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Motor1.InitPin();
  Motor2.InitPin();
  while(!Serial);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available())
  {
    char inChar = (char)Serial.read();
    if(inChar == '\n')
    {
      DeserializationError err = deserializeJson(jb, buff);
      if(err)
      {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(err.c_str());
      }

      if(jb["i"] == machine_id)
      {
        if(jb["c"] == "led")
        {
          if(jb["d"] == 1)digitalWrite(LedPin, HIGH);
          else if(jb["d"] == 0)digitalWrite(LedPin, LOW);
        }
        else if(jb["c"] == "motor")
        {
          Motor1.Distance = (int)jb["d"][0];
          Motor2.Distance = (int)jb["d"][1];
        }
      }
    }
    else buff += inChar;
  }

  Motor1.Play(M1Height);
  Motor2.Play(M2Height);
}
#include<ArduinoJson.h>
#include "Wire.h"
#include "MotorControl.hpp"

const int LedPin = 13;

String buff = "";
const byte machine_id = 1;
const size_t capacity = JSON_OBJECT_SIZE(4) + JSON_ARRAY_SIZE(16) + 7;
StaticJsonDocument<capacity> jb;

void receiveEvent()
{
  while(Wire.available())
  {
    char inChar = (char)Wire.read();
    if(inChar == '\n')
    {
      deserializeJson(jb, buff);
      buff = "";

      if(jb["i"] == machine_id)
      {
        if(jb["c"] == "led")
        {
          if(jb["d"] == 1)digitalWrite(LedPin, HIGH);
          else if(jb["d"] == 0)digitalWrite(LedPin, LOW);
        }
        else if(jb["c"] == "motor")
        {
          M1Height = (int)jb["d"][0];
          M2Height = (int)jb["d"][1];
          M3Height = (int)jb["d"][2];
          M4Height = (int)jb["d"][3];
          M5Height = (int)jb["d"][4];
          M6Height = (int)jb["d"][5];
          M7Height = (int)jb["d"][6];
          M8Height = (int)jb["d"][7];
          M9Height = (int)jb["d"][8];
          M10Height = (int)jb["d"][9];
          M11Height = (int)jb["d"][10];
          M12Height = (int)jb["d"][11];
          M13Height = (int)jb["d"][12];
          M14Height = (int)jb["d"][13];
          M15Height = (int)jb["d"][14];
          M16Height = (int)jb["d"][15];
        }
        else if(jb["c"] == "reset")
          while(Motor1.Reset() || Motor2.Reset() || Motor3.Reset() || Motor4.Reset() || Motor5.Reset() || Motor6.Reset() || Motor7.Reset() || Motor8.Reset() ||
                Motor9.Reset() || Motor10.Reset() || Motor11.Reset() || Motor12.Reset() || Motor13.Reset() || Motor14.Reset() || Motor15.Reset() || Motor16.Reset());
      }
    }
    else buff += inChar;
  }
}
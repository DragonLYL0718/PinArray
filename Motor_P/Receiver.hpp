#include<ArduinoJson.h>
// #include "Wire.h"
#include "MotorControl.hpp"
#include "Global.hpp"

const int LedPin = 13;

String buff = "";
const byte machine_id = 1;
const size_t capacity = JSON_OBJECT_SIZE(4) + JSON_ARRAY_SIZE(16) + 7;
StaticJsonDocument<capacity> jb;

// void receiveEvent()
// {
//   while(Wire.available())
//   {
//     char inChar = (char)Wire.read();
//     if(inChar == '\n')
//     {
//       deserializeJson(jb, buff);
//       buff = "";

//       if(jb["i"] == machine_id)
//       {
//         if(jb["c"] == "led")
//         {
//           if(jb["d"] == 1)digitalWrite(LedPin, HIGH);
//           else if(jb["d"] == 0)digitalWrite(LedPin, LOW);
//         }
//         else if(jb["c"] == "motor")
//         {
//           for(int i = 0; i < 16; i++){
//             MotorHeight[i] = (int)jb["d"][i];
//             Serial.println(MotorHeight[i]);
//           }
//         }
//         else if(jb["c"] == "reset")
//           while(Motor1.Reset() || Motor2.Reset() || Motor3.Reset() || Motor4.Reset() || Motor5.Reset() || Motor6.Reset() || Motor7.Reset() || Motor8.Reset() ||
//                 Motor9.Reset() || Motor10.Reset() || Motor11.Reset() || Motor12.Reset() || Motor13.Reset() || Motor14.Reset() || Motor15.Reset() || Motor16.Reset());
//       }
//     }
//     else buff += inChar;
//   }
// }

void SerialEvent()
{
  if(Serial.available())
  {
    char inChar;
    while(1){
      while(!Serial.available());
      inChar = (char)Serial.read();
      if(inChar == '\n'){
        DeserializationError err = deserializeJson(jb, buff);
        if (err) {
          Serial.print(F("deserializeJson() failed: "));
          Serial.println(err.c_str());
        }
        Serial.println(buff);
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
            for(int i = 0; i < 9; i++){
              MotorHeight[i] = (int)jb["d"][i];
            }
          }
          else if(jb["c"] == "reset"){
            while(Motors[0].Reset() | Motors[1].Reset() | Motors[2].Reset() | Motors[3].Reset());
            for(int i = 0; i < 9; i++)
              MotorHeight[i] = 0;
          }
            // while(Motor1.Reset() || Motor2.Reset() || Motor3.Reset() || Motor4.Reset() || Motor5.Reset() || Motor6.Reset() || Motor7.Reset() || Motor8.Reset() || Motor9.Reset());
        }
        break;
      }
      else buff += inChar;
    }
  }
}
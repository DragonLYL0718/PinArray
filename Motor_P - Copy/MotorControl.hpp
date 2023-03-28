#ifndef _MOTORCONTROL_
#define _MOTORCONTROL_

//Motor Pin
const int Motor_1_P = 0; //motor1 positive pole
const int Motor_1_N = 1; //motor1 negative pole
const int Motor_2_P = 4; 
const int Motor_2_N = 5; 
const int Motor_3_P = 6; 
const int Motor_3_N = 7; 
const int Motor_4_P = 8; 
const int Motor_4_N = 9; 
const int Motor_5_P = 10; 
const int Motor_5_N = 11; 
const int Motor_6_P = 12; 
const int Motor_6_N = 13; 
const int Motor_7_P = 14; 
const int Motor_7_N = 15; 
const int Motor_8_P = 16; 
const int Motor_8_N = 17; 
const int Motor_9_P = 18; 
const int Motor_9_N = 19; 
const int Motor_10_P = 22; 
const int Motor_10_N = 23; 
const int Motor_11_P = 24; 
const int Motor_11_N = 25;
const int Motor_12_P = 26;
const int Motor_12_N = 27;
const int Motor_13_P = 28;
const int Motor_13_N = 29;
const int Motor_14_P = 30;
const int Motor_14_N = 31;
const int Motor_15_P = 32;
const int Motor_15_N = 33;
const int Motor_16_P = 34;
const int Motor_16_N = 35;
//Sensor Pin
const int Sensor_1 = 54; //Hallval sensor 1
const int Sensor_2 = 55;
const int Sensor_3 = 56; 
const int Sensor_4 = 57; 
const int Sensor_5 = 58;  
const int Sensor_6 = 59; 
const int Sensor_7 = 60; 
const int Sensor_8 = 61; 
const int Sensor_9 = 62; 
const int Sensor_10 = 63; 
const int Sensor_11 = 64; 
const int Sensor_12 = 65; 
const int Sensor_13 = 66; 
const int Sensor_14 = 67; 
const int Sensor_15 = 68; 
const int Sensor_16 = 69; 
//Switch Pin
const int Switch_1 = 36;
const int Switch_2 = 37;
const int Switch_3 = 38;
const int Switch_4 = 39;
const int Switch_5 = 40;
const int Switch_6 = 41;
const int Switch_7 = 42;
const int Switch_8 = 43;
const int Switch_9 = 44;
const int Switch_10 = 45;
const int Switch_11 = 46;
const int Switch_12 = 47;
const int Switch_13 = 48;
const int Switch_14 = 49;
const int Switch_15 = 50;
const int Switch_16 = 51;

int M1Height = 0;
int M2Height = 0;
int M3Height = 0;
int M4Height = 0;
int M5Height = 0;
int M6Height = 0;
int M7Height = 0;
int M8Height = 0;
int M9Height = 0;
int M10Height = 0;
int M11Height = 0;
int M12Height = 0;
int M13Height = 0;
int M14Height = 0;
int M15Height = 0;
int M16Height = 0;

typedef class motor
{
  public:
    int StepCount = 0; //count
    int Distance = 0;
    int PrevDistance = 0;
    bool CheckState = true;//false: operating; true: done;

    motor(int pinpositve, int pinnegative, int sensor, int switchpin)
    {
      MotorPinPositve = pinpositve;
      MotorPinNegative = pinnegative;
      Sensor = sensor;
      Switch = switchpin;
      pinMode(MotorPinPositve, OUTPUT);
      pinMode(MotorPinNegative, OUTPUT);
      pinMode(Sensor, INPUT);
      pinMode(Switch, INPUT);
    }

    void MoveUp()
    {
      digitalWrite(MotorPinPositve, LOW);
      digitalWrite(MotorPinNegative, HIGH);
    }

    void MoveDown()
    {
      digitalWrite(MotorPinPositve, HIGH);
      digitalWrite(MotorPinNegative, LOW);
    }

    void MoveStop()
    {
      digitalWrite(MotorPinPositve, LOW);
      digitalWrite(MotorPinNegative, LOW);
    }

    void MoveHome()
    {
      SwitchValue = analogRead(Switch);
      if(SwitchValue == LOW)MoveDown();
      else MoveStop();
    }

    int GetHallValue()
    {
      return analogRead(Sensor);
    }

    bool GetHallPolarity()
    {
      Hallval = GetHallValue();
      if(Hallval <= 550)return true;
      else if(Hallval >= 750)return false;
      else if(StepCount % 2 == 1)return true;      
    }

    void StepMove(int StepNum, bool direction)
    {
      //direction false: down; true: up;
      SwitchValue = digitalRead(Switch);
      if(SwitchValue == HIGH)
      {
        Hallval = 0;
        StepCount = 0;
        Polarity = true;
        CurrentDistance = 0;
        Distance = 0;
        PrevDistance = 0;
        CheckState = true;
      }
      else if(StepNum == StepCount)
      {
        PrevDistance = Distance;
        StepCount = 0;
        CheckState = true;
      }
      else
      {
        if(direction)MoveUp();
        else MoveDown();
        CheckState = false;
        StepCount++;
      }      
    }

    void Play(int distance)
    {
      if(CheckState == false && CurrentDistance != distance)
      {
        if(Distance > PrevDistance)PrevDistance += StepCount;          
        else PrevDistance -= StepCount;
        StepCount = 0;    
      }
      else if(CheckState)StepCount = 0;

      Distance = distance; 
      CurrentDistance = distance;

      if(Distance == PrevDistance)CheckState = true;
      else if(Distance > PrevDistance)
        StepMove((Distance - PrevDistance), true);
      else
        StepMove((PrevDistance - Distance), false);
    }

    bool Reset()
    {
      if(SwitchValue == LOW)MoveHome();
      else
      {
        Hallval = 0;
        StepCount = 0;
        Polarity = true;
        CurrentDistance = 0;
        Distance = 0;
        PrevDistance = 0;
        CheckState = true;
        return false;
      }
      return true;
    }

  private:
    int Hallval = 0; // the value of the hallval
    bool Polarity = true; //Record the change in the number of poles of the magnet
    int CurrentDistance = 0;
    int MotorPinPositve;
    int MotorPinNegative;
    int Sensor;
    int Switch;
    int SwitchValue = 0;
}Motor;

Motor Motor1(Motor_1_P, Motor_1_N, Sensor_1, Switch_1);
Motor Motor2(Motor_2_P, Motor_2_N, Sensor_2, Switch_2);
Motor Motor3(Motor_3_P, Motor_3_N, Sensor_3, Switch_3);
Motor Motor4(Motor_4_P, Motor_4_N, Sensor_4, Switch_4);
Motor Motor5(Motor_5_P, Motor_5_N, Sensor_5, Switch_5);
Motor Motor6(Motor_6_P, Motor_6_N, Sensor_6, Switch_6);
Motor Motor7(Motor_7_P, Motor_7_N, Sensor_7, Switch_7);
Motor Motor8(Motor_8_P, Motor_8_N, Sensor_8, Switch_8);
Motor Motor9(Motor_9_P, Motor_9_N, Sensor_9, Switch_9);
Motor Motor10(Motor_10_P, Motor_10_N, Sensor_10, Switch_10);
Motor Motor11(Motor_11_P, Motor_11_N, Sensor_11, Switch_11);
Motor Motor12(Motor_12_P, Motor_12_N, Sensor_12, Switch_12);
Motor Motor13(Motor_13_P, Motor_13_N, Sensor_13, Switch_13);
Motor Motor14(Motor_14_P, Motor_14_N, Sensor_14, Switch_14);
Motor Motor15(Motor_15_P, Motor_15_N, Sensor_15, Switch_15);
Motor Motor16(Motor_16_P, Motor_16_N, Sensor_16, Switch_16);

#endif
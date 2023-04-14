#include "Arduino.h"
#include "HardwareSerial.h"
#ifndef _MOTORCONTROL_
#define _MOTORCONTROL_
#include "Global.hpp"

#define P 0.5
#define D 0

typedef class motor
{
  public:
    motor(int pinpositve, int pinnegative, int encodera, int encoderb, int pwmpin,int switchpin)
    {
      MotorPinPositve = pinpositve;
      MotorPinNegative = pinnegative;
      Encoder_A = encodera;
      Encoder_B = encoderb;
      PWMPin = pwmpin;
      Switch = switchpin;
      pinMode(MotorPinPositve, OUTPUT);
      pinMode(MotorPinNegative, OUTPUT);
      pinMode(Encoder_A, INPUT_PULLUP);
      pinMode(Switch, INPUT);
      pinMode(PWMPin, OUTPUT);
    }

    void MoveUp()
    {
      // Serial.println("moveUP");
      digitalWrite(MotorPinPositve, LOW);
      digitalWrite(MotorPinNegative, HIGH);
      // Serial.println("moveDOWN");
    }

    void MoveDown()
    {
      // Serial.println("moveDOWN");
      digitalWrite(MotorPinPositve, HIGH);
      digitalWrite(MotorPinNegative, LOW);
    }

    void MoveStop()
    {
      digitalWrite(MotorPinPositve, LOW);
      digitalWrite(MotorPinNegative, LOW);
    }

    bool Reset()
    {
      SwitchValue = digitalRead(Switch);
      if(SwitchValue == HIGH){
        analogWrite(PWMPin, 255);
        MoveDown();
      }
      else
      {
        MoveStop();
        Distance_diff = 0;
        StepCount = 0;
        Distance = 0;
        PrevDistance = 0;
        CheckState = true;
        PrevEncoder_A = LOW;
        EncoderValue = 0;
        TargetSum = 0;
        return false;
      }
      return true;
    }

    void EncoderCount(){
      if(digitalRead(Encoder_A) == HIGH && PrevEncoder_A == LOW)
      {
        PrevEncoder_A = HIGH;
        if(digitalRead(Encoder_B))EncoderValue--;
        else EncoderValue++;
        // Serial.print("EncoderValue: ");
        // Serial.println(EncoderValue);
      }
      else if(digitalRead(Encoder_A) == LOW)
        PrevEncoder_A = LOW;
    }

    void StepMove(int StepNum)
    {
      //direction false: down; true: up;
      EncoderCount();//count the encoder value
      // Serial.println("StepMove");
      SwitchValue = digitalRead(Switch);
      if(SwitchValue == LOW && StepCount < EncoderValue)//move to home
      {
        Serial.println("Reset");
        Distance_diff = 0;
        StepCount = 0;
        Distance = 0;
        PrevDistance = 0;
        CheckState = true;
        PrevEncoder_A = LOW;
        EncoderValue = 0;
        TargetSum = 0;
      }
      if(abs(StepNum - EncoderValue) < 10 && TargetSum < 1000)
      {
        TargetSum++;
      }
      if(abs(StepNum - EncoderValue)< 10 && TargetSum >= 1000){
        MoveStop();
        // Serial.println(EncoderValue);
        PrevDistance = Distance;
        StepCount = 0;
        CheckState = true;
        TargetSum = 0;
        PrevError = 0;
        // Serial.print("PrevDistance: ");
        // Serial.println(PrevDistance);
      }
      else
      {
        if(abs(StepNum - EncoderValue) > 10)TargetSum = 0;

        int Error = StepNum - EncoderValue;
        int Pout = P * Error + D * (Error - PrevError);
        PrevError = Error;
        // Serial.println(Error);

        if(Pout > 255)Pout = 255;
        else if(Pout < -255)Pout = -255;
        if(Pout < 120 && Pout > 0)Pout = 120;
        else if(Pout > -120 && Pout < 0)Pout = -120;
        analogWrite(PWMPin, abs(Pout));
        if(Pout > 0)MoveUp();
        else MoveDown();
      }      
    }

    void Play(int distance)
    {
      // Serial.println("Play");
      // Serial.println(EncoderValue);
      if(CheckState && distance != PrevDistance){//first time to set distance
        // Serial.println(PrevDistance);
        Distance_diff = distance * ARoundNum;

        Distance = distance;//set the expected distance
        CheckState = false;
        // Serial.println("GetTarget");
      }

      if(!CheckState){
        // Serial.println("CheckState");
        StepMove(Distance_diff);
      }
    }

  private:
    int StepCount = 0; //count
    int Distance = 0;
    int PrevDistance = 0;
    bool CheckState = true;//false: operating; true: done;
    int Distance_diff = 0;
    int MotorPinPositve;
    int MotorPinNegative;
    int PWMPin;
    int Encoder_A;
    int Encoder_B;
    int PrevEncoder_A = LOW;
    int EncoderValue = 0;
    int Switch;
    int SwitchValue = 0;
    int TargetSum = 0;
    int PrevError = 0;
}Motor;

Motor Motor1(Motor_1_P, Motor_1_N, Encoder_1_A, Encoder_1_B, PWM_1,Switch_1);
Motor Motor2(Motor_2_P, Motor_2_N, Encoder_2_A, Encoder_2_B, PWM_2,Switch_2);
Motor Motor3(Motor_3_P, Motor_3_N, Encoder_3_A, Encoder_3_B, PWM_3,Switch_3);
Motor Motor4(Motor_4_P, Motor_4_N, Encoder_4_A, Encoder_4_B, PWM_4,Switch_4);
Motor Motor5(Motor_5_P, Motor_5_N, Encoder_5_A, Encoder_5_B, PWM_5,Switch_5);
Motor Motor6(Motor_6_P, Motor_6_N, Encoder_6_A, Encoder_6_B, PWM_6,Switch_6);
Motor Motor7(Motor_7_P, Motor_7_N, Encoder_7_A, Encoder_7_B, PWM_7,Switch_7);
Motor Motor8(Motor_8_P, Motor_8_N, Encoder_8_A, Encoder_8_B, PWM_8,Switch_8);
Motor Motor9(Motor_9_P, Motor_9_N, Encoder_9_A, Encoder_9_B, PWM_9,Switch_9);
Motor Motors[9] = {Motor1, Motor2, Motor3, Motor4, Motor5, Motor6, Motor7, Motor8, Motor9};

#endif
//Motor Pin
const int Motor_1_P = 0; //motor1 positive pole
const int Motor_1_N = 1; //motor1 negative pole
const int Motor_2_P = 3; //motor2 positive pole
const int Motor_2_N = 4; //motor2 negetive pole
//Sensor Pin
const int Sensor_1 = 54; //Hallval sensor 1
const int Sensor_2 = 55; //Hallval sensor 2
//Switch Pin
const int Switch_1 = 36;
const int Switch_2 = 37;

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
    }

    void InitPin()
    {
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
        PrevDistance = 0;
        CheckState = true;
      }
      else if(StepNum == StepCount)
      {
        PrevDistance = Distance;
        CheckState = true;
      }
      else
      {
        if(direction)MoveUp();
        else MoveDown();
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
      Distance = distance; 
      CurrentDistance = distance;

      if(Distance == PrevDistance)CheckState = true;
      else if(Distance > PrevDistance)
        StepMove((Distance - PrevDistance), true);
      else
        StepMove((PrevDistance - Distance), false);
    }

    void Reset()
    {
      MoveHome();
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
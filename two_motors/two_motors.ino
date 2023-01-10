//2022-12-05 two motors control
//ZhangPeng

#include<stdbool.h>
#define Motor_1_P 0 //motor1 positive pole
#define Motor_1_N 1 //motor1 negative pole
#define Motor_2_P 2 //motor2 positive pole
#define Motor_2_N 3 //motor2 negetive pole
//Because pin 4 and pin 5 are for communication
#define Sensor_1 6 //Hallval sensor 1
#define Sensor_2 7 //Hallval sensor 2

struct initial_hallval
{
  int Hallval=0; // the value of the hallval
  int Step_count=0; //count
  int Record_Step_count=0; 
  bool polarity; //Record the change in the number of poles of the magnet
  int distance=0;
  int Record_initial_distance=0;
};

//forward function
void Motor1_Forward();
void Motor2_Forward();
//backward function
void Motor1_Backward();
void Motor2_Backward();
//stop function
void Motor1_Stop();
void Motor2_Stop();
//return Hallval valve
int Hallval_sensor_1_value();
int Hallval_sensor_2_value();
//Record the number of changes in magnet poles
bool hallpolarity_motor1();
bool hallpolarity_motor2();

struct initial_hallval Motor_1;//define motor 1
struct initial_hallval Motor_2;//define motor 2
struct initial_hallval *motor_1=&Motor_1;
struct initial_hallval *motor_2=&Motor_2;
void setup() 
{
  Serial.begin(9600);
  //Initializing the motor pins
  pinMode(Motor_1_P,OUTPUT);
  pinMode(Motor_1_N,OUTPUT);
  pinMode(Motor_2_P,OUTPUT);
  pinMode(Motor_2_N,OUTPUT);
}

void Motor1_Forward()
{
  digitalWrite(Motor_1_P,HIGH);
  digitalWrite(Motor_1_N,LOW);
}

void Motor2_Forward()
{
  digitalWrite(Motor_2_P,HIGH);
  digitalWrite(Motor_2_N,LOW);
}

void Motor1_Backward()
{
  digitalWrite(Motor_1_P,LOW);
  digitalWrite(Motor_1_N,HIGH);
}

void Motor2_Backward()
{
  digitalWrite(Motor_2_P,LOW);
  digitalWrite(Motor_2_N,HIGH);
}

void Motor1_Stop()
{
  digitalWrite(Motor_1_P,LOW);
  digitalWrite(Motor_1_N,LOW);
}

void Motor2_Stop()
{
  digitalWrite(Motor_2_P,LOW);
  digitalWrite(Motor_2_N,LOW);
}

int Hallval_sensor_1_value()
{
  return analogRead(Sensor_1);
}

int Hallval_sensor_2_value()
{
  return analogRead(Sensor_2);
}

bool hallpolarity_motor1()
{
  motor_1->Hallval=Hallval_sensor_1_value();
  //Serial.println(Hallval);
  if(motor_1->Hallval<=550)
  {
      return true;
  }
  if(motor_1->Hallval>=750)
  {
    return false;
  }
 if(motor_1->Step_count%2==1)
  {
    return true;
  }
  return false;
}

bool hallpolarity_motor2()
{
  motor_2->Hallval=Hallval_sensor_2_value();
  //Serial.println(Hallval);
  if(motor_2->Hallval<=550)
  {
      return true;
  }
  if(motor_2->Hallval>=750)
  {
    return false;
  }
 if(motor_2->Step_count%2==1)
  {
    return true;
  }
  return false;
}

int Step_counts_motor1()
{
  if(motor_1->polarity!=hallpolarity_motor1())
  {
    motor_1->Step_count++;
    motor_1->polarity=hallpolarity_motor1();
    return motor_1->Step_count;
  }
}

int Step_counts_motor2()
{
  if(motor_2->polarity!=hallpolarity_motor2())
  {
    motor_2->Step_count++;
    motor_2->polarity=hallpolarity_motor2();
    return motor_2->Step_count;
  }
}

int Round_count_motor1()
{
  int Round=0;
  if(motor_1->Step_count%2==0)
  {
    Round=motor_1->Step_count/2;
  }
  return Round;
}

int Round_count_motor2()
{
  int Round=0;
  if(motor_2->Step_count%2==0)
  {
    Round=motor_2->Step_count/2;
  }
  return Round;
}

void Reset_Step_count_motor1()
{
  motor_1->Step_count=0;
}

void Reset_Step_count_motor2()
{
  motor_2->Step_count=0;
}

void calculate_distance()
{
  int displacement1=0;//motor_1's displacement
  int displacement2=0;//motor_2's displacement
  //input the imformation about motor1's position
  Serial.println("Please enter the position of motor1 you want to move to");
  motor_1->Record_initial_distance=motor_1->distance;
  delay(50);
  Serial.flush();
  while(Serial.available()==0)//Waiting for input
  {

  }
  motor_1->distance=Serial.parseInt();
  delay(50);
  Serial.print("you enter the:");
  Serial.println(motor_1->distance);
  delay(50);

  //input the imformation about motor2's position
  Serial.println("Please enter the position of motor2 you want to move to");
  motor_2->Record_initial_distance=motor_2->distance;
  delay(50);
  Serial.flush();
  while(Serial.available()==0)//Waiting for input
  {

  }
  motor_2->distance=Serial.parseInt();
  delay(50);
  Serial.print("you enter the:");
  Serial.println(motor_2->distance);
  delay(50);

  //analyze the input situation
  //stop situation
  if((motor_1->distance==motor_1->Record_initial_distance)&&(motor_2->distance==motor_2->Record_initial_distance))
  {
    Motor1_Stop();
    Motor2_Stop();
    Serial.println("motor1 is not need to move!");
    Serial.println("motor2 is not need to move!");
  }

  //move situation
  //both forward at the same time 
  if((motor_1->distance>motor_1->Record_initial_distance)&&(motor_2->distance>motor_2->Record_initial_distance))
  {
    displacement1=motor_1->distance-motor_1->Record_initial_distance;
    displacement2=motor_2->distance-motor_2->Record_initial_distance;
    //Displacement value must be less than 100
    if((displacement1<=100)&&(displacement2<=100))
    {
      Serial.println("Motor1 needs to move forward!");
      Serial.println("Motor2 needs to move forward!");
      Motor1_Forward();
      Motor2_Forward();
      while(1)
      {
        Step_counts_motor1();
        Step_counts_motor2();
        //if motor 1 reach the position and need to stop first
        if(Round_count_motor1()>=displacement1)
        {
          Motor1_Stop();
          if(Round_count_motor2()>=displacement2)
          {
            Motor2_Stop();
            Reset_Step_count_motor1();
            Reset_Step_count_motor2();
            break;
          }
        }
        //if motor 2 reach the position and need to stop first
        else if(Round_count_motor2()>=displacement2)
        {
          Motor2_Stop();
          if(Round_count_motor1()>=displacement2)
          {
            Motor1_Stop();
            Reset_Step_count_motor1();
            Reset_Step_count_motor2();
            break;
          }
        }
      }
    }
    else
    {
      if((displacement1>100)&&(displacement2<=100))
      {
        Serial.println("motor1 displacement error!");
        Motor1_Stop();
        Serial.println("Motor2 needs to move forward!");
        Motor2_Forward();
        while(1)
        {
          Step_counts_motor2();
          if(Round_count_motor2()>=displacement2)
          {
            Motor2_Stop();
            Reset_Step_count_motor2();
            break;
          }
        }
      }
      else if((displacement1<=100)&&(displacement2>100))
      {
        Serial.println("motor2 displacement error!");
        Motor2_Stop();
        Serial.println("Motor1 needs to move forward!");
        Motor1_Forward();
        while(1)
        {
          Step_counts_motor1();
          if(Round_count_motor1()>=displacement1)
          {
            Motor1_Stop();
            Reset_Step_count_motor1();
            break;
          }
        }
      }
      else
      {
        Serial.println("motor1 displacement error!");
        Serial.println("motor2 displacement error!");
      }
    }
  }

  //both backward at the same time
  if((motor_1->distance<motor_1->Record_initial_distance)&&(motor_2->distance<motor_2->Record_initial_distance))
  {
    displacement1=motor_1->Record_initial_distance-motor_1->distance;
    displacement2=motor_2->Record_initial_distance-motor_2->distance;
    //Displacement value must be less than 100
    if((displacement1<=100)&&(displacement2<=100))
    {
      Serial.println("Motor1 needs to move backward!");
      Serial.println("Motor2 needs to move backward!");
      Motor1_Backward();
      Motor2_Backward();
      while(1)
      {
        Step_counts_motor1();
        Step_counts_motor2();
         //if motor 1 reach the position and need to stop first
        if(Round_count_motor1()>=displacement1)
        {
          Motor1_Stop();
          if(Round_count_motor2()>=displacement2)
          {
            Motor2_Stop();
            Reset_Step_count_motor1();
            Reset_Step_count_motor2();
            break;
          }
        }
          //if motor 2 reach the position and need to stop first
        else if(Round_count_motor2()>=displacement2)
        {
          Motor2_Stop();
          if(Round_count_motor1()>=displacement2)
          {
            Motor1_Stop();
            Reset_Step_count_motor1();
            Reset_Step_count_motor2();
            break;
          }
        }
      }
    }
    else
    {
      if((displacement1>100)&&(displacement2<=100))
      {
        Serial.println("motor1 displacement error!");
        Motor1_Stop();
        Serial.println("Motor2 needs to move backward!");
        Motor2_Backward();
        while(1)
        {
          Step_counts_motor2();
          if(Round_count_motor2()>=displacement2)
          {
            Motor2_Stop();
            Reset_Step_count_motor2();
            break;
          }
        }
      }
      else if((displacement1<=100)&&(displacement2>100))
      {
        Serial.println("motor2 displacement error!");
        Motor2_Stop();
        Serial.println("Motor1 needs to move backward!");
        Motor1_Backward();
        while(1)
        {
          Step_counts_motor1();
          if(Round_count_motor1()>=displacement1)
          {
            Motor1_Stop();
            Reset_Step_count_motor1();
            break;
          }
        }
      }
      else
      {
        Serial.println("motor1 displacement error!");
        Serial.println("motor2 displacement error!");
      }
    }
  }

  //motor 1 forward and motor 2 backward
  if((motor_1->distance>motor_1->Record_initial_distance)&&(motor_2->distance<motor_2->Record_initial_distance))
  {
    displacement1=motor_1->distance-motor_1->Record_initial_distance;
    displacement2=motor_2->Record_initial_distance-motor_2->distance;
    //Displacement value must be less than 100
    if((displacement1<=100)&&(displacement2<=100))
    {
      Serial.println("Motor1 needs to move forward!");
      Serial.println("Motor2 needs to move backward!");
      Motor1_Forward();
      Motor2_Backward();
      while(1)
      {
        Step_counts_motor1();
        Step_counts_motor2();
        if(Round_count_motor1()>=displacement1)
        {
          Motor1_Stop();
          if(Round_count_motor2()>=displacement2)
          {
            Motor2_Stop();
            Reset_Step_count_motor1();
            Reset_Step_count_motor2();
            break;
          }
        }
        else if(Round_count_motor2()>=displacement2)
        {
          Motor2_Stop();
          if(Round_count_motor1()>=displacement2)
          {
            Motor1_Stop();
            Reset_Step_count_motor1();
            Reset_Step_count_motor2();
            break;
          }
        }
      }
    }
    else
    {
      if((displacement1>100)&&(displacement2<=100))
      {
        Serial.println("motor1 displacement error!");
        Motor1_Stop();
        Serial.println("Motor2 needs to move backward!");
        Motor2_Backward();
        while(1)
        {
          Step_counts_motor2();
          if(Round_count_motor2()>=displacement2)
          {
            Motor2_Stop();
            Reset_Step_count_motor2();
            break;
          }
        }
      }
      else if((displacement1<=100)&&(displacement2>100))
      {
        Serial.println("motor2 displacement error!");
        Motor2_Stop();
        Serial.println("Motor1 needs to move forward!");
        Motor1_Forward();
        while(1)
        {
          Step_counts_motor1();
          if(Round_count_motor1()>=displacement1)
          {
            Motor1_Stop();
            Reset_Step_count_motor1();
            break;
          }
        }
      }
      else
      {
        Serial.println("motor1 displacement error!");
        Serial.println("motor2 displacement error!");
      }
    }
  }

  //motor 1 backward and motor 2 forward
  if((motor_1->distance<motor_1->Record_initial_distance)&&(motor_2->distance>motor_2->Record_initial_distance))
  {
    displacement1=motor_1->Record_initial_distance-motor_1->distance;
    displacement2=motor_2->distance-motor_2->Record_initial_distance;
    //Displacement value must be less than 100
    if((displacement1<=100)&&(displacement2<=100))
    {
      Serial.println("Motor1 needs to move backward!");
      Serial.println("Motor2 needs to move forward!");
      Motor1_Backward();
      Motor2_Forward();
      while(1)
      {
        Step_counts_motor1();
        Step_counts_motor2();
        if(Round_count_motor1()>=displacement1)
        {
          Motor1_Stop();
          if(Round_count_motor2()>=displacement2)
          {
            Motor2_Stop();
            Reset_Step_count_motor1();
            Reset_Step_count_motor2();
            break;
          }
        }
        else if(Round_count_motor2()>=displacement2)
        {
          Motor2_Stop();
          if(Round_count_motor1()>=displacement2)
          {
            Motor1_Stop();
            Reset_Step_count_motor1();
            Reset_Step_count_motor2();
            break;
          }
        }
      }
    }
    else
    {
      if((displacement1>100)&&(displacement2<=100))
      {
        Serial.println("motor1 displacement error!");
        Motor1_Stop();
        Serial.println("Motor2 needs to move forkward!");
        Motor2_Forward();
        while(1)
        {
          Step_counts_motor2();
          if(Round_count_motor2()>=displacement2)
          {
            Motor2_Stop();
            Reset_Step_count_motor2();
            break;
          }
        }
      }
      else if((displacement1<=100)&&(displacement2>100))
      {
        Serial.println("motor2 displacement error!");
        Motor2_Stop();
        Serial.println("Motor1 needs to move backward!");
        Motor1_Backward();
        while(1)
        {
          Step_counts_motor1();
          if(Round_count_motor1()>=displacement1)
          {
            Motor1_Stop();
            Reset_Step_count_motor1();
            break;
          }
        }
      }
      else
      {
        Serial.println("motor1 displacement error!");
        Serial.println("motor2 displacement error!");
      }
    }
  }

  //motor1 move but motor2 stop
  if((motor_1->distance<motor_1->Record_initial_distance)&&(motor_2->distance==motor_2->Record_initial_distance))
  {
    Serial.println("Motor2 is not need to move!");
    Motor2_Stop();
    displacement1=motor_1->Record_initial_distance-motor_1->distance;
    //Displacement value must be less than 100
    if(displacement1<=100)
    {
      Serial.println("Motor1 needs to move backward!");
      Motor1_Backward();
      while(1)
      {
        Step_counts_motor1();
        if(Round_count_motor1()>=displacement1)
        {
          Motor1_Stop();
          Reset_Step_count_motor1();
          break;
       }
      }
    }
    else
    {
      Serial.println("motor1 displacement error!");
      Motor1_Stop();
    }
  }
  else if((motor_1->distance>motor_1->Record_initial_distance)&&(motor_2->distance==motor_2->Record_initial_distance))
  {
    Serial.println("Motor2 is not need to move!");
    Motor2_Stop();
    displacement1=motor_1->distance-motor_1->Record_initial_distance;
    //Displacement value must be less than 100
    if(displacement1<=100)
    {
      Serial.println("Motor1 needs to move forward!");
      Motor1_Forward();
      while(1)
      {
        Step_counts_motor1();
        if(Round_count_motor1()>=displacement1)
        {
          Motor1_Stop();
          Reset_Step_count_motor1();
          break;
       }
      }
    }
    else
    {
      Serial.println("motor1 displacement error!");
      Motor1_Stop();
    }
  }

  //motor2 move but motor1 stop
  if((motor_1->distance==motor_1->Record_initial_distance)&&(motor_2->distance<motor_2->Record_initial_distance))
  {
    Serial.println("Motor1 is not need to move!");
    Motor1_Stop();
    displacement2=motor_2->Record_initial_distance-motor_2->distance;
    //Displacement value must be less than 100
    if(displacement2<=100)
    {
      Serial.println("Motor2 needs to move backward!");
      Motor2_Backward();
      while(1)
      {
        Step_counts_motor2();
        if(Round_count_motor2()>=displacement2)
        {
          Motor2_Stop();
          Reset_Step_count_motor2();
          break;
       }
      }
    }
    else
    {
      Serial.println("motor2 displacement error!");
      Motor2_Stop();
    }
  }
  else if((motor_1->distance==motor_1->Record_initial_distance)&&(motor_2->distance>motor_2->Record_initial_distance))
  {
    Serial.println("Motor1 is not need to move!");
    Motor1_Stop();
    displacement2=motor_2->distance-motor_2->Record_initial_distance;
    //Displacement value must be less than 100
    if(displacement2<=100)
    {
      Serial.println("Motor2 needs to move forward!");
      Motor2_Forward();
      while(1)
      {
        Step_counts_motor2();
        if(Round_count_motor2()>=displacement2)
        {
          Motor2_Stop();
          Reset_Step_count_motor2();
          break;
       }
      }
    }
    else
    {
      Serial.println("motor2 displacement error!");
      Motor2_Stop();
    }
  }
 }


void loop() 
{
    delay(500);
    calculate_distance();
  
  
}

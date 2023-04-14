#ifndef _GLOBAL_
#define _GLOBAL_

#define ARoundNum 305

//Motor Pins
const int Motor_1_P = 14; //motor1 positive pole
const int Motor_1_N = 15; //motor1 negative pole
const int Motor_2_P = 16; //motor2 positive pole
const int Motor_2_N = 17; //motor2 negative pole
const int Motor_3_P = 18; //motor3 positive pole
const int Motor_3_N = 19; //motor3 negative pole
const int Motor_4_P = 22; //motor4 positive pole
const int Motor_4_N = 23; //motor4 negative pole
const int Motor_5_P = 24; //motor5 positive pole
const int Motor_5_N = 25; //motor5 negative pole
const int Motor_6_P = 26; //motor6 positive pole
const int Motor_6_N = 27; //motor6 negative pole
const int Motor_7_P = 28; //motor7 positive pole
const int Motor_7_N = 29; //motor7 negative pole
const int Motor_8_P = 30; //motor8 positive pole
const int Motor_8_N = 31; //motor8 negative pole
const int Motor_9_P = 32; //motor9 positive pole
const int Motor_9_N = 33; //motor9 negative pole
const int MotorPins[9][2] = {{Motor_1_P, Motor_1_N}, {Motor_2_P, Motor_2_N}, {Motor_3_P, Motor_3_N}, {Motor_4_P, Motor_4_N}, {Motor_5_P, Motor_5_N}, {Motor_6_P, Motor_6_N}, {Motor_7_P, Motor_7_N}, {Motor_8_P, Motor_8_N}, {Motor_9_P, Motor_9_N}};

//Encoder Pins
const int Encoder_1_A = 34;
const int Encoder_1_B = 35;
const int Encoder_2_A = 36;
const int Encoder_2_B = 37;
const int Encoder_3_A = 38;
const int Encoder_3_B = 39;
const int Encoder_4_A = 40;
const int Encoder_4_B = 41;
const int Encoder_5_A = 42;
const int Encoder_5_B = 43;
const int Encoder_6_A = 44;
const int Encoder_6_B = 45;
const int Encoder_7_A = 46;
const int Encoder_7_B = 47;
const int Encoder_8_A = 48;
const int Encoder_8_B = 49;
const int Encoder_9_A = 50;
const int Encoder_9_B = 51;
const int EncoderPins[9][2] = {{Encoder_1_A, Encoder_1_B}, {Encoder_2_A, Encoder_2_B}, {Encoder_3_A, Encoder_3_B}, {Encoder_4_A, Encoder_4_B}, {Encoder_5_A, Encoder_5_B}, {Encoder_6_A, Encoder_6_B}, {Encoder_7_A, Encoder_7_B}, {Encoder_8_A, Encoder_8_B}, {Encoder_9_A, Encoder_9_B}};

//PWM Pins
const int PWM_1 = 2;
const int PWM_2 = 3;
const int PWM_3 = 4;
const int PWM_4 = 5;
const int PWM_5 = 6;
const int PWM_6 = 7;
const int PWM_7 = 8;
const int PWM_8 = 9;

const int PWM_9 = 10;
const int PWMPins[9] = {PWM_1, PWM_2, PWM_3, PWM_4, PWM_5, PWM_6, PWM_7, PWM_8, PWM_9};

//Switch Pins
const int Switch_1 = 52;
const int Switch_2 = 53;
const int Switch_3 = 54;
const int Switch_4 = 55;
const int Switch_5 = 56;
const int Switch_6 = 57;
const int Switch_7 = 58;
const int Switch_8 = 59;
const int Switch_9 = 60;
const int SwitchPins[9] = {Switch_1, Switch_2, Switch_3, Switch_4, Switch_5, Switch_6, Switch_7, Switch_8, Switch_9};

//Pins' Heights
int M1Height = 0;
int M2Height = 0;
int M3Height = 0;
int M4Height = 0;
int M5Height = 0;
int M6Height = 0;
int M7Height = 0;
int M8Height = 0;
int M9Height = 0;
int MotorHeight[9] = {M1Height, M2Height, M3Height, M4Height, M5Height, M6Height, M7Height, M8Height, M9Height};

#endif
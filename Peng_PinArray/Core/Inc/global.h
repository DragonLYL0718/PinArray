#ifndef __CONTROL__
#define __CONTROL__
#include "gpio.h"
extern int ARoundNum;
extern int MachineId;

//Motor Pins
extern GPIO_TypeDef* GPIO_Motor[16][2];
extern uint16_t GPIO_Pin_Motor[16][2];
//Switch(GPIOD) and Encoder(GPIOE,F) Pins 
extern uint16_t GPIO_Pin[16];

#endif
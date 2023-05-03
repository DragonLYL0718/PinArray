#ifndef __CONTROL__
#define __CONTROL__
#include "global.h"
#include "stdbool.h"
#include "stdlib.h"
#include "gpio.h"

extern GPIO_TypeDef* GPIO_Motor[16][2];
extern uint16_t GPIO_Pin_Motor[16][2];
extern uint16_t GPIO_Pin[16];

//Motor
typedef struct motor
{
    int Distance;
    int PrevDistance;
    int CheckState;//false: operating; true: done;
    uint16_t MotorPinPositve;
    uint16_t MotorPinNegative;
    GPIO_TypeDef GPIOPositive;
    GPIO_TypeDef GPIONegative;
    int EncoderValue;
    uint16_t Switch;

    void (*Init)(struct motor *self, GPIO_TypeDef GPIOPositive, GPIO_TypeDef GPIONegative, uint16_t MotorPinPositve, uint16_t MotorPinNegative, uint16_t Switch);
    void (*MoveUp)(struct motor *self);
    void (*MoveDown)(struct motor *self);
    void (*Stop)(struct motor *self);
    bool (*Reset)(struct motor *self);
    void (*StepMove)(struct motor *self);
    void (*Play)(struct motor *self);
}Motor;

extern Motor Motors[16];

void Motor_Init(Motor *Motors);
#endif
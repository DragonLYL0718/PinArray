#include "Control.h"

Motor Motors[16];

void Init(struct motor *self, GPIO_TypeDef GPIOPositive, GPIO_TypeDef GPIONegative, uint16_t MotorPinPositve, uint16_t MotorPinNegative, uint16_t Switch){
    self->GPIOPositive = GPIOPositive;
    self->GPIONegative = GPIONegative;
    self->MotorPinPositve = MotorPinPositve;
    self->MotorPinNegative = MotorPinNegative;
    self->Switch = Switch;
    self->Distance = 0;
    self->PrevDistance = 0;
    self->CheckState = 1;//0: operating; 1: done; 2: reset
    self->EncoderValue = 0;
}

void MoveUp(struct motor *self){
    HAL_GPIO_WritePin(&self->GPIOPositive, self->MotorPinPositve, GPIO_PIN_SET);
    HAL_GPIO_WritePin(&self->GPIONegative, self->MotorPinNegative, GPIO_PIN_RESET);
}

void MoveDown(struct motor *self){
    HAL_GPIO_WritePin(&self->GPIOPositive, self->MotorPinPositve, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(&self->GPIONegative, self->MotorPinNegative, GPIO_PIN_SET);
}

void Stop(struct motor *self){
    HAL_GPIO_WritePin(&self->GPIOPositive, self->MotorPinPositve, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(&self->GPIONegative, self->MotorPinNegative, GPIO_PIN_RESET);
}

bool Reset(struct motor *self){
    if(HAL_GPIO_ReadPin(GPIOD, self->Switch)){
        self->MoveDown(self);
    }
    else{
        self->Stop(self);
        self->Distance = 0;
        self->PrevDistance = 0;
        self->CheckState = 1;
        self->EncoderValue = 0;
    }
    return true;
}

void StepMove(struct motor *self){
    GPIO_PinState SwitchState = HAL_GPIO_ReadPin(GPIOD, self->Switch);
    if(SwitchState == 0 && self->Distance > self->EncoderValue){//Reset the encoder value
        self->EncoderValue = 0;
    }
    if(abs(self->Distance - self->EncoderValue) < 100){
        if(self->Distance > self->EncoderValue){
            self->MoveUp(self);
        }
        else{
            self->MoveDown(self);
        }
    }
    else{
        self->Stop(self);
        self->CheckState = 1;
        self->PrevDistance = self->Distance;
    }
}

void Play(struct motor *self){
    if(self->CheckState == 1 && self->Distance != self->PrevDistance){
        self->CheckState = 0;
    }
    if(self->CheckState == 0){
        self->StepMove(self);
    }
    else if(self->CheckState == 2){
        self->Reset(self);
    }
}

void Motor_Init(Motor *Motors){
    for(int i = 0; i < 16; i++){
        Motors[i].Init = Init;
        Motors[i].MoveUp = MoveUp;
        Motors[i].MoveDown = MoveDown;
        Motors[i].Stop = Stop;
        Motors[i].Reset = Reset;
        Motors[i].StepMove = StepMove;
        Motors[i].Play = Play;
        Motors[i].Init(&Motors[i], *GPIO_Motor[i][0], *GPIO_Motor[i][1], GPIO_Pin_Motor[i][0], GPIO_Pin_Motor[i][1], GPIO_Pin[i]);
    }
}
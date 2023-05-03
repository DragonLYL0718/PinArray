#include "global.h"

int ARoundNum = 305;
int MachineId = 1;

GPIO_TypeDef* GPIO_Motor[16][2] = { {GPIOA, GPIOA},
                                    {GPIOA, GPIOA},
                                    {GPIOA, GPIOA},
                                    {GPIOA, GPIOA},
                                    {GPIOA, GPIOA},
                                    {GPIOA, GPIOA},
                                    {GPIOA, GPIOA},
                                    {GPIOB, GPIOB},
                                    {GPIOB, GPIOB},
                                    {GPIOB, GPIOB},
                                    {GPIOB, GPIOB},
                                    {GPIOB, GPIOB},
                                    {GPIOB, GPIOB},
                                    {GPIOB, GPIOB},
                                    {GPIOC, GPIOC},
                                    {GPIOC, GPIOC}};
uint16_t GPIO_Pin_Motor[16][2] = {  {GPIO_PIN_0, GPIO_PIN_1},
                                    {GPIO_PIN_2, GPIO_PIN_3},
                                    {GPIO_PIN_4, GPIO_PIN_5},
                                    {GPIO_PIN_6, GPIO_PIN_7},
                                    {GPIO_PIN_8, GPIO_PIN_11},
                                    {GPIO_PIN_12, GPIO_PIN_13},
                                    {GPIO_PIN_14, GPIO_PIN_15},
                                    {GPIO_PIN_0, GPIO_PIN_1},
                                    {GPIO_PIN_2, GPIO_PIN_3},
                                    {GPIO_PIN_4, GPIO_PIN_5},
                                    {GPIO_PIN_8, GPIO_PIN_9},
                                    {GPIO_PIN_10, GPIO_PIN_11},
                                    {GPIO_PIN_12, GPIO_PIN_13},
                                    {GPIO_PIN_14, GPIO_PIN_15},
                                    {GPIO_PIN_0, GPIO_PIN_1},
                                    {GPIO_PIN_2, GPIO_PIN_3}};
//Switch(GPIOD) and Encoder(GPIOE,F) Pins 
uint16_t GPIO_Pin[16] = {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3,
                                GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7,
                                GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10, GPIO_PIN_11,
                                GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15};
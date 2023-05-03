#ifndef __COMMUNICATION__
#define __COMMUNICATION__

#include "usart.h"
#include "cJSON.h"
#include "Control.h"
#include "global.h"
#include "string.h"

extern int MachineId;
extern Motor Motors[16];

#define RX_BUFFER_SIZE 256
extern uint8_t RxBuffer[RX_BUFFER_SIZE];
extern uint8_t RxData;
extern uint16_t RxIndex;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void parseData(char *data, int Length);

#endif
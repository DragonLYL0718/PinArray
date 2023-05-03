#include "Communication.h"

uint8_t RxBuffer[RX_BUFFER_SIZE];
uint8_t RxData = 0;
uint16_t RxIndex = 0;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
    if(huart->Instance == USART1){
        if(RxData != '\n' && RxIndex < RX_BUFFER_SIZE -1){
            RxBuffer[RxIndex++] = RxData;
        }
        else{
            RxBuffer[RxIndex] = '\0';
            parseData((char *)RxBuffer, RxIndex);
						RxIndex = 0;
        }
        HAL_UART_Receive_IT(huart, (uint8_t *)&RxData, 1);
    }
}

void parseData(char *data, int Length) {
    cJSON *json = cJSON_ParseWithLength(data, Length);
//    cJSON *json = cJSON_Parse(data);
    if (json == NULL) {
//        printf("Error parsing JSON data\n");
    }
    cJSON *machine =  cJSON_GetObjectItem(json, "i");
    if(machine->valueint == MachineId){
        cJSON_Delete(machine);
        cJSON *state = cJSON_GetObjectItem(json, "c");
        if(strcmp(state->valuestring, "motor") == 0){
            cJSON *DistanceArray = cJSON_GetObjectItem(json, "d");
            for(int i = 0; i < 16; i++){
                cJSON *Distance = cJSON_GetArrayItem(DistanceArray, i);
                Motors[i].Distance = Distance->valueint;
                cJSON_Delete(Distance);
            }
            cJSON_Delete(DistanceArray);
        }
        else if(strcmp(state->valuestring, "reset") == 0){
            for(int i = 0; i < 16; i++){
                Motors[i].CheckState = 2;
            }
        }
        cJSON_Delete(state);
    }

    cJSON_Delete(json);
}

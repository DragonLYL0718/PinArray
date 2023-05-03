/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define EncoderB_Pin GPIO_PIN_2
#define EncoderB_GPIO_Port GPIOE
#define EncoderBE3_Pin GPIO_PIN_3
#define EncoderBE3_GPIO_Port GPIOE
#define EncoderBE4_Pin GPIO_PIN_4
#define EncoderBE4_GPIO_Port GPIOE
#define EncoderBE5_Pin GPIO_PIN_5
#define EncoderBE5_GPIO_Port GPIOE
#define EncoderBE6_Pin GPIO_PIN_6
#define EncoderBE6_GPIO_Port GPIOE
#define EncoderA_Pin GPIO_PIN_0
#define EncoderA_GPIO_Port GPIOF
#define EncoderA_EXTI_IRQn EXTI0_IRQn
#define EncoderAF1_Pin GPIO_PIN_1
#define EncoderAF1_GPIO_Port GPIOF
#define EncoderAF1_EXTI_IRQn EXTI1_IRQn
#define EncoderAF2_Pin GPIO_PIN_2
#define EncoderAF2_GPIO_Port GPIOF
#define EncoderAF2_EXTI_IRQn EXTI2_IRQn
#define EncoderAF3_Pin GPIO_PIN_3
#define EncoderAF3_GPIO_Port GPIOF
#define EncoderAF3_EXTI_IRQn EXTI3_IRQn
#define EncoderAF4_Pin GPIO_PIN_4
#define EncoderAF4_GPIO_Port GPIOF
#define EncoderAF4_EXTI_IRQn EXTI4_IRQn
#define EncoderAF5_Pin GPIO_PIN_5
#define EncoderAF5_GPIO_Port GPIOF
#define EncoderAF5_EXTI_IRQn EXTI9_5_IRQn
#define EncoderAF6_Pin GPIO_PIN_6
#define EncoderAF6_GPIO_Port GPIOF
#define EncoderAF6_EXTI_IRQn EXTI9_5_IRQn
#define EncoderAF7_Pin GPIO_PIN_7
#define EncoderAF7_GPIO_Port GPIOF
#define EncoderAF7_EXTI_IRQn EXTI9_5_IRQn
#define EncoderAF8_Pin GPIO_PIN_8
#define EncoderAF8_GPIO_Port GPIOF
#define EncoderAF8_EXTI_IRQn EXTI9_5_IRQn
#define EncoderAF9_Pin GPIO_PIN_9
#define EncoderAF9_GPIO_Port GPIOF
#define EncoderAF9_EXTI_IRQn EXTI9_5_IRQn
#define EncoderAF10_Pin GPIO_PIN_10
#define EncoderAF10_GPIO_Port GPIOF
#define EncoderAF10_EXTI_IRQn EXTI15_10_IRQn
#define Motor_Pin GPIO_PIN_0
#define Motor_GPIO_Port GPIOC
#define MotorC1_Pin GPIO_PIN_1
#define MotorC1_GPIO_Port GPIOC
#define MotorC2_Pin GPIO_PIN_2
#define MotorC2_GPIO_Port GPIOC
#define MotorC3_Pin GPIO_PIN_3
#define MotorC3_GPIO_Port GPIOC
#define MotorA0_Pin GPIO_PIN_0
#define MotorA0_GPIO_Port GPIOA
#define MotorA1_Pin GPIO_PIN_1
#define MotorA1_GPIO_Port GPIOA
#define MotorA2_Pin GPIO_PIN_2
#define MotorA2_GPIO_Port GPIOA
#define MotorA3_Pin GPIO_PIN_3
#define MotorA3_GPIO_Port GPIOA
#define MotorA4_Pin GPIO_PIN_4
#define MotorA4_GPIO_Port GPIOA
#define MotorA5_Pin GPIO_PIN_5
#define MotorA5_GPIO_Port GPIOA
#define MotorA6_Pin GPIO_PIN_6
#define MotorA6_GPIO_Port GPIOA
#define MotorA7_Pin GPIO_PIN_7
#define MotorA7_GPIO_Port GPIOA
#define MotorB0_Pin GPIO_PIN_0
#define MotorB0_GPIO_Port GPIOB
#define MotorB1_Pin GPIO_PIN_1
#define MotorB1_GPIO_Port GPIOB
#define MotorB2_Pin GPIO_PIN_2
#define MotorB2_GPIO_Port GPIOB
#define EncoderAF11_Pin GPIO_PIN_11
#define EncoderAF11_GPIO_Port GPIOF
#define EncoderAF11_EXTI_IRQn EXTI15_10_IRQn
#define EncoderAF12_Pin GPIO_PIN_12
#define EncoderAF12_GPIO_Port GPIOF
#define EncoderAF12_EXTI_IRQn EXTI15_10_IRQn
#define EncoderAF13_Pin GPIO_PIN_13
#define EncoderAF13_GPIO_Port GPIOF
#define EncoderAF13_EXTI_IRQn EXTI15_10_IRQn
#define EncoderAF14_Pin GPIO_PIN_14
#define EncoderAF14_GPIO_Port GPIOF
#define EncoderAF14_EXTI_IRQn EXTI15_10_IRQn
#define EncoderAF15_Pin GPIO_PIN_15
#define EncoderAF15_GPIO_Port GPIOF
#define EncoderAF15_EXTI_IRQn EXTI15_10_IRQn
#define EncoderBE7_Pin GPIO_PIN_7
#define EncoderBE7_GPIO_Port GPIOE
#define EncoderBE8_Pin GPIO_PIN_8
#define EncoderBE8_GPIO_Port GPIOE
#define EncoderBE9_Pin GPIO_PIN_9
#define EncoderBE9_GPIO_Port GPIOE
#define EncoderBE10_Pin GPIO_PIN_10
#define EncoderBE10_GPIO_Port GPIOE
#define EncoderBE11_Pin GPIO_PIN_11
#define EncoderBE11_GPIO_Port GPIOE
#define EncoderBE12_Pin GPIO_PIN_12
#define EncoderBE12_GPIO_Port GPIOE
#define EncoderBE13_Pin GPIO_PIN_13
#define EncoderBE13_GPIO_Port GPIOE
#define EncoderBE14_Pin GPIO_PIN_14
#define EncoderBE14_GPIO_Port GPIOE
#define EncoderBE15_Pin GPIO_PIN_15
#define EncoderBE15_GPIO_Port GPIOE
#define MotorB10_Pin GPIO_PIN_10
#define MotorB10_GPIO_Port GPIOB
#define MotorB11_Pin GPIO_PIN_11
#define MotorB11_GPIO_Port GPIOB
#define MotorB12_Pin GPIO_PIN_12
#define MotorB12_GPIO_Port GPIOB
#define MotorB13_Pin GPIO_PIN_13
#define MotorB13_GPIO_Port GPIOB
#define MotorB14_Pin GPIO_PIN_14
#define MotorB14_GPIO_Port GPIOB
#define MotorB15_Pin GPIO_PIN_15
#define MotorB15_GPIO_Port GPIOB
#define Switch_Pin GPIO_PIN_8
#define Switch_GPIO_Port GPIOD
#define SwitchD9_Pin GPIO_PIN_9
#define SwitchD9_GPIO_Port GPIOD
#define SwitchD10_Pin GPIO_PIN_10
#define SwitchD10_GPIO_Port GPIOD
#define SwitchD11_Pin GPIO_PIN_11
#define SwitchD11_GPIO_Port GPIOD
#define SwitchD12_Pin GPIO_PIN_12
#define SwitchD12_GPIO_Port GPIOD
#define SwitchD13_Pin GPIO_PIN_13
#define SwitchD13_GPIO_Port GPIOD
#define SwitchD14_Pin GPIO_PIN_14
#define SwitchD14_GPIO_Port GPIOD
#define SwitchD15_Pin GPIO_PIN_15
#define SwitchD15_GPIO_Port GPIOD
#define MotorA8_Pin GPIO_PIN_8
#define MotorA8_GPIO_Port GPIOA
#define MotorA11_Pin GPIO_PIN_11
#define MotorA11_GPIO_Port GPIOA
#define MotorA12_Pin GPIO_PIN_12
#define MotorA12_GPIO_Port GPIOA
#define MotorA13_Pin GPIO_PIN_13
#define MotorA13_GPIO_Port GPIOA
#define MotorA14_Pin GPIO_PIN_14
#define MotorA14_GPIO_Port GPIOA
#define MotorA15_Pin GPIO_PIN_15
#define MotorA15_GPIO_Port GPIOA
#define SwitchD0_Pin GPIO_PIN_0
#define SwitchD0_GPIO_Port GPIOD
#define SwitchD1_Pin GPIO_PIN_1
#define SwitchD1_GPIO_Port GPIOD
#define SwitchD2_Pin GPIO_PIN_2
#define SwitchD2_GPIO_Port GPIOD
#define SwitchD3_Pin GPIO_PIN_3
#define SwitchD3_GPIO_Port GPIOD
#define SwitchD4_Pin GPIO_PIN_4
#define SwitchD4_GPIO_Port GPIOD
#define SwitchD5_Pin GPIO_PIN_5
#define SwitchD5_GPIO_Port GPIOD
#define SwitchD6_Pin GPIO_PIN_6
#define SwitchD6_GPIO_Port GPIOD
#define SwitchD7_Pin GPIO_PIN_7
#define SwitchD7_GPIO_Port GPIOD
#define MotorB3_Pin GPIO_PIN_3
#define MotorB3_GPIO_Port GPIOB
#define MotorB4_Pin GPIO_PIN_4
#define MotorB4_GPIO_Port GPIOB
#define MotorB5_Pin GPIO_PIN_5
#define MotorB5_GPIO_Port GPIOB
#define MotorB8_Pin GPIO_PIN_8
#define MotorB8_GPIO_Port GPIOB
#define MotorB9_Pin GPIO_PIN_9
#define MotorB9_GPIO_Port GPIOB
#define EncoderBE0_Pin GPIO_PIN_0
#define EncoderBE0_GPIO_Port GPIOE
#define EncoderBE1_Pin GPIO_PIN_1
#define EncoderBE1_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

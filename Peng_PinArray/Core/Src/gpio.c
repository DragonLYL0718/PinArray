/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, Motor_Pin|MotorC1_Pin|MotorC2_Pin|MotorC3_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, MotorA0_Pin|MotorA1_Pin|MotorA2_Pin|MotorA3_Pin
                          |MotorA4_Pin|MotorA5_Pin|MotorA6_Pin|MotorA7_Pin
                          |MotorA8_Pin|MotorA11_Pin|MotorA12_Pin|MotorA13_Pin
                          |MotorA14_Pin|MotorA15_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, MotorB0_Pin|MotorB1_Pin|MotorB2_Pin|MotorB10_Pin
                          |MotorB11_Pin|MotorB12_Pin|MotorB13_Pin|MotorB14_Pin
                          |MotorB15_Pin|MotorB3_Pin|MotorB4_Pin|MotorB5_Pin
                          |MotorB8_Pin|MotorB9_Pin, GPIO_PIN_SET);

  /*Configure GPIO pins : PEPin PEPin PEPin PEPin
                           PEPin PEPin PEPin PEPin
                           PEPin PEPin PEPin PEPin
                           PEPin PEPin PEPin PEPin */
  GPIO_InitStruct.Pin = EncoderB_Pin|EncoderBE3_Pin|EncoderBE4_Pin|EncoderBE5_Pin
                          |EncoderBE6_Pin|EncoderBE7_Pin|EncoderBE8_Pin|EncoderBE9_Pin
                          |EncoderBE10_Pin|EncoderBE11_Pin|EncoderBE12_Pin|EncoderBE13_Pin
                          |EncoderBE14_Pin|EncoderBE15_Pin|EncoderBE0_Pin|EncoderBE1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PFPin PFPin PFPin PFPin
                           PFPin PFPin PFPin PFPin
                           PFPin PFPin PFPin PFPin
                           PFPin PFPin PFPin PFPin */
  GPIO_InitStruct.Pin = EncoderA_Pin|EncoderAF1_Pin|EncoderAF2_Pin|EncoderAF3_Pin
                          |EncoderAF4_Pin|EncoderAF5_Pin|EncoderAF6_Pin|EncoderAF7_Pin
                          |EncoderAF8_Pin|EncoderAF9_Pin|EncoderAF10_Pin|EncoderAF11_Pin
                          |EncoderAF12_Pin|EncoderAF13_Pin|EncoderAF14_Pin|EncoderAF15_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : PCPin PCPin PCPin PCPin */
  GPIO_InitStruct.Pin = Motor_Pin|MotorC1_Pin|MotorC2_Pin|MotorC3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin PAPin PAPin
                           PAPin PAPin PAPin PAPin
                           PAPin PAPin PAPin PAPin
                           PAPin PAPin */
  GPIO_InitStruct.Pin = MotorA0_Pin|MotorA1_Pin|MotorA2_Pin|MotorA3_Pin
                          |MotorA4_Pin|MotorA5_Pin|MotorA6_Pin|MotorA7_Pin
                          |MotorA8_Pin|MotorA11_Pin|MotorA12_Pin|MotorA13_Pin
                          |MotorA14_Pin|MotorA15_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin
                           PBPin PBPin PBPin PBPin
                           PBPin PBPin PBPin PBPin
                           PBPin PBPin */
  GPIO_InitStruct.Pin = MotorB0_Pin|MotorB1_Pin|MotorB2_Pin|MotorB10_Pin
                          |MotorB11_Pin|MotorB12_Pin|MotorB13_Pin|MotorB14_Pin
                          |MotorB15_Pin|MotorB3_Pin|MotorB4_Pin|MotorB5_Pin
                          |MotorB8_Pin|MotorB9_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PDPin PDPin PDPin PDPin
                           PDPin PDPin PDPin PDPin
                           PDPin PDPin PDPin PDPin
                           PDPin PDPin PDPin PDPin */
  GPIO_InitStruct.Pin = Switch_Pin|SwitchD9_Pin|SwitchD10_Pin|SwitchD11_Pin
                          |SwitchD12_Pin|SwitchD13_Pin|SwitchD14_Pin|SwitchD15_Pin
                          |SwitchD0_Pin|SwitchD1_Pin|SwitchD2_Pin|SwitchD3_Pin
                          |SwitchD4_Pin|SwitchD5_Pin|SwitchD6_Pin|SwitchD7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

  HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);

  HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI3_IRQn);

  HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */

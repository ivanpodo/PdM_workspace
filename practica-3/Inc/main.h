/**
 ******************************************************************************
 * @file    PdM_workspace/practica-3/Inc/main.h
 * @author  Iván Podoroska
 * @brief   This program is a solution to practice 3 of the
 * Microcontroller Programming Course.
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "stm32f4xx_hal.h"        /* <- HAL include */
#include "stm32f4xx_nucleo_144.h" /* <- BSP include */

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
/* User can use this section to tailor USARTx/UARTx instance used and associated
   resources */
/* Definition for USARTx clock resources */
#define USARTx USART3
#define USARTx_CLK_ENABLE()         __HAL_RCC_USART3_CLK_ENABLE();
#define USARTx_RX_GPIO_CLK_ENABLE() __HAL_RCC_GPIOD_CLK_ENABLE()
#define USARTx_TX_GPIO_CLK_ENABLE() __HAL_RCC_GPIOD_CLK_ENABLE()

#define USARTx_FORCE_RESET()     __HAL_RCC_USART3_FORCE_RESET()
#define USARTx_RELEASE_RESET()   __HAL_RCC_USART3_RELEASE_RESET()

/* Definition for USARTx Pins */
#define USARTx_TX_PIN         GPIO_PIN_8
#define USARTx_TX_GPIO_PORT   GPIOD
#define USARTx_TX_AF          GPIO_AF7_USART3
#define USARTx_RX_PIN         GPIO_PIN_9
#define USARTx_RX_GPIO_PORT   GPIOD
#define USARTx_RX_AF          GPIO_AF7_USART3

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

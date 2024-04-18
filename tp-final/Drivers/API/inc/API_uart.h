/**
 ******************************************************************************
 * @file    Driver/API/inc/API_uart.h
 * @author  Iván Podoroska
 * @brief   Implementation of uart API
 ******************************************************************************
 */

#ifndef API_UART_H
#define API_UART_H

#include "API_common.h"

#define UART_BAUDRATE   115200  /**< UART BAUDRATE                  */
#define UART_MAX_CHAR   250     /**< Upper limit for uartSendString */
#define UART_TIMEOUT    100     /**< UART timeout in [ms]           */

void uartReceiveStringSize(uint8_t * pString, uint16_t size);
void uartSendStringSize(uint8_t * pString, uint16_t size);
void uartSendString(uint8_t * pString);
bool_t uartInit();

#endif

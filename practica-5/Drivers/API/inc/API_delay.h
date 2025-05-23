/**
 ******************************************************************************
 * @file    Driver/API/inc/API_delay.h
 * @author  Iván Podoroska
 * @brief   Implementation of non-blocking delay
 ******************************************************************************
 */

#ifndef API_DELAYS_H
#define API_DELAYS_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint32_t tick_t;
typedef bool bool_t;

typedef struct
{
   tick_t startTime;
   tick_t duration;
   bool_t running;
} delay_t;


void delayInit(delay_t *delay, tick_t duration);
bool_t delayRead(delay_t *delay);
void delayWrite(delay_t *delay, tick_t duration);

#endif

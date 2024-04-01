/**
 ******************************************************************************
 * @file    Driver/API/inc/API_deounce.h
 * @author  Iván Podoroska
 * @brief   Implementation of Finite State Machine  FSM to perform a software 
 *          debounce of a GPIO
 ******************************************************************************
 */

#ifndef API_DEBOUNCE_H
#define API_DEBOUNCE_H

#include <stddef.h>
#include <stdint.h>
#include "stm32f4xx_nucleo_144.h"
#include "API_delay.h"

/**
 * @brief Sets debounce time for button press/release events.
 * 
 * This macro specifies the debounce interval, key for accurate readings of
 * button states. It effectively filters out noise during state transitions, 
 * stabilizing the signals received.
 *
 * @note Set at 40 milliseconds, this duration balances quick response with
 * efficient noise filtering. Adjust based on application needs and button
 * characteristics.
 */
#define DEBOUNCE_TIME	40U	 // Debounce time in milliseconds


void debounceFSM_init();
void debounceFSM_update();
bool_t readKey();

#endif

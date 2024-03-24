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

/**
 * @brief   Initializes the debounce Finite State Machine (FSM) to its starting
 * 		    state. This function sets the internal state of the FSM to the 
 *          initial state, preparing it for operation and state tracking.
 */
void debounceFSM_init();

/**
 * @brief   Updates the Finite State Machine (FSM) based on the state of 
 * 		    BUTTON_USER. This function reads the current state of BUTTON_USER 
 *          and adjusts the FSM to reflect any changes, ensuring that button 
 * 		    debouncing is handled properly.
 */
void debounceFSM_update();

/**
 * @brief   Reads the state of a key and determines if it has been pressed.
 *          This function is responsible for checking the current state of an 
 *          internal module variable, which represents whether a specific key 
 *          has been pressed. Upon invocation, it reads this variable and  
 *          outputs a boolean value: true or false.
 * @return  bool_t Returns true if the key has been pressed since the last time
 *          it was checked. Otherwise, returns false.
 */
bool_t readKey();

#endif

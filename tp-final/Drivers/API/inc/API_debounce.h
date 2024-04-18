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

#include "debounce_port.h"
#include "API_common.h"
#include "API_delay.h"

/**
 * @brief Sets debounce time for button press/release events.
 * 
 * This macro specifies the debounce interval, key for accurate readings of
 * button states. It effectively filters out noise during state transitions, 
 * stabilizing the signals received.
 *
 * @note Set at 10 milliseconds, this duration balances quick response with
 * efficient noise filtering. Adjust based on application needs and button
 * characteristics.
 */
#define DEBOUNCE_TIME	10U	 // Debounce time in milliseconds

typedef enum{
	BUTTON_UP,
	BUTTON_FALLING,
	BUTTON_DOWN,
	BUTTON_RAISING,
} debounceState_t;

typedef struct
{
    gpio_t          *gpio_;            
    delay_t         *delay_;         
    debounceState_t state_;
    debounceState_t validState_;     
    bool            isButtonPressed_;
    bool            isInit;          
} stDebounce;

void DBN_FSMinit(stDebounce *button, gpio_t *pin, delay_t *delay);
void DBN_FSMupdate(stDebounce *button);
bool_t DBN_readKey(stDebounce *button);
debounceState_t DBN_getState(stDebounce *button);

#endif

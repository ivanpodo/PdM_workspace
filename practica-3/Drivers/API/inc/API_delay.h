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

/**
 * @brief Initializes a Delay instance without starting its execution
 * 
 * @param delay Pointer to a delay instance to be initialized. Must not be NULL
 * @param duration Delay duration in ticks. This duration determines the time 
 * that must elapse before the Delay instance is considered
 * complete or expired, once it has been started.
 */
void delayInit(delay_t *delay, tick_t duration);

/**
 * @brief Checks the status of a Delay instance, starting its timing on the 
 * first call. On subsequent calls, it checks if the delay duration has elapsed.
 * 
 * @param delay Pointer to the Delay instance to be checked. This instance 
 * should have been previously initialized with delayInit().
 * @return Returns true if the delay duration has elapsed (time is up), 
 * indicating that the delay period is complete. Returns false if the delay is 
 * still running (time has not yet fully elapsed).
 */
bool_t delayRead(delay_t *delay);

/**
 * @brief Updates the duration of an existing Delay instance. It can be used to
 *  adjust the timing dynamically without needing to reinitialize the delay. 
 * The change takes effect immediately and will affect the timing on the next 
 * call to delayRead().
 * 
 * @param delay Pointer to the Delay instance whose duration is to be changed.
 * @param duration The new duration for the delay, in ticks. This value must be 
 * greater than 0.
 */
void delayWrite(delay_t *delay, tick_t duration);

#endif

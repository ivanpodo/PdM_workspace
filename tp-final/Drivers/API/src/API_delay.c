#include "API_delay.h"
#include "stm32f4xx_hal.h"

static void Error_Handler(void);

/**
 * @brief Initializes a Delay instance without starting its execution
 * 
 * @param delay Pointer to a delay instance to be initialized. Must not be NULL
 * @param duration Delay duration in ticks. This duration determines the time 
 * that must elapse before the Delay instance is considered
 * complete or expired, once it has been started.
 */
void delayInit(delay_t *delay, tick_t duration)
{
   if (delay == NULL || duration == 0U) // Fault check
   {
      Error_Handler();
   }

   delay->duration = duration;
   delay->running  = false;
}

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
bool_t delayRead(delay_t *delay)
{
   bool_t _ret = false;

   if (delay == NULL) // Fault check
   {
      Error_Handler();
   }

   tick_t currentTime = HAL_GetTick();

   if (delay->running)
   {
      if (currentTime - delay->startTime >= delay->duration)
      {
         delay->running = false;
         _ret = true;
      }      
   }
   else
   {
      delay->startTime = currentTime;
      delay->running   = true;
   }

   return _ret;         
}

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
void delayWrite(delay_t *delay, tick_t duration)
{
   if (delay == NULL || duration == 0U) // Fault check
   {
      Error_Handler();
   }

   delay->duration = duration;      
}

/**
 * @brief Error handler function.
 *
 * This function is called when an unrecoverable error occurs.
 */
static void Error_Handler(void)
{
	while (1)
	{
	}
}
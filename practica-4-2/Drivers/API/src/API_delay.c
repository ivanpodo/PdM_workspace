#include "API_delay.h"
#include "stm32f4xx_hal.h"

static void Error_Handler(void);
static void Error_Handler(void)
{
	while (1)
	{
	}
}

void delayInit(delay_t *delay, tick_t duration)
{
   if (delay == NULL || duration == 0U) // Fault check
   {
      Error_Handler();
   }

   delay->duration = duration;
   delay->running  = false;
}

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

void delayWrite(delay_t *delay, tick_t duration)
{
   if (delay == NULL || duration == 0U) // Fault check
   {
      Error_Handler();
   }

   delay->duration = duration;      
}

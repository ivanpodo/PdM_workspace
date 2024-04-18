#ifndef API_I2C
#define API_I2C

#include "stm32f4xx_hal.h"  	
#include "stm32f4xx_nucleo_144.h" 
#include "API_common.h"

#define I2C_CLOCK_RATE 100000

bool_t I2C_HW_init(void);

#endif
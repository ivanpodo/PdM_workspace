#ifndef DEBOUNCE_PORT_H
#define DEBOUNCE_PORT_H

#include "stm32f4xx_hal.h"
#include "stm32f4xx_nucleo_144.h"
#include "API_common_port.h"

pin_state_t Port_ReadPin(port_t GPIOx, pin_t GPIO_Pin);

#endif
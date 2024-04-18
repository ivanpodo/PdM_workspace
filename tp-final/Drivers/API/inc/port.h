#ifndef PORT_H
#define PORT_H

#include "API_common_port.h"
#include <stdbool.h>

void Port_Delay(uint32_t delayTime);
pin_state_t Port_ReadPin(port_t GPIOx, pin_t GPIO_Pin);

#endif
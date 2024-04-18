#ifndef LCD_PORT_H
#define LCD_PORT_H

#include "API_common_port.h"
#include <stdbool.h>

void Port_WriteByte(uint8_t valor);
void Port_Delay(uint32_t delayTime);

#endif
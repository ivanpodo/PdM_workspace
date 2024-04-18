#include "debounce_port.h"

pin_state_t Port_ReadPin(port_t port, pin_t pin)
{
    return HAL_GPIO_ReadPin(port, pin);
}
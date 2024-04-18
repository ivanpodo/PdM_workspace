#ifndef API_ENCODER_H
#define API_ENCODER_H

#include "API_common.h"
#include "API_debounce.h"

typedef enum
{
    CounterCW,  /**< Counter ClockWise */
    CW,         /**< ClockWise */
    INVALID
} eMovingDir;

void ENC_encoderInit();
void ENC_encoderUpdate();
bool_t ENC_setGPIOs(gpio_t *dt, gpio_t *clk);
eMovingDir ENC_getDirection();

#endif
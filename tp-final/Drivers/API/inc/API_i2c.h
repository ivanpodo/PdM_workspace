#ifndef API_I2C
#define API_I2C

#include "API_common.h"

#define I2C_OK    0
#define I2C_ERROR 1

#define I2C_CLOCK_RATE 100000
#define I2C_TIMEOUT    5000

bool_t I2C_HW_init(void);
bool_t I2C_Send(uint16_t address, uint8_t *ptrData, uint16_t size);
bool_t I2C_Receive(uint16_t address, uint8_t *ptrData, uint16_t size);
bool_t isInit();

#endif
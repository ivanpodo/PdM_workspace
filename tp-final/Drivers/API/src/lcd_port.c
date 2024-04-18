#include "lcd_port.h"

extern I2C_HandleTypeDef hi2c1;

static void Error_Handler();

void Port_WriteByte(uint8_t valor)
{
	if(HAL_I2C_Master_Transmit(&hi2c1, 0x27<<1, &valor, sizeof(valor), HAL_MAX_DELAY) != HAL_OK)
    {
        Error_Handler();
    }
}

void Port_Delay(uint32_t delayTime)
{
    HAL_Delay(delayTime);
}

static void Error_Handler()
{
    BSP_LED_On(LED2);
    while (1)
    {}
}


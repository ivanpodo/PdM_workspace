/**
 * @file API_i2c.h
 * @brief I2C interface library for STM32 microcontrollers.
 */

#include "API_i2c.h"


I2C_HandleTypeDef hi2c1;

static bool_t isInit_ = false;

static void GPIO_I2C(I2C_HandleTypeDef *hi2c);

/**
 * @brief Initializes the I2C hardware with predefined settings.
 * @return Returns HAL_OK if successful, HAL_ERROR otherwise.
 */
bool_t I2C_HW_init(void)
{
	if (isInit_)
	{
		return HAL_OK;
	}
	
	hi2c1.Instance 			   = I2C1;
	hi2c1.Init.ClockSpeed 	   = I2C_CLOCK_RATE;
	hi2c1.Init.DutyCycle 	   = I2C_DUTYCYCLE_2;
	hi2c1.Init.OwnAddress1 	   = 0;
	hi2c1.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
	hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c1.Init.OwnAddress2 	   = 0;
	hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c1.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLE;
	GPIO_I2C(&hi2c1);

	if (HAL_I2C_Init(&hi2c1) != HAL_OK)
	{
		return HAL_ERROR;
	}

	isInit_ = true;
	return HAL_OK;
}

/**
 * @brief Sends data over the I2C bus to a specified slave device.
 * @param address The address of the slave device.
 * @param ptrData Pointer to the data buffer to transmit.
 * @param size Number of bytes to transmit.
 * @return true if successful, false otherwise.
 */
bool_t I2C_Send(uint16_t address, uint8_t *ptrData, uint16_t size)
{
	if(HAL_I2C_Master_Transmit(&hi2c1, address, ptrData, size, I2C_TIMEOUT) != HAL_OK)
	{
		return false;
	}
	return true;
}

/**
 * @brief Receives data from a specified slave device over the I2C bus.
 * @param address The address of the slave device.
 * @param ptrData Pointer to the buffer to store received data.
 * @param size Number of bytes to receive.
 * @return true if successful, false otherwise.
 */
bool_t I2C_Receive(uint16_t address, uint8_t *ptrData, uint16_t size)
{
	if (HAL_I2C_Master_Receive(&hi2c1, address, ptrData, sizeof(ptrData), I2C_TIMEOUT) != HAL_OK)
	{
		return false;
	}
	return true;
}

/**
 * @brief Checks if the I2C interface has been initialized.
 * @return true if I2C is initialized, false otherwise.
 */
bool_t isInit()
{
	return isInit_;
}

/**
 * @brief Configures GPIO for I2C communication.
 * @param hi2c Pointer to the I2C_HandleTypeDef structure that contains the configuration information for I2C module.
 */
static void GPIO_I2C(I2C_HandleTypeDef *hi2c)
{
	 GPIO_InitTypeDef GPIO_InitStruct;

	  /* GPIO Ports Clock Enable */
	  __HAL_RCC_GPIOB_CLK_ENABLE();

	  GPIO_InitStruct.Pin 		= GPIO_PIN_8|GPIO_PIN_9;
	  GPIO_InitStruct.Mode 		= GPIO_MODE_AF_OD;
	  GPIO_InitStruct.Pull 		= GPIO_NOPULL;
	  GPIO_InitStruct.Speed 	= GPIO_SPEED_FREQ_LOW;
	  GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;

	  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	     /* Peripheral clock enable */
	  __HAL_RCC_I2C1_CLK_ENABLE();
}

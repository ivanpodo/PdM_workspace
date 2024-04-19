# API_i2c.h Library Documentation

## Overview

This library provides an interface for I2C communication on STM32 microcontrollers, allowing for initial configuration, sending, and receiving data over the I2C bus. It utilizes the HAL library functions for I2C, which simplifies the management of hardware interactions.

## Functions

### `bool_t I2C_HW_init(void)`

Initializes the I2C hardware with predefined settings. This function configures the I2C with a specific clock rate, duty cycle, addressing mode, and GPIO settings necessary for operation. It should be called before any other I2C operations.

Returns:
- `HAL_OK` if initialization was successful.
- `HAL_ERROR` if there was an error during initialization.

### `bool_t I2C_Send(uint16_t address, uint8_t *ptrData, uint16_t size)`

Sends data over the I2C bus to a specified slave device.

Parameters:
- `address`: The address of the slave device.
- `ptrData`: Pointer to the data buffer to be transmitted.
- `size`: Number of bytes to transmit.

Returns:
- `true` if the data was successfully sent.
- `false` otherwise.

### `bool_t I2C_Receive(uint16_t address, uint8_t *ptrData, uint16_t size)`

Receives data over the I2C bus from a specified slave device.

Parameters:
- `address`: The address of the slave device.
- `ptrData`: Pointer to the buffer where received data will be stored.
- `size`: Number of bytes to receive.

Returns:
- `true` if the data was successfully received.
- `false` otherwise.

### `bool_t isInit()`

Checks if the I2C interface has been successfully initialized.

Returns:
- `true` if the I2C interface is initialized.
- `false` otherwise.

## GPIO Configuration

The library configures GPIO pins for I2C communication. Specific pins (e.g., PB8 and PB9) are set to alternate function, open-drain mode suitable for I2C.

## Notes

- Ensure that the I2C bus is not busy before initiating any communication.
- Handle the return values of each function to ensure robust error management in your application.

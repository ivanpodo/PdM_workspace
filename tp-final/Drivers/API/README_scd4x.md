# API_scd4x Library Documentation

## Overview

This library facilitates communication with the SCD4x series of CO2 sensors via the I2C protocol. It provides functions to initialize the sensor, start continuous measurements, read sensor data, and clean sensor structure.

## Constants and Macros

- `SCD_I2C_ADDR`: I2C address of the SCD4x sensor.
- `START_PERIODIC_MODE`, `READ_DATA`, etc.: Commands for controlling the sensor.
- `SCD_OK`: Return value indicating successful operations.
- `SCD_ERROR`: Return value indicating unsuccessful operations or errors.

## Data Structures

### `strSCDData`

Stores sensor data:
- `temp`: Temperature in hundredths of a degree Celsius.
- `hum`: Humidity in tenths of percent relative humidity.
- `co2`: CO2 concentration in parts per million.

### `strSCDConfig`

Stores configuration offsets for sensor data:
- `tempOffset`: Offset for temperature data, ranging from -100 to 100.
- `humOffset`: Offset for humidity data, ranging from -250 to 250.
- `co2Offset`: Offset for CO2 data, ranging from -500 to 500.

### `strSCD`

Combines sensor data and configuration:
- `data`: Instance of `strSCDData` to store current sensor readings.
- `config`: Instance of `strSCDConfig` to store calibration offsets.

## Functions

### `bool_t SCD_Init()`

Initializes the SCD4x sensor by setting up the I2C interface and starting periodic measurement mode. This function must be called before any other sensor-related functions.

Returns:
- `SCD_OK` if initialization was successful.
- `SCD_ERROR` if an error occurred during initialization.

### `bool_t SCD_CleanSensor(strSCD *sensor)`

Resets the sensor data fields (temperature, humidity, and CO2 levels) to zero.

Parameters:
- `sensor`: Pointer to the sensor structure to clean.

Returns:
- `true` if successful.
- `false` if the sensor pointer is NULL.

### `bool_t SCD_PollData(strSCD *sensor)`

Polls the sensor for new data. Reads CO2, temperature, and humidity from the sensor and updates the sensor structure accordingly.

Parameters:
- `sensor`: Pointer to the sensor structure where data will be stored.

Returns:
- `SCD_OK` if data was successfully read.
- `SCD_ERROR` if there was an error reading data.

## Data Limits and Defaults

- Temperature, humidity, and CO2 have specific offset limits to ensure data accuracy.
- Default values are defined for cases where sensor data may not be initially available or is being reset.

## Usage

To use the library, initialize the sensor with `SCD_Init()`, then periodically call `SCD_PollData()` to update the sensor data in your application.

## Notes

- Ensure the I2C bus is properly configured and that the sensor is powered and connected correctly.
- Handle return values carefully to manage errors in sensor communication.

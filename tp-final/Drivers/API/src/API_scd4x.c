/**
 * @file API_scd4x.c
 * @author Iván Podoroska
 * @brief 
 * @version 0.1
 * 
 */

#include "API_scd4x.h"
#include "API_i2c.h"
#include "port.h"

//Sensor data
#define DMA_TFER_LEN 2
#define DATA_LENGTH  6
#define MAX_ERRORS   2

#define SCD_I2C_ADDR (0x62 << 1)

#define SENSOR_MODE_LENGTH	2U
#define START_PERIODIC_MODE 0x21B1U
#define READ_DATA           0xEC05U
#define STOP_PERIODIC_MODE  0x3F86U
#define WAKE_UP_MODE        0x36F6U
#define REINIT_MODE         0x3646U
#define SERIALN_MODE        0x3682U
#define SET_ASC_ENABLED     0x2416
#define GET_ASC_ENABLED     0x2313
#define DATA_READY_STATUS   0xE4B8U
#define POLYNOMIAL 			0x31
#define DATA_READY_LENGTH   3U
    
#define CO2_POS_0    0U
#define CO2_POS_1    1U
#define CO2_CRC_POS  2U
#define TEMP_POS_0   3U
#define TEMP_POS_1   4U
#define TEMP_CRC_POS 5U
#define HUM_POS_0 	 6U
#define HUM_POS_1    7U
#define HUM_CRC_POS  8U
#define CRC_INIT     0xFFU
#define CRC_LENGTH   2U

#define SCD_DATA_LENGTH 9U
#define WAIT_TIME  50U

static bool_t  SCD_SendCommand(uint16_t cmd);
static uint8_t SCD_CRC8(const uint8_t *data, uint8_t len);

/**
 * @brief Initializes the SCD4x sensor.
 * @return bool_t SCD_OK if successful, SCD_ERROR otherwise.
 */
bool_t SCD_Init()
{
	if(!I2C_isInit())
	{
		if (I2C_HW_init() != I2C_OK)
		{
			return SCD_ERROR;
		}
	}
    
    if(SCD_SendCommand(START_PERIODIC_MODE) == I2C_OK) /** Start continue measurement */
    {
        return SCD_OK;
    }
    return SCD_ERROR;
}

/**
 * @brief Cleans the sensor data structure by setting data fields to zero.
 * @param sensor Pointer to the sensor data structure.
 * @return bool_t true if successful, false if the sensor pointer is NULL.
 */
bool_t SCD_CleanSensor(strSCD *sensor)
{
    if (NULL == sensor)
    {
        return false;
    }
    
    sensor->data.temp = 0U;
    sensor->data.hum  = 0U;
    sensor->data.co2  = 0U;

    sensor->config.tempOffset = 0U;
    sensor->config.humOffset  = 0U;
    sensor->config.co2Offset  = 0U;

    return true;
}

/**
 * @brief Polls the sensor for new data and updates the sensor data structure.
 * @param sensor Pointer to the sensor data structure where data will be stored.
 * @return bool_t SCD_OK if data was successfully read, SCD_ERROR otherwise.
 */
bool_t SCD_PollData(strSCD *sensor)
{
    uint8_t data[SCD_DATA_LENGTH];
    uint16_t rawCO2         = 0U;
    uint16_t rawTemperature = 0U;
    uint16_t rawHumidity    = 0U;

    if (SCD_SendCommand(READ_DATA) != I2C_OK)
    {
        return SCD_ERROR;
    }

    Port_Delay(50);

    if(I2C_Receive(SCD_I2C_ADDR, data, SCD_DATA_LENGTH) != I2C_OK)
    {
        return SCD_ERROR;
    }

    if (SCD_CRC8(data, 2) != data[CO2_CRC_POS]) /** Check CO2 CRC */
    {
    	return SCD_ERROR;
    };

    if (SCD_CRC8(data + TEMP_POS_0, 2) != data[TEMP_CRC_POS]) /** Check Temperature CRC */
    {
    	return SCD_ERROR;
    };

    if (SCD_CRC8(data + HUM_POS_0, 2) != data[HUM_CRC_POS]) /** Check Humidity CRC */
    {
        	return SCD_ERROR;
	};

    rawCO2           = (data[CO2_POS_0] << 8) | data[CO2_POS_1];
    sensor->data.co2 = rawCO2;

    rawTemperature    = (data[TEMP_POS_0] << 8) | data[TEMP_POS_1];
    sensor->data.temp = (int16_t)(1750 * rawTemperature / 65535 - 450);

    rawHumidity      = (data[HUM_POS_0] << 8) | data[HUM_POS_1];
    sensor->data.hum = 100 * rawHumidity / 65535;

    return SCD_OK;
}

/**
 * @brief Sends a command to the SCD4x sensor.
 * @param cmd The command to send.
 * @return bool_t true if the command was successfully sent, false otherwise.
 */
static bool_t SCD_SendCommand(uint16_t cmd)
{
    uint8_t data[2];
    data[0] = (cmd >> 8) & 0xFF;
    data[1] = cmd & 0xFF;
    return I2C_Send(SCD_I2C_ADDR, data, 2);
}

/**
 * @brief Calculates CRC8 for data validation. (Commented out - can be included if CRC checks are required)
 * @param data Pointer to the data array for which CRC is to be calculated.
 * @param len Length of the data array.
 * @return uint8_t Calculated CRC8 value.
 */
static uint8_t SCD_CRC8(const uint8_t *data, uint8_t len)
{
    uint8_t crc = CRC_INIT;
    for (int j = 0; j < len; j++) {
        crc ^= data[j];
        for (int i = 8; i > 0; i--) {
            if (crc & 0x80)
                crc = (crc << 1) ^ POLYNOMIAL;
            else
                crc = (crc << 1);
        }
    }
    return crc;
}




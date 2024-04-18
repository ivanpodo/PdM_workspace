#ifndef API_SCD_40_H
#define API_SCD_40_H

#include "API_common.h"

#define SCD_OK    0
#define SCD_ERROR 1

// Data limits
#define TEMP_OFFSET_MAX_LIMIT  100
#define TEMP_OFFSET_MIN_LIMIT -100
#define HUM_OFFSET_MAX_LIMIT   250
#define HUM_OFFSET_MIN_LIMIT  -250
#define CO2_OFFSET_MAX_LIMIT   500
#define CO2_OFFSET_MIN_LIMIT  -500

// Default values
#define TEMP_DEFAULT_VALUE  1000
#define HUM_DEFAULT_VALUE   150
#define CO2_DEFAULT_VALUE   5000

typedef struct
{
    int16_t temp;
    uint16_t hum;
    uint16_t co2;
} strSCDData;

typedef struct
{
    int16_t tempOffset;
    int16_t humOffset;
    int16_t co2Offset;
} strSCDConfig;

typedef struct
{
    strSCDData   data;
    strSCDConfig config;
} strSCD;

bool_t SCD_Init();
bool_t SCD_CleanSensor(strSCD *sensor);
bool_t SCD_PollData(strSCD *sensor);

#endif
#include "API_scd4x.h"

bool_t SCD_init()
{
    // TODO
    return SCD_OK;
}

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

void SCD_PollData(strSCD *senosr)
{
    //TODO
}
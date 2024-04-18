#include "API_ambientMonitor.h"
#include "API_delay.h"
#include "API_uart.h"
#include "API_lcd.h"
#include "API_scd4x.h"

#define ERROR_STR              (uint8_t *)"STATE - ERROR\n\r"
#define INITIALIZATION_STR     (uint8_t *)"STATE - INITIALIZATION\n\r"
#define DISPLAY_DATA_TOP_STR   (uint8_t *)"STATE - DISPLAY DATA TOP\n\r"
#define DISPLAY_DATA_STR       (uint8_t *)"STATE - DISPLAY DATA\n\r"
#define CALIBRATION_STR        (uint8_t *)"STATE - CALIBRATION\n\r"
#define SELECT_TEMPERATURE_STR (uint8_t *)"STATE - SELECT TEMPERATURE\n\r"
#define SELECT_HUMIDITY_STR    (uint8_t *)"STATE - SELECT HUMIDITY\n\r"
#define SELECT_CO2_STR         (uint8_t *)"STATE - SELECT CO2\n\r"
#define EXIT_STR               (uint8_t *)"STATE - EXIT\n\r"
#define OFFSET_TEMPERATURE_STR (uint8_t *)"STATE - OFFSET TEMPERATURE\n\r"
#define OFFSET_HUMIDITY_STR    (uint8_t *)"STATE - OFFSET HUMIDITY\n\r"
#define OFFSET_CO2_STR         (uint8_t *)"STATE - OFFSET CO2\n\r"
#define POLLING_SENSOR_DATA    (uint8_t *)"Polling sensor data...\n\r"
#define OFFSET_UPDATED         (uint8_t *)"Offset updated\n\r"

#define LCD_ERROR_STR              (uint8_t *)"ERROR"
#define LCD_INITIALIZATION_STR     (uint8_t *)"Wait..."
#define LCD_DISPLAY_DATA_STR       (uint8_t *)"  DISPLAY DATA"
#define LCD_CALIBRATION_STR        (uint8_t *)"  CALIBRATION"
#define LCD_SELECT_TEMPERATURE_STR (uint8_t *)"  SELECT TEMP"
#define LCD_SELECT_HUMIDITY_STR    (uint8_t *)"SELECT HUMIDITY"
#define LCD_SELECT_CO2_STR         (uint8_t *)"   SELECT CO2"
#define LCD_EXIT_STR               (uint8_t *)"      EXIT"
#define LCD_OFFSET_TEMPERATURE_STR (uint8_t *)"OFFSET TEMP"
#define LCD_OFFSET_HUMIDITY_STR    (uint8_t *)"OFFSET HUMIDITY"
#define LCD_OFFSET_CO2_STR         (uint8_t *)"OFFSET CO2"

// Display macros
#define STR_BUFF_TEXT_LENGTH 8

#define LCD_TEMP_POS     0          /** HIGH LINE */
#define LCD_TEMP_STR     "T:"
#define LCD_HUM_POS      9          /** HIGH LINE */
#define LCD_HUM_STR      "HR:"
#define LCD_CO2_POS      0          /** LOW LINE */
#define LCD_CO2_STR      "CO2: "
#define LCD_CO2_UNIT     "ppm"
#define LCD_OFFSETS_POS  9

typedef enum
{
    INITIALIZATION     = 1,
    DISPLAY_DATA_TOP,
    DISPLAY_DATA,       
    CALIBRATION,        
    SELECT_TEMPERATURE, 
    SELECT_HUMIDITY,    
    SELECT_CO2,         
    EXIT,               
    OFFSET_TEMPERATURE, 
    OFFSET_HUMIDITY,    
    OFFSET_CO2         
} eState;

typedef struct
{
    eState state_;
} strFSM;

static strFSM FSM;
static strSCD Sensor;

static delay_t dataDelay;
static int16_t offsetCounter;

static void Error_Handler();
static void updateDisplayData(strSCD *);
static void updateDisplayOffset(int16_t, eState);

/**
 * @brief Perform FSM initialization including LCD display and SCD sensor.
 * Both must be connected to PB8 I2C_A_SCL & PB9 I2C_A_SDA
 * 
 * @return bool_t 
 */
bool_t AMB_MON_Init()
{
    bool_t _ret = true;
    FSM.state_ = INITIALIZATION;

    delayInit(&dataDelay, UPDATE_DATA_INTERVAL);

    if (LCD_Init() != LCD_OK)
    {
        Error_Handler();
    }

    LCD_Clear();
    
    // if (SCD_Init() != SCD_OK)
    // {
    //     Error_Handler();
    // }
    
    return _ret;
}

static bool_t entry = true;

/**
 * @brief Updates FSM periodically. Updates Display and poll sensors every
 * `POLLING_SENSOR_DATA`
 * 
 * @param dir 
 * @param swPressed 
 */
void AMB_MON_Update(eMovingDir dir, bool_t swPressed)
{
    switch (FSM.state_)
    {
        case INITIALIZATION:
            uartSendString(INITIALIZATION_STR);
            LCD_PosCharacH(0);
            LCD_SendText(LCD_INITIALIZATION_STR);

            SCD_CleanSensor(&Sensor);
            // SCD_PollData(&Sensor); //TODO descomentar
            Sensor.data.temp = 241; //TODO: sacar
            Sensor.data.hum  = 64;  //TODO: sacar
            Sensor.data.co2  = 789; //TODO: sacar

            Sensor.config.tempOffset = 10;  //TODO: sacar
            Sensor.config.humOffset  = 5;   //TODO: sacar
            Sensor.config.co2Offset  = 100; //TODO: sacar

            FSM.state_ = DISPLAY_DATA_TOP;
            entry = true;
            break;

        case DISPLAY_DATA_TOP:
            if (entry)
            {
                LCD_Clear();
                LCD_PosCharacH(0);
                uartSendString(DISPLAY_DATA_TOP_STR);
                updateDisplayData(&Sensor);
                entry = false;
            }

            if (delayRead(&dataDelay))
            {
                uartSendString(POLLING_SENSOR_DATA);
                // SCD_PollData(&Sensor); // TODO: poll data from sensors
                updateDisplayData(&Sensor);
            }
            
            if (swPressed)
            {
                FSM.state_ = DISPLAY_DATA;
                entry = true;
            }
            
            break;

        case DISPLAY_DATA:
            if (entry)
            {
                LCD_Clear();
                LCD_PosCharacH(0);
                LCD_SendText(LCD_DISPLAY_DATA_STR);
                uartSendString(DISPLAY_DATA_STR);
                entry = false;
            }

            if (swPressed)
            {
                FSM.state_ = DISPLAY_DATA_TOP;
                entry = true;
            }
            else if (dir != INVALID)
            {
                FSM.state_ = CALIBRATION;
                entry = true;
            }
            
            break;

        case CALIBRATION:
            if (entry)
            {
                LCD_Clear();
                LCD_PosCharacH(0);
                LCD_SendText(LCD_CALIBRATION_STR);
                uartSendString(CALIBRATION_STR);
                entry = false;
            }

            if (swPressed)
            {
                FSM.state_ = SELECT_TEMPERATURE;
                entry = true;
            }
            else if (dir != INVALID)
            {
                FSM.state_ = DISPLAY_DATA;
                entry = true;
            }
            
            break;

        case SELECT_TEMPERATURE:
            if (entry)
            {
                LCD_Clear();
                LCD_PosCharacH(0);
                LCD_SendText(LCD_SELECT_TEMPERATURE_STR);
                uartSendString(SELECT_TEMPERATURE_STR);
                entry = false;
            }

            if (swPressed)
            {
                FSM.state_ = OFFSET_TEMPERATURE;
                entry = true;
            }
            else if (dir == CW)
            {
                FSM.state_ = SELECT_HUMIDITY;
                entry = true;
            }
            else if (dir == CounterCW)
            {
                FSM.state_ = EXIT;
                entry = true;
            }
            break;

        case SELECT_HUMIDITY:
            if (entry)
            {
                LCD_Clear();
                LCD_PosCharacH(0);
                LCD_SendText(LCD_SELECT_HUMIDITY_STR);
                uartSendString(SELECT_HUMIDITY_STR);
                entry = false;
            }

            if (swPressed)
            {
                FSM.state_ = OFFSET_HUMIDITY;
                entry = true;
            }
            else if (dir == CW)
            {
                FSM.state_ = SELECT_CO2;
                entry = true;
            }
            else if (dir == CounterCW)
            {
                FSM.state_ = SELECT_TEMPERATURE;
                entry = true;
            }
            break;

        case SELECT_CO2:
            if (entry)
            {
                LCD_Clear();
                LCD_PosCharacH(0);
                LCD_SendText(LCD_SELECT_CO2_STR);
                uartSendString(SELECT_CO2_STR);
                entry = false;
            }

            if (swPressed)
            {
                FSM.state_ = OFFSET_CO2;
                entry = true;
            }
            else if (dir == CW)
            {
                FSM.state_ = EXIT;
                entry = true;
            }
            else if (dir == CounterCW)
            {
                FSM.state_ = SELECT_HUMIDITY;
                entry = true;
            }
            break;

        case EXIT:
            if (entry)
            {
                LCD_Clear();
                LCD_PosCharacH(0);
                LCD_SendText(LCD_EXIT_STR);
                uartSendString(EXIT_STR);
                entry = false;
            }

            if (swPressed)
            {
                FSM.state_ = DISPLAY_DATA;
                entry = true;
            }
            else if (dir == CW)
            {
                FSM.state_ = SELECT_TEMPERATURE;
                entry = true;
            }
            else if (dir == CounterCW)
            {
                FSM.state_ = SELECT_CO2;
                entry = true;
            }
            break;

        case OFFSET_TEMPERATURE:
            if (entry)
            {
                LCD_Clear();
                LCD_PosCharacH(0);
                LCD_SendText(LCD_OFFSET_TEMPERATURE_STR);
                uartSendString(OFFSET_TEMPERATURE_STR);
                offsetCounter = Sensor.config.tempOffset;
                updateDisplayOffset(offsetCounter, FSM.state_);
                entry = false;
            }

            if (dir != INVALID)
            {
                if (dir == CW)
                {
                    offsetCounter++;
                }
                else
                {
                    offsetCounter--;
                }
                updateDisplayOffset(offsetCounter, FSM.state_);
            }            
            
            if (swPressed)
            {
                FSM.state_ = DISPLAY_DATA;
                if ((offsetCounter < TEMP_OFFSET_MAX_LIMIT) || (offsetCounter > TEMP_OFFSET_MIN_LIMIT))
                {
                    Sensor.config.tempOffset = offsetCounter;
                    uartSendString(OFFSET_UPDATED);
                }
                
                entry = true;
            }
            break;

        case OFFSET_HUMIDITY:
            if (entry)
            {
                LCD_Clear();
                LCD_PosCharacH(0);
                LCD_SendText(LCD_OFFSET_HUMIDITY_STR);
                uartSendString(OFFSET_HUMIDITY_STR);
                offsetCounter = Sensor.config.humOffset;
                updateDisplayOffset(offsetCounter, FSM.state_);
                entry = false;
            }

            if (dir != INVALID)
            {
                if (dir == CW)
                {
                    offsetCounter++;
                }
                else
                {
                    offsetCounter--;
                }
                updateDisplayOffset(offsetCounter, FSM.state_);
            }          
            if (swPressed)
            {
                FSM.state_ = DISPLAY_DATA;
                if ((offsetCounter < HUM_OFFSET_MAX_LIMIT) || (offsetCounter > HUM_OFFSET_MIN_LIMIT))
                {
                    Sensor.config.humOffset = offsetCounter;
                    uartSendString(OFFSET_UPDATED);
                }
                entry = true;
            }
            break;

        case OFFSET_CO2:
            if (entry)
            {
                LCD_Clear();
                LCD_PosCharacH(0);
                LCD_SendText(LCD_OFFSET_CO2_STR);               
                uartSendString(OFFSET_CO2_STR);
                offsetCounter = Sensor.config.co2Offset;
                updateDisplayOffset(offsetCounter, FSM.state_);
                entry = false;
            }

            if (dir != INVALID)
            {
                if (dir == CW)
                {
                    offsetCounter++;
                }
                else
                {
                    offsetCounter--;
                }
                updateDisplayOffset(offsetCounter, FSM.state_);
            }

            if (swPressed)
            {
                FSM.state_ = DISPLAY_DATA;
                if ((offsetCounter < CO2_OFFSET_MAX_LIMIT) || (offsetCounter > CO2_OFFSET_MIN_LIMIT))
                {
                    Sensor.config.co2Offset = offsetCounter;
                    uartSendString(OFFSET_UPDATED);
                }
                entry = true;
            }
            break;

        default:
            uartSendString(ERROR_STR);
            break;
    }
}

/**
 * @brief Update display with data stored in sensor structure
 * 
 * @param sensor 
 */
static void updateDisplayData(strSCD *sensor)
{
    LCD_Clear();
    LCD_PosCharacH(LCD_TEMP_POS);
    LCD_SendText((uint8_t *)LCD_TEMP_STR);

    char _buffer[STR_BUFF_TEXT_LENGTH];
    int16_t _temp = sensor->data.temp + sensor->config.tempOffset;
    int16_t _integer = _temp / 10;
    int16_t _decimal = _temp % 10; 

    sprintf(_buffer, "%d,%d\xDF""C", _integer, _decimal); /** \xB0 ASCII for (°)*/
    LCD_SendText((uint8_t *)_buffer);

    LCD_PosCharacH(LCD_HUM_POS);
    LCD_SendText((uint8_t *)LCD_HUM_STR);
    sprintf(_buffer, "%d%%", (sensor->data.hum + sensor->config.humOffset));
    LCD_SendText((uint8_t *)_buffer);

    LCD_PosCharacL(LCD_CO2_POS);
    LCD_SendText((uint8_t *)LCD_CO2_STR);
    sprintf(_buffer, "%d", (sensor->data.co2 + sensor->config.co2Offset));
    LCD_SendText((uint8_t *)_buffer);
    LCD_SendText((uint8_t *)LCD_CO2_UNIT);
}

/**
 * @brief Update display in offset setting states.
 * 
 * @param counter 
 * @param state 
 */
static void updateDisplayOffset(int16_t counter, eState state)
{
    char _buffer[STR_BUFF_TEXT_LENGTH];
    LCD_PosCharacL(LCD_OFFSETS_POS);

    switch (state)
    {
    case OFFSET_TEMPERATURE:
        {
            int16_t _integer = counter / 10;
            int16_t _decimal = counter % 10;
            sprintf(_buffer, "%d,%d \xDF""C", _integer, _decimal); /** \xB0 ASCII for (°)*/
            LCD_SendText((uint8_t *)_buffer);
        }
        break;

    case OFFSET_HUMIDITY:
        sprintf(_buffer, "%d%%", counter);
        LCD_SendText((uint8_t *)_buffer);
        break;

    case OFFSET_CO2:
        sprintf(_buffer, "%d", counter);
        LCD_SendText((uint8_t *)_buffer);
        LCD_SendText((uint8_t *)LCD_CO2_UNIT);
        break;
    
    default:
        Error_Handler();
        break;
    }
}

/**
 * @brief Error handler function that is called when an invalid operation occurs
 * 
 */
static void Error_Handler()
{
    while (1) { }
}
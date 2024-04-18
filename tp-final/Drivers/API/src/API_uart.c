#include <stdio.h>
#include "API_uart.h"
#include "stm32f4xx_hal.h"   	 
#include "stm32f4xx_nucleo_144.h"

#define UART_ERROR_SUPPORTED    3   /**< Number of retry attempts for UART 
                                         errors. */
#define TICKS_WAIT_ERROR        8   /**< Number of ticks to wait on UART error, 
                                         timeout, or busy state. */
#define PRINT_BUFFER_SIZE       50  /**< Size of the buffer used for printing 
                                         UART configurations. */
#define UART_INSTANCE   USART3

static UART_HandleTypeDef huart_;

static bool_t isInit = false;       /**< Flag indicating if the UART has been 
                                         successfully initialized. */

static void Error_Handler(void);

static HAL_StatusTypeDef uartTransmitData(UART_HandleTypeDef *huart,
                                          uint8_t *pData,
                                          uint16_t size);

static HAL_StatusTypeDef uartReceiveData(UART_HandleTypeDef *huart,
                                         uint8_t *pData,
                                         uint16_t size);

/**
 * @brief Initializes the UART module with predefined configurations.
 *
 * This function initializes the UART module with specific settings for baud 
 * rate, parity, stop bits, etc., and checks if initialization is successful.
 *
 * @return bool_t True if initialization was successful, otherwise false.
 */
bool_t uartInit()
{
    bool_t _ret = false;

    huart_.Instance          = UART_INSTANCE;
    huart_.Init.BaudRate     = UART_BAUDRATE;
    huart_.Init.Parity       = UART_PARITY_NONE;    
    huart_.Init.StopBits     = UART_STOPBITS_1;     
    huart_.Init.WordLength   = UART_WORDLENGTH_8B;  
    huart_.Init.Mode         = UART_MODE_TX_RX;     
    huart_.Init.HwFlowCtl    = UART_HWCONTROL_NONE; 
    huart_.Init.OverSampling = UART_OVERSAMPLING_16;

    if(HAL_UART_Init(&huart_) == HAL_OK)
    {
        isInit = true;
        _ret = true;

        uartSendString((uint8_t *)"UART configuration: 8N1\n\r");
        
        char _buffer[PRINT_BUFFER_SIZE];
        snprintf(_buffer, sizeof(_buffer), "UART baudrate:      %lu\n\r",
                 huart_.Init.BaudRate);
        uartSendString((uint8_t *)_buffer);
    }

    return _ret;
}

/**
 * @brief Send a string of a specified size over UART.
 *
 * @param pString Pointer to the string to be sent.
 * @param size Size of the string to be sent.
 */
void uartSendStringSize(uint8_t *pString, uint16_t size)
{
    if ((pString == NULL) || (isInit == false))
    {
        Error_Handler();
    }

    if (size > 0)
    {
        if(uartTransmitData(&huart_, pString, size) != HAL_OK)
        {
            Error_Handler();
        }
    }
}

/**
 * @brief Receive a string of a specified size over UART.
 *
 * @param pString Pointer to the buffer where the received string will be stored.
 * @param size Size of the string to be received.
 */
void uartReceiveStringSize(uint8_t *pString, uint16_t size)
{
    if ((pString == NULL) || (isInit == false))
    {
        Error_Handler();
    }

    if (size > 0)
    {
        uartReceiveData(&huart_, pString, size);
    }
}

/**
 * @brief Send a null-terminated string over UART.
 *
 * Sends a string until a null character is encountered or the maximum character 
 * limit is reached.
 *
 * @param pString Pointer to the null-terminated string to be sent.
 */
void uartSendString(uint8_t *pString)
{
    if ((pString == NULL) || (isInit == false))
    {
        Error_Handler();
    }

    uint8_t _guard = 0U;
    
    while (((*pString) != '\0') && (_guard < UART_MAX_CHAR))
    {
        if(uartTransmitData(&huart_, pString, 1U) != HAL_OK)
        {
            break;
        }
        pString++;
        _guard++;
    }
}

/**
 * @brief Transmit data over UART.
 *
 * Attempts to transmit data over UART with specified retries on failure.
 *
 * @param huart Pointer to a UART_HandleTypeDef structure that contains
 *              the configuration information for the specified UART module.
 * @param pData Pointer to the data buffer to be sent.
 * @param size Amount of data to be sent in bytes.
 * @return HAL_StatusTypeDef HAL status code.
 */
static HAL_StatusTypeDef uartTransmitData(UART_HandleTypeDef *huart,
                                          uint8_t *pData,
                                          uint16_t size)
{
    if ((huart == NULL) || (isInit == false))
    {
        Error_Handler();
    }

    HAL_StatusTypeDef _result = HAL_ERROR;

    uint8_t _retries = UART_ERROR_SUPPORTED;

    do
    {
        _result = HAL_UART_Transmit(huart, pData, size, UART_TIMEOUT);

        if (_result == HAL_OK)
        {
            break;
        }

        HAL_Delay(TICKS_WAIT_ERROR);

        if (_retries == 0U)
        {
            break;
        }

    } while(_retries-- > 0);

    return _result;
}

/**
 * @brief Receive data over UART.
 *
 * Attempts to receive data over UART with specified retries on failure.
 *
 * @param huart Pointer to a UART_HandleTypeDef structure that contains
 *              the configuration information for the specified UART module.
 * @param pData Pointer to the buffer where the received data will be stored.
 * @param size Maximum amount of data to be received in bytes.
 * @return HAL_StatusTypeDef HAL status code.
 */
static HAL_StatusTypeDef uartReceiveData(UART_HandleTypeDef *huart,
                                         uint8_t *pData,
                                         uint16_t size)
{
    if ((huart == NULL) || (isInit == false))
    {
        Error_Handler();
    }

    HAL_StatusTypeDef _result = HAL_ERROR;

    uint8_t _retries = UART_ERROR_SUPPORTED;
       
    do
    {
        _result = HAL_UART_Receive(huart, pData, size, UART_TIMEOUT);

        if (_result == HAL_OK)
        {
            break;
        }

        HAL_Delay(TICKS_WAIT_ERROR);

        if (_retries == 0U)
        {
            break;
        }

    } while(_retries-- > 0U);

    return _result;
}

/**
 * @brief Error handler function that is called when an invalid operation occurs
 * 
 */
static void Error_Handler(void)
{
    while(1)
    {}
}
                                    

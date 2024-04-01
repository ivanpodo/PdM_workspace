#include "API_debounce.h"
#include "API_uart.h"
#include "string.h"

typedef enum{
	BUTTON_UP,
	BUTTON_FALLING,
	BUTTON_DOWN,
	BUTTON_RAISING,
} debounceState_t;

static delay_t FSM_delay;
static debounceState_t actualState;
static bool_t isButtonPressed;
static bool_t FSM_isInit = false;   // To check initialization first

static void Error_Handler(void);
static void Error_Handler(void)
{
	while (1)
	{
	}
}

/**
 * @brief   Initializes the debounce Finite State Machine (FSM) to its starting
 * 		    state. This function sets the internal state of the FSM to the 
 *          initial state, preparing it for operation and state tracking.
 */
void debounceFSM_init()
{
	actualState = BUTTON_UP;
    isButtonPressed = false;
	BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);
    delayInit(&FSM_delay, DEBOUNCE_TIME);
	
    FSM_isInit = true;  // All resources initialized. 
}

/**
 * @brief   Updates the Finite State Machine (FSM) based on the state of 
 * 		    BUTTON_USER. This function reads the current state of BUTTON_USER 
 *          and adjusts the FSM to reflect any changes, ensuring that button 
 * 		    debouncing is handled properly.
 */
void debounceFSM_update()
{
    if (!FSM_isInit)
    {
        Error_Handler();
    }
    
	GPIO_PinState buttonState = BSP_PB_GetState(BUTTON_USER);

	switch (actualState)
	{
	case BUTTON_UP:
		if(buttonState == GPIO_PIN_RESET)
		{
			delayInit(&FSM_delay, DEBOUNCE_TIME);
			actualState = BUTTON_FALLING;
		}
		break;

	case BUTTON_FALLING:
		if (delayRead(&FSM_delay))
		{
			if (buttonState == GPIO_PIN_RESET)
			{
				isButtonPressed = true;
				actualState = BUTTON_DOWN;
				const char *msg = "FLANCO DESCENDENTE\n\r";
				uartSendStringSize((uint8_t *)msg, strlen(msg));
			}
		}
		break;

	case BUTTON_DOWN:
		if(buttonState == GPIO_PIN_SET)
		{
			delayInit(&FSM_delay, DEBOUNCE_TIME);
			actualState = BUTTON_RAISING;
		}
		break;

	case BUTTON_RAISING:
		if (delayRead(&FSM_delay))
		{
			if (buttonState == GPIO_PIN_SET)
			{
				actualState = BUTTON_UP;
				const char *msg = "FLANCO ASCENDENTE\n\r";
				uartSendStringSize((uint8_t *)msg, strlen(msg));
			}
		}
		break;

	default:
	    debounceFSM_init();
		break;
	}
}

/**
 * @brief   Reads the state of a key and determines if it has been pressed.
 *          This function is responsible for checking the current state of an 
 *          internal module variable, which represents whether a specific key 
 *          has been pressed. Upon invocation, it reads this variable and  
 *          outputs a boolean value: true or false.
 * @return  bool_t Returns true if the key has been pressed since the last time
 *          it was checked. Otherwise, returns false.
 */
bool_t readKey()
{
    bool_t _ret = isButtonPressed;
    isButtonPressed = false;
    return _ret;
}




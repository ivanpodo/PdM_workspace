#include "API_debounce.h"

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

void debounceFSM_init()
{
	actualState = BUTTON_UP;
    isButtonPressed = false;
	BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);
    delayInit(&FSM_delay, DEBOUNCE_TIME);
    FSM_isInit = true;  // All resources initialized. 
}

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
			}
		}
		break;

	default:
	    debounceFSM_init();
		break;
	}
}

bool_t readKey()
{
    bool_t _ret = isButtonPressed;
    isButtonPressed = false;
    return _ret;
}




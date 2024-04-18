#include "API_debounce.h"

static void Error_Handler(void);

/**
 * @brief   Initializes the debounce Finite State Machine (FSM) to its starting
 * 		    state. This function sets the internal state of the FSM to the 
 *          initial state, preparing it for operation and state tracking.
 */
void DBN_FSMinit(stDebounce *button, gpio_t *pin, delay_t *delay)
{
	if(NULL == button || NULL == delay)
	{
		Error_Handler();
	}

	button->gpio_ 			 = pin;
	button->delay_			 = delay;
	button->state_ 			 = BUTTON_UP;
	button->isButtonPressed_ = false;

	delayInit(button->delay_, DEBOUNCE_TIME);

	button->isInit			 = true;
}

/**
 * @brief   Updates the Finite State Machine (FSM) based on the state of 
 * 		    BUTTON_USER. This function reads the current state of BUTTON_USER 
 *          and adjusts the FSM to reflect any changes, ensuring that button 
 * 		    debouncing is handled properly.
 */
void DBN_FSMupdate(stDebounce *button)
{
    if (!button->isInit)
    {
        Error_Handler();
    }
    
	GPIO_PinState buttonState = Port_ReadPin(button->gpio_->port, button->gpio_->pin);

	switch (button->state_)
	{
	case BUTTON_UP:
		if(buttonState == GPIO_PIN_RESET)
		{
			delayInit(button->delay_, DEBOUNCE_TIME);
			button->state_ = BUTTON_FALLING;
		}
		break;

	case BUTTON_FALLING:
		if (delayRead(button->delay_))
		{
			if (buttonState == GPIO_PIN_RESET)
			{
				button->isButtonPressed_ = true;
				button->state_ = BUTTON_DOWN;
			}
		}
		break;

	case BUTTON_DOWN:
		if(buttonState == GPIO_PIN_SET)
		{
			delayInit(button->delay_, DEBOUNCE_TIME);
			button->state_ = BUTTON_RAISING;
		}
		break;

	case BUTTON_RAISING:
		if (delayRead(button->delay_))
		{
			if (buttonState == GPIO_PIN_SET)
			{
				button->state_ = BUTTON_UP;
			}
		}
		break;

	default:
	    DBN_FSMinit(button, button->gpio_, button->delay_);
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
bool DBN_readKey(stDebounce *button)
{
    bool _ret = button->isButtonPressed_;
    button->isButtonPressed_ = false;
    return _ret;
}

debounceState_t DBN_getState(stDebounce *button)
{
	return button->state_;
}

static void Error_Handler(void)
{
	while (1)
	{
	}
}


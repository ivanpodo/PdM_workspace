#include "API_debounce.h"
#include "port.h"

static void Error_Handler(void);

/**
 * @brief Initializes the debounce Finite State Machine (FSM) to its initial state.
 *        This function prepares the FSM for operation by setting the initial state
 *        and initializing related hardware configurations.
 *
 * @param button Pointer to stDebounce structure managing the debounce state.
 * @param pin Pointer to gpio_t structure representing the GPIO pin configuration.
 * @param delay Pointer to delay_t structure used for timing operations.
 * @note This function must be called before any other debouncing functions are used.
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
 * @brief Updates the debounce FSM based on the current state of the button GPIO pin.
 *        This function reads the GPIO pin state and transitions the FSM states 
 * 		  accordingly to handle debouncing effectively.
 *
 * @param button Pointer to stDebounce structure managing the debounce state.
 * @note The FSM must be initialized with DBN_FSMinit before calling this function.
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
 * @brief Checks if a button has been pressed since the last call.
 *        Reads and returns the press state of the button, resetting the state 
 * 		  after checking.
 *
 * @param button Pointer to stDebounce structure managing the debounce state.
 * @return bool_t True if the button was pressed since the last check, false 
 * 		   otherwise.
 */
bool DBN_readKey(stDebounce *button)
{
    bool _ret = button->isButtonPressed_;
    button->isButtonPressed_ = false;
    return _ret;
}

/**
 * @brief Retrieves the current state of the debounce FSM.
 *
 * @param button Pointer to stDebounce structure managing the debounce state.
 * @return debounceState_t The current state of the debounce FSM.
 */
debounceState_t DBN_getState(stDebounce *button)
{
	return button->state_;
}

/**
 * @brief Error handler function that is called when an invalid operation occurs
 * 
 */
static void Error_Handler(void)
{
	while (1)
	{
	}
}


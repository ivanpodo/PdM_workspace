#include "API_encoder.h"
#include "port.h"

typedef enum
{
    State_00, /**< DT = 0, CLK = 0*/
    State_01, /**< DT = 0, CLK = 1*/
    State_11, /**< DT = 1, CLK = 1*/
    State_10  /**< DT = 1, CLK = 0*/
} eStateEncoder;

typedef struct
{
    gpio_t dt_, clk_;
    eStateEncoder lastValidState_;
    eStateEncoder state_;
    eMovingDir    dir_;
    bool_t        taken_;
} stEncoder;

static bool isInit = false;
static stEncoder Encoder;
static stDebounce clkButton;
static stDebounce dtButton;
static delay_t clkDelay;
static delay_t dtDelay;

static void Error_Handler(void);

/**
 * @brief Perform encoder FSM initialization.
 * 
 */
void ENC_encoderInit()
{
    DBN_FSMinit(&clkButton, &Encoder.clk_, &clkDelay);
    DBN_FSMinit(&dtButton,  &Encoder.dt_,  &dtDelay);

    Encoder.lastValidState_ = State_11;
    if(Port_ReadPin(Encoder.clk_.port, Encoder.clk_.pin) == GPIO_PIN_SET)
    {
        if(Port_ReadPin(Encoder.dt_.port, Encoder.dt_.pin) == GPIO_PIN_SET)
        {
            Encoder.state_    = State_11;
        }
        else
        {
            Encoder.state_ = State_01;
        }
    }
    else
    {
        if(Port_ReadPin(Encoder.dt_.port, Encoder.dt_.pin) == GPIO_PIN_SET)
        {
            Encoder.state_ = State_10;
        }
        else
        {
            Encoder.state_ = State_00;
            Encoder.lastValidState_ = State_00;
        }
    }

    Encoder.dir_   = CW;
    Encoder.taken_ = true;
    isInit         = true;
}

/**
 * @brief Updates encoder FSM. Must be called pediodically
 * 
 */
void ENC_encoderUpdate()
{
    if (!isInit)
    {
        Error_Handler();
    }
    
    DBN_FSMupdate(&clkButton);
    DBN_FSMupdate(&dtButton);

    debounceState_t clkState = DBN_getState(&clkButton);
    debounceState_t dtState  = DBN_getState(&dtButton);
    
    switch (Encoder.state_)
    {
    case State_00:

        if (dtState == BUTTON_UP)
        {
            Encoder.state_ = State_10;
        }
        else if (clkState == BUTTON_UP)
        {
            Encoder.state_ = State_01;
        }
        break;

    case State_01:
        if (dtState == BUTTON_UP)
        {
            Encoder.state_ = State_11;
            if (Encoder.lastValidState_ == State_00)
            {
                Encoder.lastValidState_ = State_11;
                Encoder.dir_   = CW;
                Encoder.taken_ = false;
            }
        }
        else if (clkState == BUTTON_DOWN)
        {
            Encoder.state_ = State_00;
            if (Encoder.lastValidState_ == State_11)
            {
                Encoder.lastValidState_ = State_00;
                Encoder.dir_   = CounterCW;
                Encoder.taken_ = false;
            }
        }        
        break;

    case State_11:
        if (dtState == BUTTON_DOWN)
        {
            Encoder.state_ = State_01;
        }
        else if (clkState == BUTTON_DOWN)
        {
            Encoder.state_ = State_10;
        }
        break;
   
    case State_10:
        if (dtState == BUTTON_DOWN)
        {
            Encoder.state_ = State_00;
            if (Encoder.lastValidState_ == State_11)
            {
                Encoder.lastValidState_ = State_00;
                Encoder.dir_   = CW;
                Encoder.taken_ = false;
            }
        }
        else if (clkState == BUTTON_UP)
        {
            Encoder.state_ = State_11;
            if (Encoder.lastValidState_ == State_00)
            {
                Encoder.lastValidState_ = State_11;
                Encoder.dir_   = CounterCW;
                Encoder.taken_ = false;
            }
        }
        break;
    
    default:
        ENC_encoderInit();
        break;
    }
}

/**
 * @brief Return last valid direction just one time.
 * 
 * @return eMovingDir 
 */
eMovingDir ENC_getDirection()
{
    eMovingDir _ret = INVALID;

    if (!Encoder.taken_)
    {
        Encoder.taken_ = true;
        _ret = Encoder.dir_;
    }
    return _ret;
}

/**
 * @brief Set gpios into internal structure
 * 
 * @param dt 
 * @param clk 
 * @return bool_t 
 */
bool_t ENC_setGPIOs(gpio_t *dt, gpio_t *clk)
{
    if ((NULL == dt) || (NULL == clk))
    {
        return false;
    }
    
    Encoder.dt_.pin   = dt->pin;
    Encoder.dt_.port  = dt->port;
    Encoder.clk_.pin  = clk->pin;
    Encoder.clk_.port = clk->port;

    return true;
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

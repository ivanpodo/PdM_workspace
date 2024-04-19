/**
 * @file API_lcd.c
 * @author Ivan Podoroska
 * @brief 
 * @version 1.1
 * @date 2024-04-16
 * 
 */
#include "API_lcd.h"
#include "port.h"
#include "API_i2c.h"

static void controlLcd(uint8_t valor);
static void send8bits(uint8_t valor, bool_t tipo);
static void send4bits(uint8_t valor, bool_t tipo);

static const uint8_t LCD_INIT_CMD[] =
{
    MODE_4BIT,
    DISPLAY_CONTROL,
    RETURN_HOME,
    ENTRY_MODE+AUTOINCREMENT,
    DISPLAY_CONTROL+DISPLAY_ON,
    CLR_LCD
};

/**
 * @brief Initializes the LCD display.
 * @return bool_t LCD_OK on success, LCD_ERROR on failure.
 */                                                                                                                                                                                                                                                                                                                         
bool_t LCD_Init(void)
{
	if(!I2C_isInit())
	{
		if(I2C_HW_init() == LCD_ERROR)
		{
			return LCD_ERROR;
		}
	}

    Port_Delay(DELAY_20MS);

    send4bits(CMD_INIT1, CONTROL);
    Port_Delay(DELAY_10MS);

    send4bits(CMD_INIT1, CONTROL);
    Port_Delay(DELAY_1MS);

    send4bits(CMD_INIT1,CONTROL);
    send4bits(CMD_INIT2,CONTROL);

    for(uint8_t i = 0U; i < sizeof(LCD_INIT_CMD); i++)
    {
        controlLcd(LCD_INIT_CMD[i]);
    }

    Port_Delay(DELAY_2MS);
    return LCD_OK;
}

/**
 * @brief Sends 8-bit data to the LCD.
 * @param data Data to send.
 */
void LCD_Data(uint8_t data)
{
	send8bits(data, DATA);
}

/**
 * @brief Sends 8-bit data to the LCD as ASCII characters.
 * @param data Data to convert to ASCII and send.
 */
void LCD_DataAscii(uint8_t data)
{
	send8bits(data + '0', DATA);
}

/**
 * @brief Sends 8-bit data to the LCD as two ASCII characters representing high and low nibbles.
 * @param data Data to send as BCD.
 */
void LCD_DataBCD(uint8_t data)
{
	  LCD_DataAscii((((data) & MASK_4BITS_HIGH) >> 4));
	  LCD_DataAscii(((data)  & MASK_4BITS_LOW));
}

/**
 * @brief Sends a null-terminated string to the LCD.
 * @param text Pointer to the string to be displayed.
 */
void LCD_SendText(uint8_t *text)
{
    if (NULL == text)
    {
        return;
    }
    
	while(*text)
    {
        LCD_Data(*text++);
    }
}

/**
 * @brief Clears the LCD display.
 */
void LCD_Clear(void)
{
   controlLcd(CLR_LCD);
   Port_Delay(DELAY_2MS);
}

/**
 * @brief Sets the cursor position on the first line of the LCD.
 * @param posH Horizontal position on the first line.
 */
void LCD_PosCharacH(uint8_t posH)
{
    if (posH > 15)
    {
        return;
    }
	controlLcd(posH | LINE1);
}

/**
 * @brief Sets the cursor position on the second line of the LCD.
 * @param posL Horizontal position on the second line.
 */
void LCD_PosCharacL(uint8_t posL)
{
    if (posL > 15)
    {
        return;
    }
	controlLcd(posL | LINE2);
}

/**
 * @brief Disables the cursor display on the LCD.
 */
void LCD_CursorOff(void)
{
	controlLcd(DISPLAY_CONTROL + DISPLAY_ON);
}

/**
 * @brief Enables the cursor display and blinking on the LCD.
 */
void LCD_CursorOn(void)
{
	controlLcd(DISPLAY_CONTROL + CURSOR_ON + DISPLAY_ON + CURSOR_BLINK);
}

/**
 * @brief Controls the LCD with a specific command or data.
 * @param value The value/command to send.
 */
static void controlLcd(uint8_t value)
{
	send8bits(value, CONTROL);
}

/**
 * @brief Sends an 8-bit value to the LCD as two sets of 4-bits.
 * @param value The value to send.
 * @param tipo Indicates whether the value is a command or data.
 */
static void send8bits(uint8_t value, bool_t tipo)
{
	send4bits(value & HIGH_NIBBLE,tipo);
	send4bits(value << LOW_NIBBLE,tipo);
}

/**
 * @brief Sends a 4-bit value to the LCD.
 * @param value The value to send.
 * @param tipo Indicates whether the value is a command or data.
 */
static void send4bits(uint8_t value, bool_t tipo)
{
    uint8_t _val1 = (value + (uint8_t)tipo + (uint8_t)EN + (uint8_t)BL);
    uint8_t _val2 = (value + (uint8_t)tipo + (uint8_t)BL);

	I2C_Send(LCD_I2C_ADD, &_val1, sizeof(value));
	Port_Delay(DELAY_1MS);
	I2C_Send(LCD_I2C_ADD, &_val2, sizeof(value));
	Port_Delay(DELAY_1MS);
}

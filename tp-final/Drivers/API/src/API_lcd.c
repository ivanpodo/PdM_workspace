/**
 * @file API_lcd.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-16
 * 
 */
#include "API_lcd.h"
#include "lcd_port.h"
#include "API_i2c.h"

static void controlLcd(uint8_t valor);
static void send8bits(uint8_t valor,bool_t tipo);
static void send4bits(uint8_t valor,bool_t tipo);

static const uint8_t LCD_INIT_CMD[] =
{
    MODE_4BIT,
    DISPLAY_CONTROL,
    RETURN_HOME,
    ENTRY_MODE+AUTOINCREMENT,
    DISPLAY_CONTROL+DISPLAY_ON,
    CLR_LCD
};

bool_t LCD_init(void)
{
    if(I2C_HW_init() == LCD_ERROR) // TODO: sacar esto de acá. Era LCD_ERROR = 1
    {
        return LCD_ERROR;
    }

    Port_Delay(DELAY_20MS);

    send4bits(CMD_INIT1,CONTROL);
    Port_Delay(DELAY_10MS);

    send4bits(CMD_INIT1,CONTROL);
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

void LCD_Data(uint8_t data)
{
	send8bits(data, DATA);
}

void LCD_DataAscii(uint8_t data)
{
	send8bits(data + '0', DATA);
}

void LCD_DataBCD(uint8_t data)
{
	  LCD_DataAscii((((data) & MASK_4BITS_HIGH) >> 4));
	  LCD_DataAscii(((data)  & MASK_4BITS_LOW));
}

void LCD_SendText(uint8_t *text)
{
	while(*text)
    {
        LCD_Data(*text++);
    }
}

void LCD_Clear(void)
{
   controlLcd(CLR_LCD);
   Port_Delay(DELAY_2MS);
}

void LCD_PosCharacH(uint8_t posH)
{
    if (posH > 15)
    {
        return;
    }
	controlLcd(posH | LINE1);
}

void LCD_PosCharacL(uint8_t posL)
{
    if (posL > 15)
    {
        return;
    }
	controlLcd(posL | LINE2);
}

void LCD_CursorOff(void)
{
	controlLcd(DISPLAY_CONTROL + DISPLAY_ON);
}

void LCD_CursorOn(void)
{
	controlLcd(DISPLAY_CONTROL + CURSOR_ON + DISPLAY_ON + CURSOR_BLINK);
}

static void controlLcd(uint8_t value)
{
	send8bits(value, CONTROL);
}

static void send8bits(uint8_t value, bool_t tipo)
{
	send4bits(value & HIGH_NIBBLE,tipo);
	send4bits(value << LOW_NIBBLE,tipo);
}

static void send4bits(uint8_t value, bool_t tipo)
{
	Port_WriteByte(value + tipo + EN + BL);
	Port_Delay(DELAY_1MS);
	Port_WriteByte(value + tipo + BL);
	Port_Delay(DELAY_1MS);
}

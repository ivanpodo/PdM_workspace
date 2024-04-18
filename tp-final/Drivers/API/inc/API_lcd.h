#ifndef API_LCD_H
#define API_LCD_H

#include "stm32f4xx_hal.h"  	
#include "stm32f4xx_nucleo_144.h" 
#include "API_common.h"

#define DATA    1
#define CONTROL 0

#define LCD_OK    0
#define LCD_ERROR 1

#define EN (1<<2)
#define BL (1<<3)

// Control Signals
#define CLR_LCD              (1<<0)
#define RETURN_HOME          (1<<1)
#define ENTRY_MODE           (1<<2)
#define DISPLAY_CONTROL      (1<<3)
#define CURSOR_DISPLAY_SHIFT (1<<4)
#define FUNTION_SET          (1<<5)
#define SET_CGRAM            (1<<6)
#define SET_DDRAM            (1<<7)

#define CURSOR_BLINK         (1<<0)
#define CURSOR_ON            (1<<1)
#define DISPLAY_ON           (1<<2)
#define AUTOINCREMENT        (1<<1)
#define MODE_4BIT             0x28

// Delays
#define DELAY_20MS  20
#define DELAY_10MS  10
#define DELAY_2MS   2
#define DELAY_1MS   1

#define HIGH_NIBBLE 0xF0
#define LOW_NIBBLE  4

#define MASK_4BITS_HIGH 0xF0
#define MASK_4BITS_LOW  0x0F

#define LINE1 0x80
#define LINE2 0xC0

#define CMD_INIT1 0x30
#define CMD_INIT2 0x20

bool_t LCD_init(void);
void LCD_SendText(uint8_t *texto);
void LCD_Data(uint8_t dato);
void LCD_DataAscii(uint8_t dato);
void LCD_DataBCD(uint8_t dato);
void LCD_PosCharacH(uint8_t posH);
void LCD_PosCharacL(uint8_t posL);
void LCD_Clear(void);
void LCD_CursorOff(void);
void LCD_CursorOn(void);

#endif /* API_LCD_H */

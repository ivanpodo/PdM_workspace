# API_lcd.c Documentation

**File:** `API_lcd.c`  
**Author:** Ivan Podoroska  
**Version:** 1.1  
**Date:** 2024-04-16  

## Overview

This module handles LCD operations via I2C for displaying text, managing cursor positions, and controlling the display properties. It includes initialization routines, data sending, and cursor control functions tailored for an LCD using a standard HD44780 controller or a compatible one in 4-bit mode.

## Initialization

### `bool_t LCD_Init(void)`

Initializes the LCD display. This function sets up the I2C communication, sends initial configuration commands to the LCD, and ensures the display is ready for use. Returns `LCD_OK` if successful or `LCD_ERROR` otherwise.

## Data Sending Functions

### `void LCD_Data(uint8_t data)`

Sends an 8-bit data value to the LCD for display. The data is sent as character information to the LCD.

### `void LCD_DataAscii(uint8_t data)`

Converts the provided data into its ASCII equivalent and sends it to the LCD. Useful for displaying numerical values directly.

### `void LCD_DataBCD(uint8_t data)`

Sends the provided byte as two separate ASCII characters representing the high and low nibbles. Useful for displaying data in a human-readable binary-coded decimal format.

### `void LCD_SendText(uint8_t *text)`

Sends a string of text to the LCD. This function iterates over the string and sends each character to the display until the null terminator is encountered.

## Control Functions

### `void LCD_Clear(void)`

Clears the LCD display and resets the cursor position.

### `void LCD_PosCharacH(uint8_t posH)`

Sets the cursor position on the first line (high) of the LCD to the specified position `posH`. The position must be less than 16.

### `void LCD_PosCharacL(uint8_t posL)`

Sets the cursor position on the second line (low) of the LCD to the specified position `posL`. The position must be less than 16.

### `void LCD_CursorOff(void)`

Turns off the LCD cursor display.

### `void LCD_CursorOn(void)`

Turns on the LCD cursor display and makes it blink.

## Private Functions

### `static void controlLcd(uint8_t value)`

Sends a control command to the LCD. This is a wrapper around `send8bits` that specifically sets the control bit.

### `static void send8bits(uint8_t value, bool_t tipo)`

Breaks down an 8-bit value into two 4-bit values and sends each to the LCD, specifying whether the bits are data or control bits.

### `static void send4bits(uint8_t value, bool_t tipo)`

Sends a 4-bit value to the LCD. This function handles the lower-level I2C communication, sending the high nibble first followed by the low nibble, and manages the enable signal to latch the data into the LCD.

## Constants and Macros

This module uses several macros and constants to define control codes and delays used in LCD operations, such as `DELAY_1MS`, `DISPLAY_ON`, `CURSOR_ON`, `LINE1`, and `LINE2`.

## Error Handling

Error handling in this module is minimal and focuses primarily on initialization errors. During regular operation, errors are not explicitly handled but could be extended to include more robust error management.

## Notes

- It is important to ensure that the I2C bus is properly configured and that the LCD is compatible with the commands sent by this driver.
- Future improvements might include more dynamic error handling and configuration options to adapt to different LCD models or interfaces.

# UART API for STM32

## API_uart.h Documentation

**Brief:** Implementation of a UART communication interface.

## Overview
This API provides a straightforward method for UART communication on STM32 microcontrollers, facilitating the initialization of the UART module, and the sending and receiving of strings. It is designed to make UART communication in embedded projects simpler and more intuitive.

## Features
- UART module initialization with predefined configurations
- Blocking sending and receiving of strings
- Adjustable baud rate, timeout, and character limit settings

## Getting Started
To use the UART communication functionality, include `API_uart.h` in your STM32 project.

### Prerequisites
Your project should include the STM32 HAL Library, and the UART peripheral should be properly configured to match the settings used by `uartInit`.

### Installation
Copy `API_uart.h` and its implementation file into your project's respective include and source directories. Make sure to include it in your source files where UART communication is needed.

## API Reference
The API provides the following functions for UART communication:

- `bool_t uartInit();`
  
  Initializes the UART module with predefined settings. Returns `true` if successful.

- `void uartSendString(uint8_t * pString);`
  
  Sends a null-terminated string over UART.

- `void uartSendStringSize(uint8_t * pString, uint16_t size);`
  
  Sends a string over UART, specifying the size.

- `void uartReceiveStringSize(uint8_t * pString, uint16_t size);`
  
  Receives a string of a specified size over UART.

## Usage

### Initializing UART
Before sending or receiving data, the UART module must be initialized:

```c
if (uartInit()) {
    // UART initialized successfully
} else {
    // Initialization failed
}
```

### Sending a String
To send a string over UART:

```c
uartSendString((uint8_t *)"Hello, UART!");
```

For sending a string with a specified size:

```c
uint8_t message[] = "Hello, UART!";
uartSendStringSize(message, sizeof(message));
```

### Receiving a String
To receive a string of a specified size over UART:

```c
uint8_t buffer[50];
uartReceiveStringSize(buffer, sizeof(buffer));
```

## Error Handling
A simple error handler is invoked if a null pointer or zero duration is passed to the API functions, which may be replaced with a system-specific error handler as needed.

## Contributing
Contributions to the API are welcome. Please ensure that any pull requests or issues are concise and clear to aid in the review process.

## Author
Iván Podoroska

## License
This API is released under the MIT License.

```license
MIT License

Copyright (c) 2024 Iván Podoroska

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
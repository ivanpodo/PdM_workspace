# Button debouncing API for STM32 USER_BUTTON

# API_debounce.h Documentation

**Brief:** Implementation of a Finite State Machine (FSM) to perform software debounce of a USER_BUTTON on STM32 microcontrollers.

## Overview

The `API_debounce` module provides functions to manage the debouncing of a button or key input using a Finite State Machine approach. This is crucial for reliable button press detection in embedded applications.

## Macros

- `DEBOUNCE_TIME`: Sets the debounce interval to 40 milliseconds. This value balances responsiveness with effective noise filtering. It may be adjusted to fit specific application needs.

## Functions

### `void debounceFSM_init();`

Initializes the debounce FSM to its starting state, preparing it for operation.

### `void debounceFSM_update();`

Updates the FSM based on the current state of `BUTTON_USER`, ensuring proper debouncing.

### `bool_t readKey();`

Checks if a key has been pressed since the last check, returning a boolean value. Resets the key's state if pressed.

## Usage Example

First, initialize the debounce system:

```c
debounceFSM_init();
```

Regularly call debounceFSM_update() to process button state changes:

```c
while (1) {
    debounceFSM_update();
    if (readKey()) {
        // Button was pressed
    }
}
```
This structured documentation provides clarity on usage, installation, and features of the API, making it easier for developers to integrate and utilize the delay and debounce functionalities in their STM32 projects.

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
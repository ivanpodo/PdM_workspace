# Button debouncing API for STM32 USER_BUTTON

# API_debounce.h Documentation

**Brief:** Implementation of a Finite State Machine (FSM) to perform software debounce of a USER_BUTTON on STM32 microcontrollers.

## Overview

The `API_debounce` module offers a comprehensive approach to manage the debouncing of button or key inputs using a Finite State Machine (FSM). This methodology is essential for ensuring reliable button press detection in embedded systems.

## Macros

- `DEBOUNCE_TIME`: This macro sets the debounce interval to 10 milliseconds, striking a balance between responsiveness and effective noise filtering. It can be adjusted based on specific application needs and button characteristics.

## Data Types

- `debounceState_t`: Enumerates possible states in the debounce FSM (`BUTTON_UP`, `BUTTON_FALLING`, `BUTTON_DOWN`, `BUTTON_RAISING`).

- `stDebounce`: Struct that holds the debounce FSM configuration including the button GPIO, delay, current state, valid state, button press status, and initialization status.

## Functions

### `void DBN_FSMinit(stDebounce *button, gpio_t *pin, delay_t *delay);`

Initializes the debounce FSM to its starting state and configures the associated GPIO and delay components.

### `void DBN_FSMupdate(stDebounce *button);`

Updates the FSM based on the current state of the `BUTTON_USER` pin, ensuring appropriate debouncing.

### `bool_t DBN_readKey(stDebounce *button);`

Checks if a key has been pressed since the last check, returning a boolean value. Resets the key's state if pressed.

### `debounceState_t DBN_getState(stDebounce *button);`

Returns the current state of the debounce FSM, allowing external modules to query the state of the button.


## Usage Example

Initialize the debounce system and continuously update its state, checking for button presses:

```c
stDebounce button;
gpio_t pin = {GPIOC, GPIO_PIN_12};
delay_t delay;

DBN_FSMinit(&button, &pin, &delay);

while (1) {
    DBN_FSMupdate(&button);
    if (DBN_readKey(&button))
    {
        // Button was pressed
    }
    ...
    if(DBN_getState(&button) == BUTTON_UP)
    {
        // gpio is binded to Vss
    }
}
```
This structured documentation enhances clarity on the usage, configuration, and functionalities of the API, facilitating developers to seamlessly integrate and utilize the debounce functionalities in their STM32 projects.

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
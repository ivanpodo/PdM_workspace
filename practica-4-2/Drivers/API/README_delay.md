# Non-Blocking Delay API for STM32

# API_delay.h Documentation

**Brief:** Implementation a non-blocking delay.

## Overview
This API offers a simple interface for creating and managing non-blocking delays on STM32 microcontrollers. It is built to allow systems to perform other tasks while a delay is underway, without the CPU being held up in a wait loop.

## Features
- Initialize delay structures
- Check if a delay has expired without blocking
- Update delay durations on-the-fly

## Getting Started
Include `API_delay.h` in your STM32 project to access the delay functionality.

### Prerequisites
Make sure that the STM32 HAL Library is included in your project and that `HAL_GetTick()` is configured to increment properly.

### Installation
Simply copy `API_delay.h` into your project's include directory and include it in your source files where you need to use delays.

## API Reference
The following functions are available:

- void delayInit(delay_t *delay, tick_t duration);
  
Initializes a delay with a given duration.

- bool_t delayRead(delay_t *delay);
  
Checks if the delay has expired and manages delay state.

- void delayWrite(delay_t *delay, tick_t duration);
  
Updates the duration of an existing delay.

## Usage

### Initializing a Delay
Before using a delay, initialize it with `delayInit`.

```c
delay_t myDelay;
delayInit(&myDelay, 1000); // Initializes a delay for 1000 ticks.
```
### Checking a Delay
Use delayRead to check if the delay has expired. It will start the delay on the first call and check for expiration on subsequent calls.

```c
if (delayRead(&myDelay)) {
    // Delay has expired, time to do something.
}
```
### Updating a Delay
Change the duration of a delay anytime with delayWrite.

```c
delayWrite(&myDelay, 2000); // Updates the delay to 2000 ticks.
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
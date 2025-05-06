## Introduction
Arduino uses a programming language based on **C/C++**, designed for microcontrollers and embedded systems. Below are key syntax rules and commonly used functions.

---

## Basic Syntax
### 1. Structure
- The program consists of two main functions: `setup()` (runs once at startup) and `loop()` (runs continuously).
- Comments can be written as single-line (`//`) or multi-line (`/* ... */`).
- Variables must be declared with data types such as `int`, `float`, `char`, and `bool`.

---

## Basic Functions

### 1. Digital I/O
- Configure pins using `pinMode()`.
- Control digital pins using `digitalWrite()` and read their state with `digitalRead()`.

### 2. Analog I/O
- Read analog inputs using `analogRead()`.
- Write analog (PWM) values using `analogWrite()`.

### 3. Delay Function
- Pause execution for a specified time using `delay()`.

### 4. Serial Communication
- Initialize the serial monitor using `Serial.begin()`.
- Send data using `Serial.println()` or `Serial.print()`.
- Read incoming serial data using `Serial.read()`.

# Robomatics-Gear-Motor-Library

## Overview

The Arduino DCMotor library provides a simple and modular way to manage a DC motor connected to an Arduino board using the **L293D** motor driver.


![Circuit Diagram](./extras/eps32.png)


## Installation

1. **Download the Library:**
   - Click on the "Code" button in the GitHub repository.
   - Select "Download ZIP" to download the library as a ZIP file.

2. **Extract the ZIP File:**
   - Extract the contents of the ZIP file to your Arduino libraries directory.

3. **Restart the Arduino IDE:**
   - Restart the Arduino IDE to ensure that the library is recognized.

## Usage

1. **Include the Library:**
   ```cpp
   #include <DCMotor.h>
   ```

2. **Instantiate the VibrationMotor object:**
   ```cpp
   // Specify the pins of the L293D motor driver: (A, B, S)
   // A --> direction A
   // B --> direction B
   // S --> speed pin (PWM)
   DCMotor motor(2, 4, 9); 
   ```

## Features

- Constructor
   ```cpp
      // Initialize the VibrationMotor with the specified Arduino pin.
      VibrationMotor(uint8_t motorPin);
   ```

- Turn the Motor On
   ```cpp
      // Turn on the motor with a given speed. 
      // The speed in in range [-255, 255] where the sign determines the direction.
      void on(int speed);
   ```

- Turn the Motor On for a given time
   ```cpp
      // Turn on the motor with a given speed and for a given time in millisec. After, the motor turns off.
      void on(int speed, int millisec);
   ```

- Turn the Motor Off
   ```cpp
      void off();
   ```

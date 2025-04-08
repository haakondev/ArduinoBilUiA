# UiA Bil Prosjekt 2025

This project is part of the "UiA Bil Prosjekt 2025" and is developed by Bamle and Addi. It involves controlling a robotic car using PID control and motor drivers.

## Project Overview

The project uses C++ and the Arduino framework to implement a robotic car that follows a lead vehicle. The car's movement is controlled using PID (Proportional-Integral-Derivative) algorithms to maintain a desired distance from the lead vehicle.

## Features

- **Motor Control**: Uses the `Motor` class to control two motors (MotorA and MotorB).
- **PID Control**: Implements a PID controller to adjust motor speeds based on distance errors.
- **Distance Measurement**: Reads sensor data to calculate the distance from the lead vehicle.
- **Configurable Parameters**: Adjustable PID constants and other parameters via `parameters.h`.

## File Structure

- `src/main.cpp`: Main program logic for motor control and sensor reading.
- `src/PID.h`: PID controller implementation.
- `src/parameters.h`: Configuration file for project parameters.

## Dependencies

- Arduino framework
- Custom `Motor` library

## How to Use

1. Clone the repository to your local machine.
2. Open the project in an IDE like CLion or the Arduino IDE.
3. Configure the parameters in `parameters.h` as needed.
4. Upload the code to your Arduino-compatible board.
5. Connect the motors and sensors as per the hardware setup.

## Configuration

The following parameters can be adjusted in `parameters.h`:

- `KP_VERDI`, `KI_VERDI`, `KD_VERDI`: PID constants.
- `ARC_DISTANCE`: Desired distance from the lead vehicle.
- `WHEEL_DIAMETER`: Diameter of the wheels in cm.
- `STARTSPEED_VALUE`: Initial motor speed.
- `MAX_INTEGRAL`: Maximum integral value for PID control.

## Example Usage

The following snippet demonstrates how the PID controller is used to calculate motor speed adjustments:

```cpp
PID pidController("DistancePID", KP_VERDI, KI_VERDI, KD_VERDI);
float pidOutput = pidController.calculatePidOutput(error, previousTime);
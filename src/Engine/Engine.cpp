#include "Engine.h"

/**
 * @brief Drives the motor with the specified speed, direction, and state.
 *
 * @param speed The speed of the motor (0-255).
 * @param backward Whether the motor should run backward (true) or forward (false).
 * @param run Whether the motor should run (true) or stop (false).
 */
void Engine::drive(int speed, bool backward, bool run) {
    if (!run) {
        analogWrite(enginePin, 255);
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        return;
    }
    if (backward) {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        analogWrite(enginePin, speed);
    } else {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        analogWrite(enginePin, speed);
    }
}

/**
 * @brief Brakes the motor by applying maximum resistance.
 */
void Engine::brake() {
    analogWrite(enginePin, 255);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, HIGH);
}

/**
 * @brief Stops the motor by cutting off power and setting direction pins to LOW.
 */
void Engine::stop() {
    analogWrite(enginePin, 0);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
}

/**
 * @brief Sets the pin for motor speed control (EN pin).
 *
 * @param pinEn The pin number to set for speed control.
 */
void Engine::setEnginePin(int pinEn) {
    enginePin = pinEn;
}

/**
 * @brief Gets the pin number used for motor speed control (EN pin).
 *
 * @return The pin number for speed control.
 */
int Engine::getEnginePin() {
    return enginePin;
}

/**
 * @brief Sets the pin for motor direction control (Input 1).
 *
 * @param pin The pin number to set for Input 1.
 */
void Engine::setPinInOne(int pin) {
    in1 = pin;
}

/**
 * @brief Gets the pin number used for motor direction control (Input 1).
 *
 * @return The pin number for Input 1.
 */
int Engine::getPinInOne() {
    return in1;
}

/**
 * @brief Sets the pin for motor direction control (Input 2).
 *
 * @param pin The pin number to set for Input 2.
 */
void Engine::setPinInTwo(int pin) {
    in2 = pin;
}

/**
 * @brief Gets the pin number used for motor direction control (Input 2).
 *
 * @return The pin number for Input 2.
 */
int Engine::getPinInTwo() {
    return in2;
}

/**
 * @brief Sets the name of the motor.
 *
 * @param name The name to assign to the motor.
 */
void Engine::setName(String name) {
    this->name = name;
}

/**
 * @brief Gets the name of the motor.
 *
 * @return The name of the motor.
 */
String Engine::getName() {
    return name;
}
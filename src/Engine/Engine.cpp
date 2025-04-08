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
        Serial.println("Motor " + name + " has now stopped.");
        return;
    }
    if (backward) {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        analogWrite(enginePin, speed);
        Serial.println("Motor " + name + " is now going backwards.");
    } else {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        analogWrite(enginePin, speed);
        Serial.println("Motor " + name + " is now going forwards.");
    }
}

/**
 * @brief Brakes the motor by applying maximum resistance.
 */
void Engine::brake() {
    analogWrite(enginePin, 255);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, HIGH);
    Serial.println("Motor " + name + " is now braking.");
}

/**
 * @brief Stops the motor by cutting off power and setting direction pins to LOW.
 */
void Engine::stop() {
    analogWrite(enginePin, 0);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    Serial.println("Motor " + name + " has now stopped.");
}

/**
 * @brief Sets the pin for motor speed control (EN pin).
 *
 * @param pinEn The pin number to set for speed control.
 */
void Engine::setEnginePin(int pinEn) {
    Serial.println("You set in1 to pin EN(A/B) " + String(pinEn));
    enginePin = pinEn;
}

/**
 * @brief Gets the pin number used for motor speed control (EN pin).
 *
 * @return The pin number for speed control.
 */
int Engine::getEnginePin() {
    Serial.println("pin EN(A/B) is " + String(enginePin));
    return enginePin;
}

/**
 * @brief Sets the pin for motor direction control (Input 1).
 *
 * @param pin The pin number to set for Input 1.
 */
void Engine::setPinInOne(int pin) {
    Serial.println("You set in1 to pin " + String(pin));
    in1 = pin;
}

/**
 * @brief Gets the pin number used for motor direction control (Input 1).
 *
 * @return The pin number for Input 1.
 */
int Engine::getPinInOne() {
    Serial.println("in1 is " + String(in1));
    return in1;
}

/**
 * @brief Sets the pin for motor direction control (Input 2).
 *
 * @param pin The pin number to set for Input 2.
 */
void Engine::setPinInTwo(int pin) {
    Serial.println("You set in2 to pin " + String(pin));
    in2 = pin;
}

/**
 * @brief Gets the pin number used for motor direction control (Input 2).
 *
 * @return The pin number for Input 2.
 */
int Engine::getPinInTwo() {
    Serial.println("in2 is " + String(in2));
    return in2;
}

/**
 * @brief Sets the name of the motor.
 *
 * @param motorName The name to assign to the motor.
 */
void Engine::setName(String motorName) {
    Serial.println("You set name to " + motorName);
    name = motorName;
}

/**
 * @brief Gets the name of the motor.
 *
 * @return The name of the motor.
 */
String Engine::getName() {
    Serial.println("name is " + name);
    return name;
}
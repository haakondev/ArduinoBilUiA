

// Loop

// Mål distanse fra ledebil

// Proporsjonal = TrueDistance - Goal Distance

// Integral = Integral + feil(GoalDistance - TrueDistance)

// Derivert = Fart

// Speed = Proporsjonal * Kp + Integral * Ki + Derivert * Kd

/**
 * @file PID.h
 * @brief This file contains the implementation of a PID controller class for use in Arduino-based projects.
 */

#include <Arduino.h>
#include "motor.h"
#include "parameters.h"

/**
 * @class PID
 * @brief A class to implement a Proportional-Integral-Derivative (PID) controller.
 */
class PID {
private:
    float Kp; ///< Proportional gain
    float Ki; ///< Integral gain
    float Kd; ///< Derivative gain

    float error = 0; ///< Current error value
    float previousError = 0; ///< Previous error value for derivative calculation
    float integral = 0; ///< Accumulated integral of the error
    float derivative = 0; ///< Rate of change of the error

    String name; ///< Name of the PID controller instance

public:
    /**
     * @brief Constructor for the PID class.
     * @param name The name of the PID controller instance.
     * @param kp Proportional gain.
     * @param ki Integral gain.
     * @param kd Derivative gain.
     */
    PID(const String name, float kp, float ki, float kd) :
            name(name),
            Kp(kp),
            Kd(kd),
            Ki(ki)
    {}

    /**
     * @brief Calculates the PID output based on the current error and time.
     * @param error The current error value.
     * @param previousTime The previous timestamp in milliseconds.
     * @return The calculated PID output.
     */
    float calculatePidOutput(float error, const unsigned long previousTime) {

        // Get the current time in milliseconds
        unsigned long currentTime = millis();

        // Calculate the time difference in seconds
        float deltaTime = (currentTime - previousTime) / 1000.0;
        deltaTime = deltaTime > 0 ? deltaTime : 0.001; // Avoid division by zero

        // Calculate integral (accumulated error over time)
        this->integral += error * deltaTime;
        this->integral = constrain(integral, -MAX_INTEGRAL, MAX_INTEGRAL); // Constrain integral to avoid windup

        // Calculate derivative (rate of change of error)
        this->derivative = (error - previousError) / deltaTime;

        // Calculate PID output
        float pidOutput = (Kp * error) + (Ki * integral) + (Kd * derivative);

        // Update previous error
        this->previousError = error;

        return pidOutput;
    }
};
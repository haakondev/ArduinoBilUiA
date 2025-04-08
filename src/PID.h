


// KP, KI, KD, GoalDistance
/*
int Kp = 0;
int Ki = 0;
int Kd = 0;

int GoalDistance = 20; // Cm
int TrueDistance = 0;
*/


// Loop

// Mål distanse fra ledebil

// Proporsjonal = TrueDistance - Goal Distance

// Integral = Integral + feil(GoalDistance - TrueDistance)

// Derivert = Fart

// Speed = Proporsjonal * Kp + Integral * Ki + Derivert * Kd

#include <Arduino.h>
#include "motor.h"
#include "parameters.h"

class PID {
private:
    float Kp;
    float Ki;
    float Kd;

    float error = 0;
    float previousError = 0;
    float integral = 0;
    float derivative = 0;

    String name;

public:
    PID(String name, float kp, float ki, float kd){
        this->name = name;
        this->Kp = kp;
        this->Ki = ki;
        this->Kd = kd;

    }
    float calculatePidOutput(float error, unsigned long previousTime) {
        unsigned long currentTime = millis();
        float deltaTime = (currentTime - previousTime) / 1000.0;

        // Calculate integral (accumulated error over time)
        this->integral += error * deltaTime;
        this->integral = constrain(integral, -MAX_INTEGRAL, MAX_INTEGRAL);

        // Calculate derivative (rate of change of error)
        this->derivative = (error - previousError) / deltaTime;

        // Calculate PID output
        float pidOutput = (Kp * error) + (Ki * integral) + (Kd * derivative);

        // Update previous error
        this->previousError = error;

        return pidOutput;
    }
};




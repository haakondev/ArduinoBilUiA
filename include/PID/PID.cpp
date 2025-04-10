#include "PID.h"
#include <Arduino.h>

PID::PID(float kp, float ki, float kd) {
    Kp = kp;
    Ki = ki;
    Kd = kd;
    prevError = 0;
    integral = 0;
    lastTime = millis();
}

float PID::calculate(float setpoint, float measuredValue) {
    float error = setpoint - measuredValue;
    unsigned long now = millis();
    float deltaTime = (now - lastTime) / 1000.0; // convert to seconds

    integral += error * deltaTime;
    float derivative = (error - prevError) / deltaTime;

    float output = Kp * error + Ki * integral + Kd * derivative;

    prevError = error;
    lastTime = now;

    return output;
}

void PID::reset() {
    prevError = 0;
    integral = 0;
    lastTime = millis();
}

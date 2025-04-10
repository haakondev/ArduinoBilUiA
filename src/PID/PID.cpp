#include "PID.h"

PID::PID(String name, float kp, float ki, float kd, float maxIntegral)
    : name(name), kp(kp), ki(ki), kd(kd), integral(0), previousError(0), maxIntegral(maxIntegral) {}

float PID::calculate(float currentValue, float targetValue) {

    unsigned long now = millis();

    float deltaTime = (now - previousTime) / 1000.0; // Convert milliseconds to seconds

    float error = targetValue - currentValue;
    integral += error * deltaTime;

    // Clamp integral to avoid wind-up
    if (integral > maxIntegral) integral = maxIntegral;
    if (integral < -maxIntegral) integral = -maxIntegral;

    float derivative = (error - previousError) / deltaTime;
    previousError = error;

    return kp * error + ki * integral + kd * derivative;
    previousTime = now;
}

void PID::reset() {
    integral = 0;
    previousError = 0;
}


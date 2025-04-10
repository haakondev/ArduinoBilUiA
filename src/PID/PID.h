#ifndef PID_H
#define PID_H

#include <Arduino.h>

class PID {
private:
    String name;
    float kp, ki, kd;
    float integral;
    float previousError;
    float maxIntegral;
    unsigned long previousTime = 0;

public:
    PID(String name, float kp, float ki, float kd, float maxIntegral = 255.0);

    float calculate(float currentValue, float targetValue);

    void reset();

    // Getters (optional)
    float getKp() const { return kp; }
    float getKi() const { return ki; }
    float getKd() const { return kd; }
    String getName() const { return name; }
};

#endif

//
// Created by haksie001 on 10.04.2025.
//



#ifndef UIAARDUINO_CALCULATOR_H
#define UIAARDUINO_CALCULATOR_H

#include <Arduino.h>
#include "parameters.h"

class calculator {
public:
    calculator() {
    }

    float ArcWheelSpeed(boolean outer, int radius, int wheelDistance, int wantedSpeed) {
        return outer ? (wantedSpeed * (radius) + (wheelDistance / 2)) : (wantedSpeed * (radius) - (wheelDistance / 2));
    }

    float distanceToCar(int readLeft, int readRight) {
        int theSum = readLeft + readRight;
        return (0.0927611617 * theSum - 0.7325530993); // Placeholder function
    }

    double distanceDriven(int countLeft, int countRight) {
        double avgCount = (countLeft + countRight) / 2.0;
        return (avgCount / NUM_SLITS) * WHEEL_DIAMETER * PI;
    }

    float speedFromPulses(long pulseCount, float wheelDiameter, int intervalMs) {
        float wheelCircumference = wheelDiameter * PI;
        float revolutions = pulseCount / (float)NUM_SLITS;
        float distance = revolutions * wheelCircumference;
        return (distance / (intervalMs / 1000.0)); // Speed in meters per second
    }



};

#endif //UIAARDUINO_CALCULATOR_H

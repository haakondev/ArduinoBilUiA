#include <Arduino.h>
#include "calculations.h" // Class header
#include "../src/parameters/physicalConstants.h"

double calculations::ArcWheelSpeed(boolean outer, float radius, float wheelDistance, float wantedSpeed) {
    return outer ? (wantedSpeed * (radius + (wheelDistance / 2))) : (wantedSpeed * (radius - (wheelDistance / 2)));
}

float calculations::distanceToCar(int readLeft, int readRight, int startSum) {
    int theSum = readLeft + readRight;
    if (theSum >= startSum + 300) return 0.0;
    else if (theSum >= startSum + 270) return 0.05;
    else if (theSum >= startSum + 260) return 0.1;
    else if (theSum >= startSum + 191) return 0.2;
    else if (theSum >= startSum + 150) return 0.3;
    else if (theSum >= startSum + 124) return 0.4;
    else if (theSum >= startSum + 112) return 0.5;
    else if (theSum >= startSum + 85) return 0.6;
    else if (theSum >= startSum + 80) return 0.7;
    else if (theSum >= startSum + 73) return 0.8;
    else if (theSum >= startSum + 60) return 0.9;
    else return 0; // Return -1 for undefined values
}

double calculations::distanceDriven(int countLeft, int countRight) {
    double avgCount = (countLeft + countRight) / 2.0;
    return (avgCount / NUM_SLITS) * WHEEL_DIAMETER * PI;
}

float calculations::speedFromPulsesRPS(long pulseCount, int intervalMs) {
    float revolutions = pulseCount / (float)NUM_SLITS;
    return (revolutions / (intervalMs / 1000.0)); // Speed in rps
}
float calculations::speedFromPulses(long pulseCount, float wheelDiameter, int intervalMs) {
    float wheelCircumference = wheelDiameter * PI;
    float revolutions = pulseCount / (float)NUM_SLITS;
    float distance = revolutions * wheelCircumference;
    return (distance / (intervalMs / 1000.0)); // Speed in meters per second
}


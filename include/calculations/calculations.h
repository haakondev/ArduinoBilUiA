#include <Arduino.h>


class calculations {
public:
    calculations() {}

    double ArcWheelSpeed(boolean outer, float radius, float wheelDistance, float wantedSpeed);

    float distanceToCar(int readLeft, int readRight, int startSum);

    double distanceDriven(int countLeft, int countRight);

    float speedFromPulsesRPS(long pulseCount, int intervalMs);

    float speedFromPulses(long pulseCount, float wheelDiameter, int intervalMs);

};

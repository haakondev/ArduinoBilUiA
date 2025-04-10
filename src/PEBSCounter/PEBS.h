#ifndef UIAARDUINO_PEBS_H
#define UIAARDUINO_PEBS_H

#include <Arduino.h>

class PEBS {
private:
    String name;
    int pin;
    volatile int count = 0; // Volatile for interrupt safety
    int lastPulseCount = 0;
    unsigned long lastTime = 0;

public:
    // Constructor
    PEBS(String name, int pin) : name(name), pin(pin) {}

    // Getters and setters
    void setPin(int pin) { this->pin = pin; }
    int getPin() const { return pin; }
    void setName(String name) { this->name = name; }
    String getName() const { return name; }
    volatile int getCount() const { return count; }
    void setCount(volatile int counter) { this->count = count; }
    int getLastPulseCount() const { return lastPulseCount; }
    void setLastPulseCount(int lastPulseCount) { this->lastPulseCount = lastPulseCount; }

    // Increment counter (called in interrupt)
    void countInterrupt(unsigned long now) { this->count++; this->lastTime = now;}

    // Reset counter
    void reset() { count = 0; }

};

#endif // UIAARDUINO_PEBS_H
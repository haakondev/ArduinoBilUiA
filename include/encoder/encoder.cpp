#include "encoder.h"

// Getters and setters
void encoder::setPin(int pin) {
    this->pin = pin;
}

int encoder::getPin() const {
    return pin;
}

void encoder::setName(String name) {
    this->name = name;
}
String encoder::getName() const {
    return name;
}
volatile int encoder::getCount() const {
    return count;
}

void encoder::setCount(volatile int counter) {
    this->count = count;
}

int encoder::getLastPulseCount() const {
    return lastPulseCount;
}

void encoder::setLastPulseCount(int lastPulseCount) {
    this->lastPulseCount = lastPulseCount;
}

// Increment counter (called in interrupt)
void encoder::countInterrupt(unsigned long now) {
    this->count++; this->lastTime = now;
}

// Reset counter
void encoder::reset() {
    this->count = 0;
    this->lastPulseCount = 0;
}

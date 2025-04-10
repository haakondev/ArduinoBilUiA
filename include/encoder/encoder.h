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

class encoder {
private:
    String name;
    int pin;
    volatile int count = 0; // Volatile for interrupt safety
    int lastPulseCount = 0;
    unsigned long lastTime = 0;
public:
    // Constructor
    encoder(String name, int pin) {
        this->name = name;
        this->pin = pin;
    }
    void setPin(int pin);
    int getPin() const;
    void setName(String name);
    String getName() const;
    volatile int getCount() const;
    void setCount(volatile int counter);
    int getLastPulseCount() const;
    void setLastPulseCount(int lastPulseCount);
    void countInterrupt(unsigned long now);
    void reset();
    // Getters and setters

};


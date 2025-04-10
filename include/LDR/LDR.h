#include <Arduino.h>

class LDR {
private:
    String name;
    int pin;

public:
    LDR(String name, int pin = A4) {
        this->name = name;
        this->pin = pin;
    }

    int read();

    int setPin(int pin);

    int getPin() const;


    void printReadings();
};
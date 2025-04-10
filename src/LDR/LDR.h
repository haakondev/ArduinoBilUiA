#include <Arduino.h>

#ifndef UIAARDUINO_LDR_H
#define UIAARDUINO_LDR_H

class LDR {
private:
    String name;
    int pin;

public:
    LDR(String name, int pin = A4) {
        this->name = name;
        this->pin = pin;
    }

    int read() {
        return analogRead(pin);
    }


    void printReadings() {
        Serial.print(name + ": ");
        Serial.print(read());
    }
};

#endif //UIAARDUINO_LDR_H
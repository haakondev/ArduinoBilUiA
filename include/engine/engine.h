#ifndef UIAARDUINO_ENGINE_H
#define UIAARDUINO_ENGINE_H

#include <Arduino.h>

class engine {
private:
    int enginePin;
    int in1;
    int in2;
    String name;

public:
    engine(String name, int enginePin, int in1, int in2) {
        this->name = name;
        this->enginePin = enginePin;
        this->in1 = in1;
        this->in2 = in2;
    }

    void drive(int speed, bool backward, bool run);
    void brake();
    void stop();
    void setEnginePin(int pinEn);
    int getEnginePin();
    void setPinInOne(int pin);
    int getPinInOne();
    void setPinInTwo(int pin);
    int getPinInTwo();
    void setName(String name);
    String getName();
};

#endif // ENGINE_H
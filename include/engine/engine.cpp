#include "engine.h"

void engine::drive(int speed, bool backward, bool run) {
    if (!run) {
        analogWrite(enginePin, 255);
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        return;
    }
    if (backward) {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        analogWrite(enginePin, speed);
    } else {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        analogWrite(enginePin, speed);
    }
}

void engine::brake() {
    analogWrite(enginePin, 255);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, HIGH);
}

void engine::stop() {
    analogWrite(enginePin, 0);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
}

void engine::setEnginePin(int pinEn) {
    enginePin = pinEn;
}

int engine::getEnginePin() {
    return enginePin;
}

void engine::setPinInOne(int pin) {
    in1 = pin;
}

int engine::getPinInOne() {
    return in1;
}

void engine::setPinInTwo(int pin) {
    in2 = pin;
}

int engine::getPinInTwo() {
    return in2;
}

void engine::setName(String name) {
    this->name = name;
}

String engine::getName() {
    return name;
}
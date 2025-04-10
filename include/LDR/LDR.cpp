#include "LDR.h"

int LDR::read() {
    return analogRead(pin);
}
void LDR::printReadings() {
    Serial.print(name + ": ");
    Serial.print(read());
}

void LDR::setPin(int pin) {
    this->pin = pin;
}

int LDR::getPin() const {
    return pin;
}
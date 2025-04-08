#include <Arduino.h>
#include "Engine/Engine.h"

volatile int rightWheelCount = 0;
volatile int leftWheelCount = 0;

void trigRightWheel() {rightWheelCount+=1;}
void trigLeftWheel() {leftWheelCount+=1;}

int ReadingPin = A0;

Engine MotorA("A", 9, 8, 7);

Engine MotorB("B", 5, 6, 4);

int speedH = 255;
int speedV = 255;

void setup() {

    Serial.begin(9600);

    // Motor pins
    pinMode(MotorA.getPinInOne(), OUTPUT);
    pinMode(MotorA.getPinInTwo(), OUTPUT);
    pinMode(MotorB.getPinInOne(), OUTPUT);
    pinMode(MotorB.getPinInTwo(), OUTPUT);


}

void loop() {

    MotorA.drive(speedH, false, true);

}
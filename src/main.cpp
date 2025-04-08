#include <Arduino.h>
#include <Motor.h>

volatile int rightWheelCount = 0;
volatile int leftWheelCount = 0;

void trigRightWheel() {rightWheelCount+=1;}
void trigLeftWheel() {leftWheelCount+=1;}

int ReadingPin = A0;

// Motor B

int enB = 5;
int in4 = 4;
int in3 = 6;

// Motor A

int in2 = 7;
int in1 = 8;
int enA = 9;

int speedH = 255;
int speedV = 255;

void setup() {
    Serial.begin(9600);
    pinMode(enB, OUTPUT);
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in4, OUTPUT);
}

void loop() {
    analogWrite(enA, speedH);
    analogWrite(enB, speedV);
    pinMode(in1, HIGH);
    pinMode(in2, LOW);
    pinMode(in3, HIGH);
    pinMode(in4, LOW);
}
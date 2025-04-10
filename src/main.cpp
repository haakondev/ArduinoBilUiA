#include <Arduino.h>
#include "calculations/calculations.h"
#include "parameters/pins.h"
#include "engine/engine.h"
#include "parameters/PID.h"
#include "parameters/physicalConstants.h"
#include "parameters/mode.h"
#include "PID/PID.h"
#include "LDR/LDR.h"
#include "encoder/encoder.h"
#include "modeController/modeController.h"



// -------------------- GLOBAL VARIABLES --------------------

// Light sensor readings
int readLightRight = 0;
int readLightLeft = 0;
int startError = 0;
int startSum;

// -------------------- CLASS INSTANTIATIONS --------------------
calculations calculate;

encoder leftEncoder("left", ENCODER_LEFT_PIN);
encoder rightEncoder("left", ENCODER_RIGHT_PIN);

engine leftMotor("left", ENA, IN1, IN2);
engine rightMotor("right", ENB, IN3, IN4);

LDR leftLDR("leftLDR", LDR_LEFT_PIN);
LDR rightLDR("rightLDR", LDR_RIGHT_PIN);

PID anglePid(ANGLE_PID_KP, ANGLE_PID_KI, ANGLE_PID_KD);
PID speedPid(SPEED_PID_KP, SPEED_PID_KI, SPEED_PID_KD);

modeController modeController();

// -------------------- COUNT FUNCTIONS --------------------

unsigned long previousTime = 0;
unsigned long lastTime = 0;

volatile unsigned long lastPulseTimeVenstre = 0;
volatile unsigned long pulseIntervalVenstre = 0;
volatile unsigned long lastPulseTimeHoyre = 0;
volatile unsigned long pulseIntervalHoyre = 0;

float leftWheelSpeedArc = 0.0;
float rightWheelSpeedArc = 0.0;

void countLeftEncoder() {
    leftEncoder.countInterrupt(millis());
    unsigned long currentTime = micros();  // Current time in microseconds
    pulseIntervalVenstre = currentTime - lastPulseTimeVenstre;
    lastPulseTimeVenstre = currentTime;
}

void countRightEncoder() {
    rightEncoder.countInterrupt(millis());
    unsigned long currentTime = micros();  // Current time in microseconds
    pulseIntervalHoyre = currentTime - lastPulseTimeHoyre;
    lastPulseTimeHoyre = currentTime;
}

float targetArcDistance = 0.0;

// -------------------- SETUP FUNCTION --------------------
void setup() {
    Serial.begin(115200);

    // Initialize pulse sensor pins
    attachInterrupt(digitalPinToInterrupt(leftEncoder.getPin()), countLeftEncoder, CHANGE);
    attachInterrupt(digitalPinToInterrupt(rightEncoder.getPin()), countRightEncoder, CHANGE);

    // Initialize motor pins
    pinMode(leftMotor.getPinInOne(), OUTPUT);
    pinMode(leftMotor.getPinInTwo(), OUTPUT);
    pinMode(rightMotor.getPinInOne(), OUTPUT);
    pinMode(rightMotor.getPinInTwo(), OUTPUT);

    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);

    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);

    // Initialize light resistor pins
    pinMode(rightLDR.getPin(), INPUT);
    pinMode(leftLDR.getPin(), INPUT);

    // Calculate initial light sensor error
    startError = (analogRead(leftLDR.getPin()) - analogRead(rightLDR.getPin())) / 2;
    startSum = (analogRead(leftLDR.getPin()) + analogRead(rightLDR.getPin()));

    // Initialize mode-specific parameters
    if (MODE == "LINE") {
        leftMotor.drive(WANTED_SPEED_BITS_LINE, false, true);
        rightMotor.drive(WANTED_SPEED_BITS_LINE, true, true);
    } else if (MODE == "ARC") {
        leftWheelSpeedArc = calculate.ArcWheelSpeed(true, ARC_TURN_RADIUS, WHEEL_DISTANCE, ARC_WANTED_SPEED);
        rightWheelSpeedArc = calculate.ArcWheelSpeed(false, ARC_TURN_RADIUS, WHEEL_DISTANCE, ARC_WANTED_SPEED);
        leftMotor.drive(ARC_WANTED_SPEED_BITS, true, true);
        rightMotor.drive(ARC_WANTED_SPEED_BITS, true, true);
    }
}

// -------------------- LOOP FUNCTION --------------------
void loop() {
    if (MODE == "FOLLOW") {
        modeController().followMode(calculate, leftEncoder, rightEncoder, leftMotor, rightMotor, leftLDR, rightLDR, anglePid, speedPid, startError, startSum);
    } else if (MODE == "LINE") {
        modeController().lineMode(calculate, leftEncoder, rightEncoder, leftMotor, rightMotor, leftLDR, rightLDR, anglePid, speedPid, startError, startSum);
    } else if (MODE == "ARC") {
        modeController().arcMode(calculate, leftEncoder, rightEncoder, leftMotor, rightMotor, leftLDR, rightLDR, anglePid, speedPid, startError, startSum, targetArcDistance, rightWheelSpeedArc, leftWheelSpeedArc);
    }
}



// -------------------- LINE MODE --------------------


// -------------------- ARC MODE --------------------

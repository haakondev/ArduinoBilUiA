#include <Arduino.h>
#include "calculations/calculations.h"
#include "parameters/pins.h"
#include "engine/engine.h"
#include "parameters/PID.h"
#include "parameters/physicalConstants.h"
#include "mode.h"


// -------------------- PIN DEFINITIONS --------------------

// Pulse counter pins

// Photoresistors

// -------------------- GLOBAL VARIABLES --------------------

// Light sensor readings
int readLightRight = 0;
int readLightLeft = 0;
int startError = 0;
int startSum;

// -------------------- CLASS INSTANTIATIONS --------------------
PID anglePid("anglePID", ANGLE_PID_KP, ANGLE_PID_KI, ANGLE_PID_KD, ANGLE_PID_MAX_INTEGRAL);
PID speedPid("speedPID", SPEED_PID_KP, SPEED_PID_KI, SPEED_PID_KD, SPEED_PID_MAX_INTEGRAL);

engine leftMotor("left", ENA, IN1, IN2);
engine rightMotor("right", ENB, IN3, IN4);

calculations calculate;

// -------------------- SETUP FUNCTION --------------------
void setup() {
    Serial.begin(115200);

    // Initialize pulse sensor pins
    pinMode(interruptPinLeft, INPUT_PULLUP);
    pinMode(interruptPinRight, INPUT_PULLUP);

    // Initialize motor pins
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENB, OUTPUT);

    // Initialize light resistor pins
    pinMode(lightRightPin, INPUT);
    pinMode(lightLeftPin, INPUT);

    // Calculate initial light sensor error
    startError = (analogRead(lightLeftPin) - analogRead(lightRightPin)) / 2;
    startSum = (analogRead(lightLeftPin) + analogRead(lightRightPin));

    // Attach interrupts

    // Initialize mode-specific parameters
}

// -------------------- LOOP FUNCTION --------------------
void loop() {
    if (MODE == "FOLLOW") {
        followMode();
    } else if (MODE == "LINE") {
        lineMode(LINE_TARGET_SPEED);
    } else if (MODE == "ARC") {
        arcMode(ARC_TURN_RADIUS * PI);
    }
}

// -------------------- FOLLOW MODE --------------------
void follow() {
    // --- Read sensors ---
    int ldrV = analogRead(ldrV_pin);                  // brightness = inverse of distance
    int ldrH_left = analogRead(ldrH_left_pin);
    int ldrH_right = analogRead(ldrH_right_pin);

    // --- Calculate errors ---
    float distanceError = targetBrightness - ldrV;    // Higher means you're too far
    float angleError = (float)(ldrH_left - ldrH_right); // Positive = veer right, Negative = veer left

    // --- Get PID outputs ---
    float baseSpeed = pidDist.calculate(0, distanceError);   // Try to get distanceError to 0
    float turnSpeed = pidAngle.calculate(0, angleError);     // Try to get angleError to 0

    // --- Combine motor outputs ---
    int motorL = constrain(baseSpeed - turnSpeed, 0, 255);
    int motorR = constrain(baseSpeed + turnSpeed, 0, 255);

    // --- Drive motors ---
    analogWrite(motorL_pin, motorL);
    analogWrite(motorR_pin, motorR);

    // --- Debug ---
    Serial.print("LDR V: "); Serial.print(ldrV);
    Serial.print(" | DistErr: "); Serial.print(distanceError);
    Serial.print(" | AngleErr: "); Serial.print(angleError);
    Serial.print(" | L: "); Serial.print(motorL);
    Serial.print(" R: "); Serial.println(motorR);
}

// -------------------- LINE MODE --------------------


// -------------------- ARC MODE --------------------

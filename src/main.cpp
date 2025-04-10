#include <Arduino.h>
#include "Engine/Engine.h"
#include "PEBSCounter/PEBS.h"
#include "PID/PID.h"
#include "parameters.h"
#include "LDR/LDR.h"
#include "calculator.h"

Engine MOTOR_HOYRE("Hoyre", 5, 6, 4);
PEBS TELLER_HOYRE("Hoyre", 2);
LDR LDR_HOYRE("Hoyre", A5);

Engine MOTOR_VENSTRE("Venstre", 9, 8, 7);
PEBS TELLER_VENSTRE("Venstre", 3);
LDR LDR_VENSTRE("Venstre", A4);


// BENNY OG JØLLE
/*
Engine MOTOR_HOYRE("Hoyre", 11, 5, 4);
PEBS TELLER_HOYRE("Hoyre", 2);
LDR LDR_HOYRE("Hoyre", A0);

Engine MOTOR_VENSTRE("Venstre", 9, 8, 7);
PEBS TELLER_VENSTRE("Venstre", 3);
LDR LDR_VENSTRE("Venstre", A1);
*/

PID speedPID("SpeedPID", SPEED_PID_KP, SPEED_PID_KI, SPEED_PID_KD, SPEED_PID_MAX_INTEGRAL);
PID anglePID("AnglePID", ANGLE_PID_KP, ANGLE_PID_KI, ANGLE_PID_KD, ANGLE_PID_MAX_INTEGRAL);

calculator calculate;

// Timing
unsigned long previousTime = 0;
unsigned long lastTime = 0;

volatile unsigned long lastPulseTimeVenstre = 0;
volatile unsigned long pulseIntervalVenstre = 0;
volatile unsigned long lastPulseTimeHoyre = 0;
volatile unsigned long pulseIntervalHoyre = 0;

void countTellerVenstre() {
    TELLER_VENSTRE.countInterrupt(millis());
    unsigned long currentTime = micros();  // Current time in microseconds
    pulseIntervalVenstre = currentTime - lastPulseTimeVenstre;
    lastPulseTimeVenstre = currentTime;
}

void countTellerHoyre() {
    TELLER_HOYRE.countInterrupt(millis());
    unsigned long currentTime = micros();  // Current time in microseconds
    pulseIntervalHoyre = currentTime - lastPulseTimeHoyre;
    lastPulseTimeHoyre = currentTime;
}


unsigned long start = 0;
void setup() {

    Serial.begin(9600);

    // Motor pins
    pinMode(MOTOR_VENSTRE.getPinInOne(), OUTPUT);
    pinMode(MOTOR_VENSTRE.getPinInTwo(), OUTPUT);
    pinMode(MOTOR_HOYRE.getPinInOne(), OUTPUT);
    pinMode(MOTOR_HOYRE.getPinInTwo(), OUTPUT);

    attachInterrupt(digitalPinToInterrupt(TELLER_HOYRE.getPin()), countTellerHoyre, CHANGE);
    attachInterrupt(digitalPinToInterrupt(TELLER_VENSTRE.getPin()), countTellerVenstre, CHANGE);

    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);

    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);


    MOTOR_HOYRE.drive(100, true, true);
    MOTOR_VENSTRE.drive(100, false, true);
    start = millis() + 500;

}



void lineMode(float targetSpeed) {
/*
        noInterrupts();
        long localLeftPulseCount = TELLER_VENSTRE.getCount() - TELLER_VENSTRE.getLastPulseCount();
        long localRightPulseCount = TELLER_HOYRE.getCount() - TELLER_HOYRE.getLastPulseCount();
        TELLER_VENSTRE.setLastPulseCount(TELLER_VENSTRE.getCount());
        TELLER_HOYRE.setLastPulseCount(TELLER_HOYRE.getCount());

        interrupts();

    */

    unsigned long now = millis();

    noInterrupts();
    unsigned long currentSpeedVenstre = 1000000.0 / pulseIntervalVenstre;
    unsigned long currentSpeedHoyre = 1000000.0 / pulseIntervalHoyre;
    interrupts();

        if (now > start) {




        Serial.print("Left Pulses per second: ");
        Serial.print(currentSpeedVenstre);
        Serial.println();
        Serial.print("Right Pulses per second: ");
        Serial.print(currentSpeedHoyre);
        Serial.println();



        // Use PID controllers to adjust motor speeds
        float pidLeft = speedPID.calculate(currentSpeedVenstre, LINE_TARGET_SPEED);
        float pidRight = speedPID.calculate(currentSpeedHoyre, LINE_TARGET_SPEED);

        int MOTOR_INPUT_HOYRE = constrain(LINE_TARGET_SPEED + pidRight, 0, 255);
        int MOTOR_INPUT_VENSTRE = constrain(LINE_TARGET_SPEED + pidLeft, 0, 255);

        MOTOR_VENSTRE.drive(MOTOR_INPUT_VENSTRE, false, true);
        MOTOR_HOYRE.drive(MOTOR_INPUT_HOYRE, true, true);

        LDR_HOYRE.read();
        LDR_VENSTRE.read();
    }


}

void loop() {
    lineMode(LINE_TARGET_SPEED);
}




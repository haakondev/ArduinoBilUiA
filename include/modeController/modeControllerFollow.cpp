#include <Arduino.h>
#include "calculations/calculations.h"
#include "encoder/encoder.h"
#include "engine/engine.h"
#include "LDR/LDR.h"
#include "PID/PID.h"

#include "parameters/mode.h"
#include "../src/parameters/global.h"

#include "modeController.h"

// --------------------- LINE MODE --------------------

void modeController::followMode(calculations &calculate,
              encoder &leftEncoder, encoder &rightEncoder,
              engine &leftMotor, engine &rightMotor,
              LDR &leftLDR, LDR &rightLDR,
              PID &anglePid, PID &speedPid, int startSum, int startError) {

    unsigned long now = millis();

    // --- Read sensors ---
    int ldrV = analogRead(leftLDR.getPin());
    int ldrH = analogRead(rightLDR.getPin());

    // --- Calculate errors ---
    float distance = calculate.distanceToCar(ldrV, ldrH, startSum);


    float angleError = ldrH - ldrV;
    float angleCorrection = anglePid.calculate(angleError, this->lastTime);


    float distanceError = FOLLOW_TARGET_DISTANCE - distance;
    float distanceCorrection = speedPid.calculate(distanceError, this->lastTime);

    // --- Combine motor outputs ---
    int motorL = constrain(distanceCorrection + angleCorrection * CONTROL_SENSITIVITY, -255, 255);
    int motorR = constrain(distanceCorrection - angleCorrection * CONTROL_SENSITIVITY, -255, 255);

    // --- Drive motors ---
    leftMotor.drive(motorL, motorL < 0, motorL >= 0);
    rightMotor.drive(motorR,motorR > 0, motorR >= 0);

    // --- Debug ---
    Serial.print("LDR V: "); Serial.print(ldrV);
    Serial.print(" | DistErr: "); Serial.print(distanceError);
    Serial.print(" | AngleErr: "); Serial.print(angleError);
    Serial.print(" | L: "); Serial.print(motorL);
    Serial.print(" R: "); Serial.println(motorR);
    this->lastTime = now;
}
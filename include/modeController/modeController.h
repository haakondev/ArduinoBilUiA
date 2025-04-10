#include <Arduino.h>
#include "calculations/calculations.h"
#include "encoder/encoder.h"
#include "engine/engine.h"
#include "LDR/LDR.h"
#include "PID/PID.h"

class modeController {
private:
    unsigned long lastTime = 0;
public:
    modeController() {

    }

    void lineMode(calculations &calculate,
                  encoder &leftEncoder, encoder &rightEncoder,
                  engine &leftMotor, engine &rightMotor,
                  LDR &leftLDR, LDR &rightLDR,
                  PID &anglePid, PID &speedPid, int startSum, int startError);

    void arcMode(calculations &calculate,
                 encoder &leftEncoder, encoder &rightEncoder,
                 engine &leftMotor, engine &rightMotor,
                 LDR &leftLDR, LDR &rightLDR,
                 PID &anglePid, PID &speedPid, int startSum, int startError, float targetArcDistance, float rightWheelSpeedArc, float leftWheelSpeedArc);

    void followMode(calculations &calculate,
                    encoder &leftEncoder, encoder &rightEncoder,
                    engine &leftMotor, engine &rightMotor,
                    LDR &leftLDR, LDR &rightLDR,
                    PID &anglePid, PID &speedPid, int startSum, int startError);


};

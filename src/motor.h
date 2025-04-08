
#ifndef MOTOR_H
#define MOTOR_H

class Motor {
    private:
        int pin;
        int in1;
        int in2;
        String name;

    public:

        //Constructor
        Motor(String motorName, int pinEn, int inOne, int inTwo) {
            pin = pinEn;
            in1 = inOne;
            in2 = inTwo;
            name = motorName;
        }

        void drive(int speed, bool direction, bool run) {
            if (!run) {
                analogWrite(pin, 0);
                digitalWrite(in1, LOW);
                digitalWrite(in2, LOW);
                Serial.println("Motor " + name + " has now stopped.");
                return;
            }
            if (direction) {
                digitalWrite(in1, LOW);
                digitalWrite(in2, HIGH);
                analogWrite(pin, speed);
                Serial.println("Motor " + name + " is now going backwards.");
            }
            else {
                digitalWrite(in1, HIGH);
                digitalWrite(in2, LOW);
                analogWrite(pin, speed);
                Serial.println("Motor " + name + " is now going forwards.");
            }
        }

        // Setter & Getter pin EN(A/B)
        void setPinEn(int pinEn) {
            Serial.println("You set in1 to pin EN(A/B) " + String(pinEn));
            pin = pinEn;
        }

        int getPinEn() {
            Serial.println("pin EN(A/B) is " + String(pin));
            return pin;
        }

        // Setter & Getter in1
        void setPinInOne(int pin) {
            Serial.println("You set in1 to pin " + String(pin));
            in1 = pin;
        }


        int getPinInOne() {
            Serial.println("in1 is " + String(in1));
            return in1;
        }

        // Setter & Getter in2
        void setPinInTwo(int pin) {
            Serial.println("You set in2 to pin " + String(pin));
            in2 = pin;
        }

        int getPinInTwo() {
            Serial.println("in2 is " + String(in2));
            return in2;
        }



};



#endif //MOTOR_H

#include <Arduino.h>


class Motor {
    private:
        int enginePin;
        int in1;
        int in2;
        String name;

    public:

        //Constructor
        Motor(String name, int enginePin, int in1, int in2) {
            this->enginePin = enginePin;
            this->in1 = in1;
            this->in2 = in2;
            this->name = name;
        }

        void drive(int speed, bool backward, bool run) {
            if (!run) {
                analogWrite(enginePin, 255);
                digitalWrite(in1, LOW);
                digitalWrite(in2, LOW);
                Serial.println("Motor " + name + " has now stopped.");
                return;
            }
            if (backward) {
                digitalWrite(in1, LOW);
                digitalWrite(in2, HIGH);
                analogWrite(enginePin, speed);
                Serial.println("Motor " + name + " is now going backwards.");
            }
            else {
                digitalWrite(in1, HIGH);
                digitalWrite(in2, LOW);
                analogWrite(enginePin, speed);
                Serial.println("Motor " + name + " is now going forwards.");
            }
        }

        void brake() {
            analogWrite(enginePin, 255);
            digitalWrite(in1, HIGH);
            digitalWrite(in2, HIGH);
            Serial.println("Motor " + name + " is now braking.");
        }

        void stop() {
            analogWrite(enginePin, 0);
            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
            Serial.println("Motor " + name + " has now stopped.");
        }

        // Setter & Getter pin EN(A/B)
        void setEnginePin(int pinEn) {
            Serial.println("You set in1 to pin EN(A/B) " + String(pinEn));
            enginePin = pinEn;
        }

        int getEnginePin() {
            Serial.println("pin EN(A/B) is " + String(enginePin));
            return enginePin;
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

        // Setter & Getter name
        void setName(String motorName) {
            Serial.println("You set name to " + motorName);
            name = motorName;
        }

        String getName() {
            Serial.println("name is " + name);
            return name;
        }


};

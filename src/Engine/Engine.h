#include <Arduino.h>

/**
 * @class Engine
 * @brief Represents a motor engine with control for speed, direction, and state.
 */
class Engine {
private:
    int enginePin; ///< Pin for motor speed control (EN pin).
    int in1;       ///< Pin for motor direction control (Input 1).
    int in2;       ///< Pin for motor direction control (Input 2).
    String name;   ///< Name of the motor.

public:
    /**
     * @brief Constructor for the Engine class.
     * @param name The name of the motor.
     * @param enginePin The pin used for motor speed control.
     * @param in1 The pin used for motor direction control (Input 1).
     * @param in2 The pin used for motor direction control (Input 2).
     */
    Engine(String name, int enginePin, int in1, int in2) {
        this->name = name;
        this->enginePin = enginePin;
        this->in1 = in1;
        this->in2 = in2;
    }

    /**
     * @brief Drives the motor with the specified speed, direction, and state.
     * @param speed The speed of the motor (0-255).
     * @param backward Whether the motor should run backward.
     * @param run Whether the motor should run or stop.
     */
    void drive(int speed, bool backward, bool run);

    /**
     * @brief Brakes the motor.
     */
    void brake();

    /**
     * @brief Stops the motor.
     */
    void stop();

    /**
     * @brief Sets the pin for motor speed control (EN pin).
     * @param pinEn The pin number to set.
     */
    void setEnginePin(int pinEn);

    /**
     * @brief Gets the pin for motor speed control (EN pin).
     * @return The pin number.
     */
    int getEnginePin();

    /**
     * @brief Sets the pin for motor direction control (Input 1).
     * @param pin The pin number to set.
     */
    void setPinInOne(int pin);

    /**
     * @brief Gets the pin for motor direction control (Input 1).
     * @return The pin number.
     */
    int getPinInOne();

    /**
     * @brief Sets the pin for motor direction control (Input 2).
     * @param pin The pin number to set.
     */
    void setPinInTwo(int pin);

    /**
     * @brief Gets the pin for motor direction control (Input 2).
     * @return The pin number.
     */
    int getPinInTwo();

    /**
     * @brief Sets the name of the motor.
     * @param motorName The name to set.
     */
    void setName(String motorName);

    /**
     * @brief Gets the name of the motor.
     * @return The name of the motor.
     */
    String getName();
};
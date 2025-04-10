class PID {
private:
    float Kp, Ki, Kd;
    float prevError;
    float integral;
    unsigned long lastTime;

public:
    PID(float kp, float ki, float kd);

    float calculate(float setpoint, float measuredValue);
    void reset();
};
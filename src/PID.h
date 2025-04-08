
#ifndef UNTITLED1_PID_H
#define UNTITLED1_PID_H


// KP, KI, KD, GoalDistance
int Kp = 0;
int Ki = 0;
int Kd = 0;

int GoalDistance = 20; // Cm
int TrueDistance = 0;


// Loop

// Mål distanse fra ledebil

// Proporsjonal = TrueDistance - Goal Distance

// Integral = Integral + feil(GoalDistance - TrueDistance)

// Derivert = Fart

// Speed = Proporsjonal * Kp + Integral * Ki + Derivert * Kd




#endif //UNTITLED1_PID_H

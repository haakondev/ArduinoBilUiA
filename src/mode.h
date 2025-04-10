// -------------------- MODE SELECTION --------------------
#define MODE "FOLLOW" // Options: "FOLLOW", "LINE", "ARC"

// -------------------- SPEED AND DISTANCE PARAMETERS --------------------

// Follow Mode
#define FOLLOW_TARGET_DISTANCE 0.5 // meters (desired distance to the car in front)

// Line Mode
#define LINE_TARGET_SPEED 0.7 // meters per second (straight-line target speed)
#define WANTED_SPEED_BITS_LINE 150      // PWM value for desired speed in line mode

// Arc Mode
#define ARC_TURN_RADIUS 1.0          // meters (desired turning radius)
#define ARC_WANTED_SPEED 0.7       // meters per second (desired speed for arc mode)
#define LEFT_OUTER true
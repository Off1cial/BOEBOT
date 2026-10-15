#ifndef BOBOT_H
#define BOBOT_H
#include <Servo.h>

// Arduino ints are 16 bits, short makes it 8
typedef unsigned short int pin_t; // 8 bits

typedef struct wheel_t
{
    Servo servo; 
    int value;
} wheel_t;

typedef struct bobot_t
{
    wheel_t wheels[2];
} boebot_t;


enum wheelindex_t
{
    BWHEEL_LEFT = 0,
    BWHEEL_RIGHT = 1,
};

// Calibrated values so that the wheel motors receive a pulse of exactly 1500 microseconds, causing a complete stop
// Normally it receives a pulse of 1472 microseconds that makes it slowly move backwards
// The default limits are 544 - 2400
//
// Pulse width = min + ( (value / 180 ) * (max - min) )
#define BWHEEL_MOTOR_MAX 2000 
#define BWHEEL_MOTOR_MIN 1000

// Stopping, clockwise and counter-clockwise motion
#define WHEEL_STOP 90
#define WHEEL_CW 0
#define WHEEL_CCW 180

void BOBOT_Init( boebot_t* bot, pin_t pin_leftwheel, pin_t pin_rightwheel );

/* 
 *
 *
 * @param bot:   pointer to the boebot memory
 * @param wheel_index:   BWHEEL_LEFT/RIGHT, index of the wheel you wish to move
 * @param drive:    floating point -1.0f to 1.0f value, backwards to forwards and anywhere inbetween
 *
 * */
void BOBOT_DriveWheel( boebot_t* bot, wheelindex_t wheel_index, float drive );
void BOBOT_DriveStraight( boebot_t* bot, float drive );

#endif

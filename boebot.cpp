#include "boebot.hpp"
#include "common.h"

#include <Arduino.h>

static inline void init_wheel( wheel_t* wheel, pin_t pin )
{
    if (!wheel){
        SerialMessage("init_wheel: cannot initialise NULL wheel\n");
        return;
    }
    wheel->value = 0;
    wheel->servo.attach( pin, BWHEEL_MOTOR_MIN, BWHEEL_MOTOR_MAX );
}

void BOBOT_Init( boebot_t* bot, pin_t pin_leftwheel, pin_t pin_rightwheel )
{
    init_wheel( &bot->wheels[BWHEEL_LEFT], pin_leftwheel );
    init_wheel( &bot->wheels[BWHEEL_RIGHT], pin_rightwheel );
}

void BOBOT_DriveWheel( boebot_t *bot, wheelindex_t wheel_index, float drive )
{
    int mov = ( drive + 1.0f ) * 90;
    bot->wheels[wheel_index].servo.write( mov );
}

void BOBOT_DriveStraight( boebot_t* bot, float drive )
{
    // I wonder if the number of cyles between each call can be large enough
    // to cause one wheel to move well before the other, or atleast after an amount of time
    // significant enough to affect the direction of the bot
    BOBOT_DriveWheel( bot, BWHEEL_RIGHT, drive );
    BOBOT_DriveWheel( bot, BWHEEL_LEFT, drive );
}

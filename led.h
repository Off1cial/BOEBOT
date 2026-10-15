#ifndef LED_H
#define LED_H

#include "common.h"
#include <Arduino.h>

typedef struct led_t
{
    int pin;
    unsigned char brightness; // 0 - 255
    unsigned long last_toggle; // For non-blocking blink behaviour
    bool active;
} led_t;

// magical C++ function overload
static inline void LED_SetBrightness( led_t* led, float fraction )
{
    if (!led) return;
    // Add bounds checking/clamping?
    float frac = fraction;
    clamp( 0.0f, 1.0f, &frac );
    led->brightness = (unsigned char)(frac * 255);
}

static inline void LED_SetBrightness( led_t* led, unsigned char brightness )
{
    if (!led) return;
    led->brightness = brightness;
}

static inline void LED_WriteOn( led_t* led )
{
    analogWrite( led->pin, led->brightness );
}

static inline void LED_WriteAnalogFraction( led_t* led, float fraction )
{
    if (!led) return;
    float frac = fraction;
    clamp(0.0f, 1.0f, &frac);

    analogWrite( led->pin, rnd_float_int(255.0f * frac) );
}

static inline void LED_WriteAnalogInteger( led_t* led, unsigned char brightness )
{
    if (!led) return;
    analogWrite( led->pin, brightness );
}





static inline void LED_WriteOff( led_t* led )
{
    analogWrite( led->pin, 0 );
}

static inline void LED_WriteState( led_t* led )
{
    analogWrite( led->pin, 255 * led->active );
}

static inline void LED_SetPin( led_t* led, int pin )
{
    if (!led) return;
    pinMode( pin, OUTPUT );
    led->pin = pin;
}

static inline void LED_Blink( led_t* led, unsigned long current_time, unsigned long delay_ms )
{
    if (current_time - led->last_toggle < delay_ms)
        return;

    led->last_toggle = current_time;
    led->active = !led->active;
    LED_WriteState( led );
}



#endif

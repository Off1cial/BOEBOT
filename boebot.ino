#include "led.h"

#include "boebot.hpp"

led_t led_red;
led_t led_green;
unsigned long current_time = 0;


void setup( void )
{
  LED_SetPin( &led_red, 11 );
  LED_SetBrightness( &led_red, 0.5f );

  LED_SetPin( &led_green, 10 );
  LED_SetBrightness( &led_green, 1.0f );
}


void loop( void )
{
  current_time = millis();
  LED_Blink( &led_red, current_time, 1000 );
  LED_Blink( &led_green, current_time, 500 );
}

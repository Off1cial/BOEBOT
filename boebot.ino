#include "led.h"
#include "common.h"
#include "boebot.hpp"

led_t led_red;
led_t led_green;
unsigned long current_time = 0;

boebot_t bot;

void setup( void )
{
  Serial.begin(9600);
  LED_SetPin( &led_red, 11 );
  LED_SetBrightness( &led_red, 1.0f );

  LED_SetPin( &led_green, 10 );
  LED_SetBrightness( &led_green, 1.0f );

}


void loop( void )
{
  current_time = millis();
  float phase = (current_time % 2000UL) * ( (2 * M_PI) / 2000.0f);
  int brightness = rnd_float_int(255.0f * (sinf(phase) + 1.0f) * 0.5f);
  //LED_Blink( &led_red, current_time, 1000 );
  //LED_Blink( &led_green, current_time, 500 );
  LED_WriteAnalogFraction( &led_red, (sinf(phase) + 1.0f) * 0.5f);
}

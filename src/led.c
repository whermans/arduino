#include "../inc/led.h"

void led_on(unsigned char port)
{
	DDRB |= _BV(port);
	PORTB |= _BV(port);
}

void led_off(unsigned char port)
{
	PORTB &= ~_BV(port);
}
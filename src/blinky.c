#include <avr/io.h>
#include "../inc/led.h"
#include "../inc/debug.h"

#ifndef F_CPU
#define F_CPU 16000000L
#endif

#include <util/delay.h>


void setup(void);
void loop(void);
void on(void);
void off(void);

int main(void)
{
	setup();
	for(;;)
	{
		loop();
	}
}

void setup(void)
{
	serial_init();
}

void loop(void)
{
	on();
	_delay_ms(250);
	off();
	_delay_ms(250);
	on();
	_delay_ms(250);
	off();
	_delay_ms(1250);
}

void on(void)
{
	debug_msg("LED on");
	led_on(PORTB5);
}

void off(void)
{
	debug_msg("LED off");
	led_off(PORTB5);
}
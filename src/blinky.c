#include <avr/io.h>
#include "../inc/led.h"

#define F_CPU 16000000L
#include <util/delay.h>


void setup(void);
void loop(void);

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

}

void loop(void)
{
	led_on(PORTB5);
	_delay_ms(1000);
	led_off(PORTB5);
	_delay_ms(1000);
	led_on(PORTB5);
	_delay_ms(5000);
	led_off(PORTB5);
	_delay_ms(1000);
}
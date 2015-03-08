#include "../inc/serial.h"

void serial_init(void)
{
	/* set baud rate high byte */
	UBRR0H = (unsigned char) (BAUD_SPECIFIC >> 8);
	/* set baud rate low byte */
	UBRR0L = (unsigned char) (BAUD_SPECIFIC);
	/* enable receiver and transmitter */
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	/* set 8-bit data frame size */
	UCSR0C = (3 << UCSZ00);
}

unsigned char serial_rx(void)
{
	/* wait until receive complete bit is set */
	while(!(UCSR0A & (1 << RXC0)));
	/* return received data byte */
	return UDR0;
}

void serial_tx(unsigned char byte)
{
	/* wait until tx ready bit is set */
	while(!(UCSR0A & (1 << UDRE0)));
	/* send data */
	UDR0 = byte;
}

void serial_print(char *txt)
{
	while(*txt != 0x00)
	{
		serial_tx(*txt);
		txt++;
	}
}

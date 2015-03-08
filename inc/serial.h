#ifndef INC_SERIAL_H_
#define INC_SERIAL_H_

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>

#define BAUD 9600
#define BAUD_SPECIFIC (((F_CPU / (BAUD * 16UL))) - 1)

void 			serial_init(void);
unsigned char 	serial_rx(void);
void 			serial_tx(unsigned char byte);
void 			serial_print(char *txt);

#endif
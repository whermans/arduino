#include "../inc/debug.h"

void debug_msg(char *txt)
{
	serial_print(txt);
	serial_print("\n");
}
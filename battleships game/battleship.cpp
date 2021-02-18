#include "battleship.h"
int battleship::serial = 0;
battleship::battleship()
{
	if (serial == 4) {
		length = 3;
	}
	else {
		length = (5 - serial);
	}
	serial++;
}


#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "tables.h"
#include "helper.h"
#include "ASES.h"

int main(int argc, char *argv[])
{
	 int32_t x0 = 0x00000001, x1 = 0x00000000, x2 = 0x00000000, x3 = 0x00000000;
	 int32_t values[4] = { x0, x1, x2, x3 };
	
	std::cin.ignore();

	int8_t test = 0xA2, res;

	res = t::calc_sbox(test);
	printf_s("%#2x - %#2x\n", test, res);

	system("PAUSE");

	return EXIT_SUCCESS;
}


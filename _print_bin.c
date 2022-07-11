#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_bin - Prints an int in binary
 * @b: unsigned int
 * Return: the binary
 */

int print_bin(va_list b)
{
	int bin, rm, i;
	unsigned int bb;

	bin = 0;
	rm = 0;
	i = 1;

	bb = va_arg(b, unsigned int);

	while (bb != 0)
	{
	rm = bb % 2;
	bb /= 2;
	bin += rm * i;
	i *= 10;
	}

	print_string(itoa(bb));

	return (bb);
}

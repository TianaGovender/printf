#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_char - Prints a char
 * @c: char
 * Return: 1
 */

int print_char(va_list c)
{
	unsigned char ch;

	ch = va_arg(c, int);

	_putchar(ch);
	fflush(stdout);

	return (1);
}

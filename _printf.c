#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - acts as printf
 * @format: char
 * Return: num of char printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int numc = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	numc = find_f(format, args);

	va_end(args);

	return (numc);
}

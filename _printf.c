#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char * const format, ...);

/**
 * _printf - acts as printf
 * @format: char
 * Return: num of char printed
 */

int _printf(const char * const format, ...)
{
	va_list args;
	int i, numc, s;
	char *ss;

	i = 0;
	numc = 0;

	va_start(args, format);

	while (format != NULL && format[i] != '\0')
	{
		if (format[i] != '%' && format[i + 1] != 's' && format[i + 1] != 'c')
		{
			_putchar(format[i]);
			numc++;
		}

		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					s = va_arg(args, int);

					_putchar(s);
					i++;
					numc++;
					break;
				case 's':
					ss = va_arg(args, char *);

					print_string(ss);
					i++;
					numc++;
					break;
			}
		}

		i++;

	}

	va_end(args);

	_putchar('\n');

	return (numc);
}

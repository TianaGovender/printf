#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char * const format, ...);

/**
 * find_f - finds the relevant funct for the format
 * @format: char
 * Return: 0
 */

int (*find_f(const char *format))(va_list)
{
	unsigned int i;
	code_format f_fun[] = {
		{"c", print_char},
		{"s", print_string},
		{NULL, NULL}
	};

	i = 0;
	while (f_fun[i].cf)
	{
		if (f_fun[i].cf[0] == (*format))
		{
			return (f_fun[i].f);
		}
		i++;
	}

	return (NULL);
}

/**
 * _printf - acts as printf
 * @format: char
 * Return: num of char printed
 */

int _printf(const char * const format, ...)
{
	va_list args;
	int (*f)(va_list);
	unsigned int i, numc;

	i = 0;
	numc = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			numc++;
			i++;
		}

		if (format[i] == '\0')
			return (numc);

		f = find_f(&format[i + 1]);

		if (f != NULL)
		{
			numc = numc + f(args);
			i = i + 2;
			continue;
		}

		if (!format[i + 1])
			return (-1);

		_putchar(format[i]);
		numc++;

		if (format[i + 1] == '%')
		{
			i = i + 2;
		}
		else
		{
			i++;
		}
	}

	va_end(args);

	return (numc);
}

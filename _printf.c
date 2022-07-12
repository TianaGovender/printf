#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * find_f - finds the relevant funct for the format
 * @format: char
 * @args: list
 * Return: num of char
 */
int find_f(const char *format, va_list args)
{
	int i = 0, n, f_v, numc = 0;
	code_format f_fun[] = {
		{"c", print_char},
		{"s", print_string},
		{"b", print_bin},
		{"r", print_rev},
		{"R", print_rot},
		{NULL, NULL}
	};

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			n = 0;
			while (f_fun[n].cf != NULL)
			{
				if (format[i + 1] == f_fun[n].cf[0])
				{
					f_v = f_fun[n].f(args);
					if (f_v == -1)
						return (-1);
					numc = numc + f_v;
					break;
				}
				n++;
			}
			if (f_fun[n].cf == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					numc = numc + 2;
				}
				else
					return (-1);
			}
			i++;
		}
		else
		{
			_putchar(format[i]);
			numc++;
		}
		i++;
	}
	return (numc);
}
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

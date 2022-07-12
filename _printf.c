#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * find_f - finds the relevant funct for the format
 * @format: char
 * @args: list
 * @f_fun: struct
 * Return: num of char
 */
int find_f(const char *format, va_list args, code_format f_fun[])
{
	int i, n, f_v, numc = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (n = 0; f_fun[n].cf != NULL; n++)
			{
				if (format[i + 1] == f_fun[n].cf[0])
				{
					f_v = f_fun[n].f(args);
					if (f_v == -1)
						return (-1);
					numc = numc + f_v;
					break;
				}
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
	code_format f_fun[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int},
		{"d", print_int},
		{"b", print_bin},
		{"r", print_rev},
		{"R", print_rot},
		{"u", print_un_int},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_heX},
		{NULL, NULL}
	};
	va_list args;
	int numc = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	numc = find_f(format, args, f_fun);

	va_end(args);

	return (numc);
}

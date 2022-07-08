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
	int i, n, j, numc;
	char *str;
	const char tpe[] = "cifs";

	i = 0;
	numc = 0;

	va_start(args, format);

	while (format != NULL && format[i] != '\0')
	{
		n = 0;

		switch (format[i])
		{
			case 'i':
				print_string(va_arg(args, char*));
				n = 1;
				numc = numc + 1;
				break;
			case 'f':
				print_string(va_arg(args, char*));
				n = 1;
				numc = numc + 1;
				break;
			case 'c':
				print_string(va_arg(args, char *));
				n = 1;
				numc = numc + 1;
				break;
			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
				{
					print_string("(nil)");
					break;
				}
				n = 1;
				numc = numc + 1;
				print_string(str);
		}

		j = 0;

		while (tpe[j] != '\0')
		{
			if (n == 1 && format[i] == tpe[j] && format[i + 1] != '\0')
			{
				print_string(", ");
				break;
			}
			j++;
		}

		i++;
	}

	va_end(args);

	printf("\n");

	return (numc);
}

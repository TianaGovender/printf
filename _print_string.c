#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_string - Printts string
 * @s: string
 * Return: 0
 */

int print_string(va_list s)
{
	int i, len;
	char *str;

	str = va_arg(s, char *);
	if (str == NULL)
		str = "(null)";

	i = 0;
	len = _strlen(str);

	while (i < len)
	{
		_putchar(str[i]);
		fflush(stdout);
		i++;
	}

	return (i);
}

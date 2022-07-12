#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_rev - prints reversed str
 * @a: va_list
 * Return: int
 */

int print_rev(va_list a)
{
	int i;
	char *s, *p;

	s = va_arg(a, char *);
	if (s == NULL)
		return (-1);

	p = rev_str(s);
	if (p == NULL)
	{
		return (-1);
	}

	i = 0;
	while (p[i] != '\0')
	{
		_putchar(p[i]);
		i++;
	}

	return (i);
}

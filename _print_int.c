#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_int - Prints an integer
 * @i: va_list
 * Return: len
 */

int print_int(va_list i)
{
	int len;

	len = print_num(i);

	return (len);
}

/**
 * print_un_int - prints unsigned int
 * @i: va_list
 * Return: len
 */

int print_un_int(va_list i)
{
	unsigned int n;

	n = va_arg(i, unsigned int);

	if (n == 0)
		return (print_un_num(n));

	if (n < 1)
		return (-1);

	return (print_un_num(n));
}

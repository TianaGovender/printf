#include "main.h"

/**
 * print_num - prints a num
 * @n: va_list
 * Return: int
 */

int print_num(va_list n)
{
	int i, d, len;
	unsigned int num;

	i = va_arg(n, int);
	d = 1;
	len = 0;

	if (i < 0)
	{
		len += _putchar('-');
		num = i * -1;
	}
	else
		num = i;

	for (; num / d > 9; )
		d *= 10;

	for (; d != 0; )
	{
		len += _putchar('0' + num / d);
		num %= d;
		d /= 10;
	}

	return (len);
}

/**
 * print_un_num - prints unsigned num
 * @n: unsigned int
 * Return: int
 */

int print_un_num(unsigned int n)
{
	int d, len;
	unsigned int num;

	d = 1;
	len = 0;
	num = n;

	for (; num / d > 9; )
	{
		d *= 10;
	}

	for (; d != 0; )
	{
		len += _putchar('0' + num / d);
		num %= d;
		d /= 10;
	}

	return (len);
}

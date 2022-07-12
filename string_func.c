#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * b_len - len of octo
 * @n: int
 * @base: int
 * Return: int len
 */

int b_len(unsigned int n, int base)
{
	unsigned int i = 0;

	while (n > 0)
	{
		n = n / base;
		i++;
	}

	return (i);
}

/**
 * print_b - print str
 * @s: char
 */

void print_b(char *s)
{
	int i;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}

/**
 * rev_str - reverses str
 * @s: char
 * Return: reversed string
 */

char *rev_str(char *s)
{
	int len, i;
	char tmp, *d;

	len = _strlen(s);

	d = malloc(sizeof(char) * len + 1);
	if (d == NULL)
		return (NULL);

	_memcpy(d, s, len);

	i = 0;
	while (i < len)
	{
		tmp = d[len - 1];
		d[len - 1] = d[i];
		d[i] = tmp;
		i++;
		len--;
	}

	return (d);
}

/**
 * _memcpy - copies
 * @d: char
 * @s: char
 * @n: int
 * Return: (d)
 */

char *_memcpy(char *d, char *s, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		d[i] = s[i];
		i++;
	}

	d[i] = '\0';

	return (d);
}

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_rot - Prints string in rot13
 * @R: va_list
 * Return: int
 */

int print_rot(va_list R)
{
	int i, j;
	char *s;
	char c[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(R, char *);
	if (s == NULL)
		return (-1);

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (j <= 52)
		{
			if (s[i] == c[j])
			{
				_putchar(u[j]);
				break;
			}
			j++;
		}

		if (j == 53)
		{
			_putchar(s[i]);
		}
		i++;
	}
	
	return (i);
}

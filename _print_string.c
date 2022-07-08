#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * print_string - Printts string
 * @s: string
 */

void print_string(char *s)
{
	int i, len;

	len = _strlen(s);
	i = 0;

	while (i < len)
	{
		_putchar(s[i]);
		fflush(stdout);
		i++;
	}
}

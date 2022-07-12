#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strlen - finds len of string
 * @s: string
 * Return: int
 */

int _strlen(char *s)
{
	int c = 0;

	while (s[c] != '\0')
	{
		c++;
	}

	return (c);
}

#include <unistd.h>
#include <stdio.h>

/**
 * _putchar - prints char
 * @c: char
 * Return: 1 On success
 * on error returns -1
 */

int _putchar(char c)
{
	static char buf[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buf, i);
		i = 0;
	}

	if (c != -1)
	{
		buf[i] = c;
		i++;
	}

	return (1);
}

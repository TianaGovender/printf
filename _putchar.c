#include <unistd.h>

/**
 * _putchar - prints char
 * @c: char
 * Return: 1 On success
 * on error returns -1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

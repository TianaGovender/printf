#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * print_bin - Prints an int in binary
 * @b: unsigned int
 * Return: the binary
 */
int print_bin(va_list b)
{
	int len, i;
	unsigned int bb;
	char *s, *rs;

	bb = va_arg(b, unsigned int);
	if (bb == 0)
		return (_putchar('0'));
	if (bb < 1)
		return (-1);
	len = b_len(bb, 2);
	s = malloc(sizeof(char) * len + 1);
	if (s == NULL)
		return (-1);
	for (i = 0; bb > 0; i++)
	{
		if (bb % 2 == 0)
			s[i] = '0';
		else
			s[i] = '1';
		bb = bb / 2;
	}
	s[i] = '\0';
	rs = rev_str(s);
	if (rs == NULL)
		return (-1);
	print_b(rs);
	free(s);
	free(rs);
	return (len);
}

#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int hex_check(int, char);

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

/**
 * print_octal - Prints the numeric representation of a number in octal base
 * @list: List of all the arguments passed to the program
 * Return: Number of symbols printed to stdout
 */
int print_octal(va_list list)
{
	unsigned int num;
	int len;
	char *octal_rep;
	char *rev_str;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = b_len(num, 8);

	octal_rep = malloc(sizeof(char) * len + 1);
	if (octal_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		octal_rep[len] = (num % 8) + 48;
		num = num / 8;

	}
	octal_rep[len] = '\0';
	rev_str = rev_str(octal_rep);
	if (rev_str == NULL)
		return (-1);

	print_b(rev_str);
	free(octal_rep);
	free(rev_str);
	return (len);
}

/**
 * print_hex - Prints a representation of a decimal number on base16 lowercase
 * @list: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int print_hex(va_list list)
{
	unsigned int num;
	int len;
	int rem_num;
	char *hex_rep;
	char *rev_hex;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = b_len(num, 16);
	hex_rep = malloc(sizeof(char) * len + 1);
	if (hex_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, 'x');
			hex_rep[len] = rem_num;
		}
		else
			hex_rep[len] = rem_num + 48;
		num = num / 16;
	}
	hex_rep[len] = '\0';
	rev_hex = rev_str(hex_rep);
	if (rev_hex == NULL)
		return (-1);
	print_b(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (len);
}


/**
 * print_heX - Prints a representation of a decimal number on base16 Uppercase
 * @list: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int print_heX(va_list list)
{
	unsigned int num;
	int len;
	int rem_num;
	char *hex_rep;
	char *rev_hex;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = b_len(num, 16);
	hex_rep = malloc(sizeof(char) * len + 1);
	if (hex_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, 'X');
			hex_rep[len] = rem_num;
		}
		else
			hex_rep[len] = rem_num + 48;
		num = num / 16;
	}
	hex_rep[len] = '\0';
	rev_hex = rev_str(hex_rep);
	if (rev_hex == NULL)
		return (-1);
	print_b(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (len);
}

/**
 * hex_check - Checks which hex function is calling it
 * @num: Number to convert into letter
 * @x: Tells which hex function is calling it
 * Return: Ascii value for a letter
 */
int hex_check(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (Hex[num]);
	return (0);
}

#ifndef _MAIN_
#define _MAIN_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int _putchar(char c);
int _strlen(char *s);
int b_len(unsigned int n, int base);
void print_b(char *s);
char *rev_str(char *s);
char *_memcpy(char *d, char *s, unsigned int);
int print_char(va_list c);
int print_string(va_list s);
int print_bin(va_list b);
int print_octal(va_list list);
int print_hex(va_list list);
int print_heX(va_list list);
int print_rot(va_list R);
int print_rev(va_list a);
int print_un_int(va_list i);
int print_int(va_list i);
int print_un_num(unsigned int n);
int print_num(va_list n);
int _printf(const char *format, ...);

/**
 * struct c_format - finding format
 * @cf: char
 * @f: functions
 */

typedef struct c_format
{
	char *cf;
	int (*f)(va_list);
} code_format;


int find_f(const char *format, va_list args, code_format f_fun[]);
#endif

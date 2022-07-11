#ifndef _MAIN_
#define _MAIN_

int _putchar(char c);
int _strlen(char *s);
int print_char(va_list c);
int print_string(va_list s);
int _printf(const char * const format, ...);

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

#endif

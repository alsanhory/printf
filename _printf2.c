#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
/**
 * _putchar - to simplify the function of print
 * @c: the passed character
 * Return: the result
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * print_char - to print characters
 * @args: the arguments
 */
void print_char(va_list args)
{
	char ch = va_arg(args, int);

	_putchar(ch);
}
/**
 * print_string - to print the string
 * @args: the arguments
 */
void print_string(va_list args)
{
	char *str = va_arg(args, char *);

	while (*str)
	{
		_putchar(*str);
		str++;
	}
}
/**
 * _printf - the main required printf
 * @format: the passed data
 * Return: the result
 */
int _printf(const char *format, ...)
{
	int chr = 0;
	va_list args;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			chr++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				print_char(args);
				chr++;
			}
			else if (*format == 's')
			{
				print_string(args);
				chr += strlen(va_arg(args, char *));
			}
		}
		format++;
	}

	va_end(args);
	return (chr);
}

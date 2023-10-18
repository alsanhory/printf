#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - custom printf function
 * @format: format string
 * Return: number of arguments
 */
int _printf(const char *format, ...)
{
	int char_count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			char_count++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);
				putchar(c);
				char_count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				if (str != NULL)
				{
					while (*str)
					{
						putchar(*str);
						char_count++;
						str++;
					}
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				char_count++;
			}
		}
		format++;
	}

	va_end(args);

	return (char_count);
}

#include "main.h"
/**
 * print_string - to support
 * @c: the string
 * Return: the number
 */
int print_string(char *c)
{
	int count = 0;

	if (c)
	{
		for (count = 0; c[count] != '\0'; count++)
		{
			putchar(c[count]);
		}
	}
	return (count);
}
/**
 * _printf - the required furnction
 * @format: format
 * Return: num
 */
int _printf(const char *format, ...)
{
	unsigned int i, ccount, count = 0;

	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
		}
		else if (format[i + 1] == 'c')
		{
			putchar(va_arg(args, int));
			i++;
		}
		else if (format[i + 1] == 's')
		{
			ccount = print_string(va_arg(args, char *));
			i++;
			count += (ccount + 1);
		}
		else if (format[i + 1] == '%')
		{
			putchar('%');
		}
		count += 1;
	}
	va_end(args);
	return (count);
}

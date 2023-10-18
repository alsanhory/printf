#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - custom printf function
 * @format: format string
 * Return: the number of characters printed
 */
int _putchar(char c)
{
        return (write(1, &c, 1));
}
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
                        _putchar(c[count]);
                }
        }
        return (count);
}
int _printf(const char *format, ...)
{
	int char_count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			char_count++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);
				_putchar(c);
				char_count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				if (str != NULL)
				{
					while (*str)
					{
						_putchar(*str);
						char_count++;
						str++;
					}
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				if (num < 0)
				{
					_putchar('-');
					char_count++;
					num = -num;
				}
				char_count += print_number(num);
			}
			else if (*format == 'u')
			{
				unsigned int num = va_arg(args, unsigned int);
				char_count += print_unsigned_number(num);
			}
			else if (*format == 'o')
			{
				unsigned int num = va_arg(args, unsigned int);
				char_count += print_octal_number(num);
			}
			else if (*format == 'x' || *format == 'X')
			{
				unsigned int num = va_arg(args, unsigned int);
				char_count += print_hex_number(num, (*format == 'X'));
			}
			else if (*format == 'p')
			{
				void *ptr = va_arg(args, void *);
				if (ptr != NULL)
				{
					char_count += print_pointer(ptr);
				}
				else
				{
					char_count += print_string("(nil)");
				}
			}
			else if (*format == '%')
			{
				_putchar('%');
				char_count++;
			}
		}
		format++;
	}

	va_end(args);

	return char_count;
}

int print_number(int num)
{
	int count = 0;
	if (num / 10)
	{
		count += print_number(num / 10);
	}
	_putchar('0' + num % 10);
	return count + 1;
}

int print_unsigned_number(unsigned int num)
{
	int count = 0;
	if (num / 10)
	{
		count += print_unsigned_number(num / 10);
	}
	_putchar('0' + num % 10);
	return count + 1;
}

int print_octal_number(unsigned int num)
{
	int count = 0;
	if (num / 8)
	{
		count += print_octal_number(num / 8);
	}
	_putchar('0' + num % 8);
	return count + 1;
}

int print_hex_number(unsigned int num, int uppercase)
{
	char hex_chars[16] = "0123456789abcdef";
	int count;

	if (uppercase)
	{
		hex_chars[10] = 'A';
		hex_chars[11] = 'B';
		hex_chars[12] = 'C';
		hex_chars[13] = 'D';
		hex_chars[14] = 'E';
		hex_chars[15] = 'F';
	}
	count = 0;
	if (num / 16)
	{
		count += print_hex_number(num / 16, uppercase);
	}
	_putchar(hex_chars[num % 16]);
	return count + 1;
}

int print_pointer(void *ptr)
{
	_putchar('0');
	_putchar('x');
	return print_hex_number((unsigned long)ptr, 0) + 2;
}


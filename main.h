#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_string(char *c);
int _putchar(char c);
int print_number(int num);
int print_unsigned_number(unsigned int num);
int print_octal_number(unsigned int num);
int print_hex_number(unsigned int num, int uppercase);
int print_pointer(void *ptr);

#endif /* MAIN_H */

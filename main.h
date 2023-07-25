#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

/**
 * struct printer - the structure for printing to stdout, given a specifier
 * @specifier: the specifier is  recognized by this printer
 * @run: its a to function to run when this printer is invoked
 */
typedef struct printer
{
	char *specifier;
	int (*run)(va_list);
} printer;

printer _get_printer(const char *specifier);
int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list);
int print_strr(va_list);
int print_dc_10(va_list);
int print_integer(va_list);
int print_bin(va_list);
int print_s_not_p(va_list);
int print_s_rev(va_list);
int print_rot_13(va_list);
int print_unsigned_int(va_list);
int print_oc_8(va_list);
int print_h_l(va_list);
int print_h_u(va_list);
int print_adresse(va_list);

#endif /* MAIN_H */

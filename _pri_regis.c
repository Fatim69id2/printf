#include "main.h"

/**
 * _get_printer - checks for a registered printer for a input specifier
 * @specifier: the specifier that will be printed for
 *
 * Return: the printer foundes
 */
printer _get_printer(const char *specifier)
{
	int cpt;
	static printer printers[] = {
		{"c", _print_char},
		{"s", _print_str},
		{"d", _print_decimal},
		{"i", _print_int},
		{"b", _print_binary},
		{"S", _print_str_nonprintable},
		{"r", _print_str_reverse},
		{"R", _print_rot13},
		{"u", _print_uint},
		{"o", _print_octal},
		{"x", _print_hex_lower},
		{"X", _print_hex_upper},
		{"p", _print_pointer},
		{NULL, NULL}
	};

	for (cpt = 0; printers[cpt].specifier != NULL; cpt++)
	{
		if (*specifier == *(printers[cpt].specifier))
			break;
	}

	return (printers[cpt]);
}

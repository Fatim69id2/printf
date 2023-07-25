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
		{"c", print_char},
		{"s", print_strr},
		{"d", print_dc_10},
		{"i", print_integer},
		{"b", print_bin},
		{"S", print_s_not_p},
		{"r", print_s_rev},
		{"R", print_rot_13},
		{"u", print_unsigned_int},
		{"o", print_oc_8},
		{"x", print_h_l},
		{"X", print_h_u},
		{"p", print_adresse},
		{NULL, NULL}
	};

	for (cpt = 0; printers[cpt].specifier != NULL; cpt++)
	{
		if (*specifier == *(printers[cpt].specifier))
			break;
	}

	return (printers[cpt]);
}

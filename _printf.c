#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: the size of the string
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * _printf - Prints anything
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	printer printer;
	int cpt = 0;
	int characters_printed = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[cpt])
	{
		for (; format[cpt] != '%' && format[cpt]; cpt++)
		{
			_putchar(format[cpt]);
			characters_printed++;
		}
		if (!format[cpt])
			return (characters_printed);
		if (format[cpt] == '%' && _strlen(format) == 1)
			return (-1);
		printer = _get_printer(&format[cpt + 1]);
		if (printer.specifier != NULL)
		{
			characters_printed += printer.run(args);
			cpt += 2;
			continue;
		}

		if (!format[cpt + 1])
			return (characters_printed);

		_putchar(format[cpt]);
		characters_printed++;

		if (format[cpt + 1] == '%')
			cpt += 2; /* move past the % */
		else
			cpt++;
	}
	va_end(args);
	return (characters_printed);
}

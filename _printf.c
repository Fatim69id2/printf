#include "main.h"

/**
 * _strlen - Length of a string
 * @s: String
 *
 * Return: Length of string
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * _printf - Prints function
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list valist;
	printer printer;
	int j = 0;
	int characters_printed = 0;

	if (format == NULL)
		return (-1);
	va_start(valist, format);
	while (format[j])
	{
		for (; format[j] != '%' && format[j]; j++)
		{
			_putchar(format[j]);
			characters_printed++;
		}
		if (!format[j])
			return (characters_printed);
		if (format[j] == '%' && _strlen(format) == 1)
			return (-1);
		printer = _get_printer(&format[j + 1]);
		if (printer.specifier != NULL)
		{
			characters_printed += printer.run(valist);
			j += 2;
			continue;
		}

		if (!format[j + 1])
			return (characters_printed);

		_putchar(format[j]);
		characters_printed++;

		if (format[j + 1] == '%')
			j += 2;
		else
			j++;
	}
	va_end(valist);
	return (characters_printed);
}

#include "main.h"
#include <unistd.h>
void print_buffer(char buffer[], int *buff_ind);
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

printer _get_printer(const char *specifier);

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
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

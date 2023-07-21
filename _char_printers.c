#include "main.h"

/**
 * hex_print - prints a char's ascii value in uppercase hex
 * @c: char to print
 *
 * Return: number of chars printed (always 2)
 */
static int hex_print(char c)
{
	int cpt;
	char dix = 'A' - ':';
	char d[2];

	d[0] = c / 16;
	d[1] = c % 16;
	for (cpt = 0; cpt < 2; cpt++)
	{
		if (d[cpt] >= 10)
			_putchar('0' + dix + d[cpt]);
		else
			_putchar('0' + d[cpt]);
	}
	return (cpt);
}

/**
 * _print_char - prints a character
 * @args: the arguments list
 *
 * Return: 1 (number of chars printed)
 */
int _print_char(va_list args)
{
	char ch = (char)va_arg(args, int);

	_putchar(ch);
	return (1);
}

/**
 * _print_str - prints a string
 * @args: the arguments list
 *
 * Return: the number of chars printed
 */
int _print_str(va_list args)
{
	int cpt;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	for (cpt = 0; str[cpt]; cpt++)
	{
		_putchar(str[cpt]);
	}
	return (cpt);
}
/**
 * _print_str_nonprintable - prints a string and nonprintable
 * character ascii values
 * @args: the arguments list
 *
 * Return: the number of chars printed
 */
int _print_str_nonprintable(va_list args)
{
	unsigned int i;
	int cpt = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			cpt += 2;
			cpt += hex_print(str[i]);
		}
		else
		{
			_putchar(str[i]);
			cpt++;
		}
	}
	return (cpt);
}
/**
 * _print_str_reverse - prints a string in reverse
 * @args: the arguments
 *
 * Return: the of number of chars printed
 */
int _print_str_reverse(va_list args)
{
	char *str;
	int i, cpt = 0;

	str = va_arg(args, char *);
	if (str == NULL)
		str = ")llun(";
	for (i = 0; str[i]; i++)
		;
	for (i -= 1; i >= 0; i--)
	{
		_putchar(str[i]);
		cpt++;
	}
	return (cpt);
}

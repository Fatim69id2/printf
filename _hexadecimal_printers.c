#include "main.h"

/**
 * _pow - calculates an exponent.
 * @base: base of exponent.
 * @exponent: exponent of number.
 *
 * Return: base expo.
 */
static unsigned long _pow(unsigned int base, unsigned int exponent)
{
	unsigned int i;
	unsigned long as = base;

	for (i = 1; i < exponent; i++)
	{
		as *= base;
	}
	return (as);
}

/**
 * print_hex - prints an unsigned int in hexidecimal form
 * @n: unsigned int to print
 * @c: flag to determine 0 = lower, 1 = upper
 *
 * Return: number of digits printed
 */
int print_hex(unsigned int n, unsigned int c)
{
	unsigned int a[8];
	unsigned int i, m, sum;
	char f;
	int cpt;

	m = 268435456; /* (16 ^ 7) */
	if (c)
		f = 'A' - ':';
	else
		f = 'a' - ':';
	a[0] = n / m;
	for (i = 1; i < 8; i++)
	{
		m /= 16;
		a[i] = (n / m) % 16;
	}
	for (i = 0, sum = 0, cpt = 0; i < 8; i++)
	{
		sum += a[i];
		if (sum || i == 7)
		{
			if (a[i] < 10)
				_putchar('0' + a[i]);
			else
				_putchar('0' + f + a[i]);
			cpt++;
		}
	}
	return (cpt);
}

/**
 * _print_hex_lower - takes an unsigned int and prints
 * it in lowercase hex notation
 * @args: arguments
 *
 * Return: number of digits printed
 */
int _print_hex_lower(va_list args)
{
	return (print_hex(va_arg(args, unsigned int), 0));
}

/**
 * _print_hex_upper - takes an unsigned int and prints it in
 * uppercase hex
 * @args: arguments
 *
 * Return: the number of digits printed
 */
int _print_hex_upper(va_list args)
{
	return (print_hex(va_arg(args, unsigned int), 1));
}

/**
 * _print_pointer - prints an address
 * @args: the arguments
 *
 * Return: the number of chars to print
 */
int _print_pointer(va_list args)
{
	int cpt = 0;
	unsigned int a[16];
	unsigned int i, sum;
	unsigned long n, m;
	char *str = "(nil)";

	n = va_arg(args, unsigned long);
	if (n == 0)
	{
		for (i = 0; str[i]; i++)
		{
			_putchar(str[i]);
			cpt++;
		}
		return (cpt);
	}
	_putchar('0');
	_putchar('x');
	cpt = 2;
	m = _pow(16, 15); /* 16 ^ 15 */
	a[0] = n / m;
	for (i = 1; i < 16; i++)
	{
		m /= 16;
		a[i] = (n / m) % 16;
	}
	for (i = 0, sum = 0; i < 16; i++)
	{
		sum += a[i];
		if (sum || i == 15)
		{
			if (a[i] < 10)
				_putchar('0' + a[i]);
			else
				_putchar('0' + ('a' - ':') + a[i]);
			cpt++;
		}
	}
	return (cpt);
}

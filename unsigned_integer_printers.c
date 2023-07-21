#include "main.h"

/**
 * _print_binary - its takes an unsigned int and prints it in binary notation
 * @args: the arguments list
 *
 * Return: this is the number of characters printed
 */
int _print_binary(va_list args)
{
	unsigned int n, m, i, summ;
	unsigned int a[32];
	int cpt;

	n = va_arg(args, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, summ = 0, cpt = 0; i < 32; i++)
	{
		summ += a[i];
		if (summ || i == 31)
		{
			_putchar('0' + a[i]);
			cpt++;
		}
	}
	return (cpt);
}
/**
 * _print_uint - prints an unsigned in decimal notation
 * @args: arguments
 *
 * Return: the number of digits printed
 */
int _print_uint(va_list args)
{
	unsigned int a[10];
	unsigned int i, m, n, summ;
	int cpt;

	n = va_arg(args, unsigned int);
	m = 1000000000; /* (10 ^ 9) */
	a[0] = n / m;
	for (i = 1; i < 10; i++)
	{
		m /= 10;
		a[i] = (n / m) % 10;
	}
	for (i = 0, summ = 0, cpt = 0; i < 10; i++)
	{
		summ += a[i];
		if (summ || i == 9)
		{
			_putchar('0' + a[i]);
			cpt++;
		}
	}
	return (cpt);
}

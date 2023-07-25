#include "main.h"

/**
 * print_dc_10 - prints a decimal number.
 * @args: arguments
 *
 * Return: number of chars
 */
int print_dc_10(va_list args)
{
	int a[10];
	int j, m, n, sum, cpt;

	n = va_arg(args, int);
	cpt = 0;
	m = 1000000000;
	a[0] = n / m;
	for (j = 1; j < 10; j++)
	{
		m /= 10;
		a[j] = (n / m) % 10;
	}
	if (n < 0)
	{
		_putchar('-');
		cpt++;
		for (j = 0; j < 10; j++)
			a[j] *= -1;
	}
	for (j = 0, sum = 0; j < 10; j++)
	{
		sum += a[j];
		if (sum != 0 || j == 9)
		{
			_putchar('0' + a[j]);
			cpt++;
		}
	}

	return (cpt);
}

/**
 * print_integer - prints an integer
 * @args: the arguments list
 *
 * Return: number of chars printed
 */
int print_integer(va_list args)
{
	int a[10];
	int j, m, n, sum, cpt;

	n = va_arg(args, int);
	cpt = 0;
	m = 1000000000;
	a[0] = n / m;
	for (j = 1; j < 10; j++)
	{
		m /= 10;
		a[j] = (n / m) % 10;
	}
	if (n < 0)
	{
		_putchar('-');
		cpt++;
		for (j = 0; j < 10; j++)
			a[j] *= -1;
	}
	for (j = 0, sum = 0; j < 10; j++)
	{
		sum += a[j];
		if (sum != 0 || j == 9)
		{
			_putchar('0' + a[j]);
			cpt++;
		}
	}
	return (cpt);
}
/**
 * print_oc_8 - takes an unsigned int and prints it in octal notation
 * @args:the arguments
 *
 * Return:the number of digits printed
 */
int print_oc_8(va_list args)
{
	unsigned int a[11];
	unsigned int i, m, n, sum;
	int cpt;

	n = va_arg(args, unsigned int);
	m = 1073741824; /* (8 ^ 10) */
	a[0] = n / m;
	for (i = 1; i < 11; i++)
	{
		m /= 8;
		a[i] = (n / m) % 8;
	}
	for (i = 0, sum = 0, cpt = 0; i < 11; i++)
	{
		sum += a[i];
		if (sum || i == 10)
		{
			_putchar('0' + a[i]);
			cpt++;
		}
	}
	return (cpt);
}

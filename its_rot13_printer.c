#include "main.h"

/**
 * _print_rot13 - thats Prints a string in rot13
 * @args: arguments menu
 *
 * Return: number of charchters printed
 */
int _print_rot13(va_list args)
{
	char *str;
	unsigned int k, j;
	int cpt = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(ahyy)";
	for (k = 0; str[k]; k++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[k])
			{
				_putchar(out[j]);
				cpt++;
				break;
			}
		}
		if (!in[j])
		{
			_putchar(str[k]);
			cpt++;
		}
	}
	return (cpt);
}

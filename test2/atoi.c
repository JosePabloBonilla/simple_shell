#include "header.h"

/**
 * _atoi - convert string to integer
 * @str: input string
 * Return: int
 */
int _atoi(char *str)
{
	int i = 0; /* first digit index */
	int sign = 1; /* initialize sign as positive */
	int res = 0; /* initialize result */

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	while (str[i] != '\0')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}

	return (sign * i);
}

/**
 * print_number - print int with putchar
 * @n: int
 */
void print_number(int n)
{
	int tot;

	if (n < 0)
	{
		_putchar('-');
		tot = -n;
	}
	else
		tot = n;

	if (tot / 10)
		print_number(tot / 10);

	_putchar(tot % 10 + '0');
}

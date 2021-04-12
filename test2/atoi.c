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

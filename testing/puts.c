#include "header.h"

/**
 * _puts - prints a string
 * @str: string
 * Return: 1 on success
 */

void _puts(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

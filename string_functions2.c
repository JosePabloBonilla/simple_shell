#include "shell.h"

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

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strstr - find string inside a string
 * @haystack: string with everything
 * @needle: string to find
 * Return: matching substring, else null
 */

char *_strstr(char *haystack, char *needle)
{
	char *start;
	char *search;

	while (*haystack != '\0')
	{
		start = haystack;
		search = needle;

		while (*needle != '\0' && *search != '\0' && *search == *haystack)
		{
			haystack++;
			search++;
		}

		if (*search == '\0')
			return (start);
		haystack = start + 1;
	}
	return (0);
}

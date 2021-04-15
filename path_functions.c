#include "shell.h"

/**
 * _splitPATH - counts the number of PATH members
 * @str: pointer to string to count
 *
 * Return: number of PATH members
 */
int _splitPATH(char *str)
{
	int count, flags = 1, wordcount = 0;

	for (count = 0; str[count]; count++)
	{
		if (str[count] != ':' && flags == 1)
		{
			wordcount += 1;
			flags = 0;
		}
		if (str[count + 1] == ':')
		{
			flags = 1;
		}
	}
	return (wordcount);
}

/**
 * _PATHstrcmp - compares PATH with environ to find PATH value
 * @s1: pointer PATH string
 * @s2: pointer to environ string with actual value
 *
 * Return: 0 on success
 */
int _PATHstrcmp(const char *s1, const char *s2)
{
	int count;

	for (count = 0; s2[count] != '='; count++)
	{
		if (s1[count] != s2[count])
		{
			return (-1);
		}
	}
	return (0);
}

/**
 * _concat - concats user string with PATH member string and /
 * @tmp: static array to store concatenated string
 * @av: pointer to array of user strings
 * @tok: pointer to PATH token
 *
 * Return: 0 on success
 */
char *_concat(char *tmp, char **av, char *tok)
{
	int len = 0;

	_memset(tmp, 0, 256);

	len = _strlen(tok) + _strlen(av[0]) + 2;

	_strcat(tmp, tok);
	_strcat(tmp, "/");
	_strcat(tmp, av[0]);
	tmp[len - 1] = '\0';
	return (tmp);
}


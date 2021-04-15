#include "header.h"

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

/**
 * str_concat - concatenates two strings
 * @s1: string one
 * @s2: string two
 * Description - concatenate two strings
 * Return: pointer to new space containing the 2 strings, if not NULL
 */

char *str_concat(char *s1, char *s2)
{
	int i, l;
	char *new;

	if (s1 == NULL)
		s1 = "";

	i = _strlen(s1);

	if (s2 == NULL)
		s2 = "";

	l = _strlen(s2);

	new = malloc((sizeof(char) * (i + l) + 1));

	if (new == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		new[i] = s1[i];

	for (l = 0; s2[l] != '\0'; l++)
		new[i + l] = s2[l];

	new[i + l] = s2[l];
	return (new);
}

/**
 * _strchr - locates a character in a string
 * @src: source string
 * @c: character to search
 * Return: pointer to char
 */

char *_strchr(char *src, char c)
{
	int i;

	if (src == NULL)
	{
		return (NULL);
	}

	for (i = 0; src[i] != '\0'; i++)
	{
		if (src[i] == c)
		{
			return (&src[i]);
		}
	}

	if (src[i] == c)
	{
		return (&src[i]);
	}
	return (NULL);
}

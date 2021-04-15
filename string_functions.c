#include "shell.h"

/**
 * _wordcount - counts number of words in string
 * @str: pointer to string to count
 *
 * Return: number of words in string
 */
int _wordcount(char *str)
{
	int i, parseflag = 1, wc = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && parseflag == 1)
		{
			wc = wc + 1;
			parseflag = 0;
		}

		if (str[i + 1] == ' ')
		{
			parseflag = 1;
		}
	}
	return (wc);
}

/**
 * _strlen - show string length
 * @s: string
 * Return: length of string
 */
int _strlen(const char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _strdup - duplicates a string
 * @str: string to copy
 * Description - duplicate a string
 * Return: pointer to the duplicated string, if not NULL
 */
char *_strdup(char *str)
{
	int i;
	char *str2;

	if (str == NULL)
		return (NULL);

	str2 = malloc((_strlen(str)) * sizeof(char) + 1);

	if (str2 == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		str2[i] = str[i];

	return (str2);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string to compare
 * Return: -15 if s1 is less than s2, 0 if equal, 15 if s1 is greater
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}

	if (s1[i] == s2[i])
		return (0);
	return (s1[i] - s2[i]);
}

/**
 * _strcat - Function that concatenates two strings
 * @dest: Destination concatenated string.
 * @src: Source of origincal string to concat.
 *
 * Return: Pointer to resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	int v, w;

	v = 0;
	w = 0;

	for (; dest[v] != '\0'; v++)
	{
	}

	for (; src[w] != '\0'; w++, v++)
	{
		dest[v] = src[w];
	}
	dest[v] = '\0';

	return (dest);
}

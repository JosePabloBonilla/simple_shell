#include "header.h"

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
 * *_strcpy - copies string src to buffer pointed to by dest
 * @dest: string pointer
 * @src: buffer pointer
 * Return: dest pointer
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;

	while (i >= 0)
	{
		dest[i] = src[i];

		if (src[i] == '\0')
			return (dest);
		i++;
	}
	return (dest);
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

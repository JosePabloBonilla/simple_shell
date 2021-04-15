#include "shell.h"

/**
 * _env - prints the environ
 *
 * Return: 0 on success
 */
int _env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
	}
	return (0);
}

/**
 * tokenize - creates array of tokens based on user string
 * @buffer: pointer to user string
 *
 * Return: pointer to array of user strings
 */
char **tokenize(char *buffer)
{
	char *token = NULL;
	int i = 0, wordcount = 0;
	char *delimiter = " \n";
	char **av = NULL;

	wordcount = _wordcount(buffer);
	if (!wordcount)
	{
		return (NULL);
	}
	av = malloc((wordcount + 1) * sizeof(char *));
	if (av == NULL)
	{
		exit(1);
	}
	token = strtok(buffer, delimiter);
	while (token != NULL)
	{
		av[i] = _strdup(token);
		token = strtok(NULL, delimiter);
		i++;
	}
	av[i] = NULL;
	return (av);
}

/**
 * _memset - fills memory with a constant byte
 * @s: buffer
 * @b: constant byte b
 * @n: n bytes of memory area pointed by s
 *
 * Return: pointer to memory area of s.
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int v;

	v = 0;

	for (; v < n; v++)
	{
		s[v] = b;
	}
	return (s);
}

/**
 * _getenv - get environment variable
 * @var: command that user uses
 * Return: the environment variable
 */
char *_getenv(char *var)
{
	char *token;
	int i = 0;

	while (environ[i])
	{
		if (_strstr(environ[i], var) != 0)
		{
			token = _strstr(environ[i], "=");
			if (token[0] == '=')
			{
				return (token);
			}
		}
		i++;
	}
	return (0);
}


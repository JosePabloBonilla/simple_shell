#include "header.h"
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
				return (token);
		}
		i++;
	}
	return (0);
}

/**
 * path - get command line and give address
 * @comm_line: command that user uses
 * Return: address
 */
char *path(char *comm_line)
{
	struct stat st;
	char *path, *address, *comm;
	char *token, *pathdup;
	int i;

	pathdup = _strdup(_getenv("PATH"));
	comm = str_concat("/", comm_line);
	address = _strdup(comm_line);
	token = strtok(pathdup, ":");
	for (i = 0; token != NULL; i++)
	{
		path = str_concat(token, comm);
		if (stat(path, &st) == 0)
		{
			_free(&address);
			address = _strdup(path);
		}
		token = strtok(NULL, ":");
		_free(&path);
	}
	free(pathdup);
	_free(&comm);
	return (address);
}

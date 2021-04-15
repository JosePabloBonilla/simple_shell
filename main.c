#include "shell.h"

/**
 * main - programs that runs the shell
 *
 * Return: 0 on success
 */
int main(void)
{
	char *fullpathbuffer = NULL, *cpy = NULL, *buffer = NULL;
	char *PATH = NULL, **av = NULL;
	int exstat = 0;

	signal(SIGINT, SIG_IGN);
	PATH = _getenv("PATH");
	if (PATH == NULL)
	{
		return (-1);
	}
	while (1)
	{
		av = NULL;
		prompt();
		buffer = _read();
		if (*buffer != '\0')
		{
			av = tokenize(buffer);
			if (av == NULL)
			{
				free(buffer);
				continue;
			}
			fullpathbuffer = _fullpathbuffer(av, PATH, cpy);
			if (checkbuiltins(av, buffer, exstat) != 0)
			{
				continue;
			}
			exstat = _forkprocess(av, buffer, fullpathbuffer);
		}
		else
		{
			free(buffer);
		}
	}
	return (0);
}

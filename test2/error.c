#include "header.h"

/**
 * _perror - own perror function
 * @s: input error string
 */
void _perror(char *s)
{
	write(STDERR_FILENO, s, _strlen(s));
}

/**
 * print_error - print error cases
 * @err0: error string
 * @err1: error string
 * @status: shell status
 */
void print_error(char *err0, char *err1, int status)
{
	if (status == 0)
	{
		if (err1[0] == '/')
		{
			write(STDERR_FILENO, err1, _strlen(err1));
			write(STDERR_FILENO, ": 1: ", 5);
			write(STDERR_FILENO, err1, _strlen(err1));
			write(STDERR_FILENO, ": Syntax error: \"(\" unexpected\n", 32);
		}
		else
		{
			write(STDERR_FILENO, err0, _strlen(err0));
			write(STDERR_FILENO, ": 0: Can't open ", 16);
			write(STDERR_FILENO, err1, _strlen(err1));
			write(STDERR_FILENO, "\n", 1);
		}
	}
	else
	{
		write(STDERR_FILENO, err0, _strlen(err0));
		write(STDERR_FILENO, ": ", 2);
		print_number(status);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, err1, _strlen(err1));
		write(STDERR_FILENO, ": not found\n", 12);
	}
}

/**
 *
 */
void f_error(int argc, char *argv1, char *argv2, int process)
{
	if (argc > 1 && argv2[0] == '/')
	{
		print_error(argv1, argv2, process);
		exit(2);
	}
	else if (argc > 1)
	{
		print_error(argv1, argv2, process);
		exit(127);
	}
}

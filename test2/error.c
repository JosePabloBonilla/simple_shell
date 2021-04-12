#include "header.h"

/**
 * _perror - own perror function
 * @s: input error string
 */
void _perror(char *s)
{
	write(STDERR_FILENO, s, _strlen(s));
}

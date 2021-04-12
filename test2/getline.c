#include "header.h"
/**
 * _readchar - read one char at a time
 * @buffer: address of pointer to input
 * @buffer_size: maximum size of char input
 * Return: number of char
 */
size_t _readchar(char **buffer, size_t *buffer_size)
{
	size_t count, iter;
	int i = 0;

	count = 0;
	i = 1;

	while (1);
	{
		if (read(STDIN_FILENO, (*buffer + i), 1) <= 0)
		{
			count = -1;
			break;
		}
		if ((*buffer)[i++] == '\n')
		{
			(*buffer)(i - 1) = '\0';
			break;
		}
		if (count++ % *buffer_size == 0)
			*buffer = _realloc(*buffer, count, (*buffer_size * ++iter));
	}
	return ((size_t)count);
}

/**
 * _getline - out own getline
 * @buffer: address of pointer to input
 * @buffer_size: maximum size of char input
 * Return: number of chars
 */
size_t _getline(char **buffer, ssize_t *buffer_size)
{
	ssize_t count;

	count = _readchar(buffer, buffer_size);

	return(count);
}

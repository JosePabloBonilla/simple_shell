#include "header.h"

/**
 * _memcpy - copies memory area
 * @dest: memory destination
 * @src: memory source
 * @n: bytes to copy to dest
 * Return: pointer to memory
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	for (; n > 0; n--)
	{
		dest[n - 1] = src[n - 1];
	}

	return (dest);
}

/**
 * *_realloc - reallocates a memory block
 * @ptr: void pointer
 * @old_size: old memory size
 * @new_size: new memory size
 * Return: pointer to new size
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *ptr2 = NULL;

	if (ptr == NULL)
	{
		ptr2 = malloc(new_size);
		return (ptr2);
	}

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	ptr2 = malloc(new_size);

	_memcpy(ptr2, ptr, old_size);
	free(ptr);

	return (ptr2);
}

/**
 * _malloc - allocates memory, prints error message on error
 * @bytes: number of bytes to allocate
 * Return: pointer to memory allocated
 */
char *_malloc(int bytes)
{
	char *str;
	int i;

	str = malloc(bytes);
	if (str == NULL)
	{
		_perror("No Memory here\n");
		exit(1);
	}
	for (i = 0; i < bytes; i++)
		str[i] = '\0';
	return (str);
}

/**
 * _free - free and set the pointer to null
 * @ptr: pointer
 */
void _free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

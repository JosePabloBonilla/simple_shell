#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int _strlen(const char *s);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
void _puts(char *str);
int _atoi(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_malloc(int bytes);
void _free(char **ptr);
void _exec(char *name, char **buffer, char **buffercopy, char **tmp, int process);
void sighandler(void);
ssize_t _readchar(char **buffer, size_t *buffer_size);
ssize_t _getline(char **buffer, ssize_t *buffer_size);
void _perror(char *s);

#endif

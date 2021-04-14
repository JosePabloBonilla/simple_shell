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
char *_strstr(char *haystack, char *needle);
char *str_concat(char *s1, char *s2);
char *_strchr(char *src, char c);
int _putchar(char c);
void _puts(char *str);
int _atoi(char *str);
void print_number(int n);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_malloc(int bytes);
void _free(char **ptr);
void _exec(char *name, char **buffer, char **buffercopy, char **tmp, int process);
void sighandler(int sig);
ssize_t _readchar(char **buffer, size_t *buffer_size);
ssize_t _getline(char **buffer, size_t *buffer_size);
void _perror(char *s);
void print_error(char *err0, char *err1, int status);
void f_error(int argc, char *argv1, char *argv2, int process);
char *_getenc(char *var);
char *path(char *comm_line);

#endif

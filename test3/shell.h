#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

extern char **environ;

/* prompt_functions.c */
int prompt(void);
char *_read(void);
char *_fullpathbuffer(char **av, char *PATH, char *copy);
int checkbuiltins(char **av, char *buffer, int exitstatus);
int _forkprocess(char **av, char *buffer, char *fullpathbuffer);

/* string_functions.c */
int _wordcount(char *str);
int _strlen(const char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);

/* string_functions2.c */
void _puts(char *str);
int _putchar(char c);
char *_strstr(char *haystack, char *needle);

/* path_functions.c */
int _splitPATH(char *str);
int _PATHstrcmp(const char *s1, const char *s2);
char *_concat(char *tmp, char **av, char *tok);

/* other_functions.c */
int _env(void);
char **tokenize(char *buffer);
char *_memset(char *s, char b, unsigned int n);
char *_getenv(char *var);

#endif

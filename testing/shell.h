#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void print_prompt1(void);
void print_prompt2(void);
void _puts(char *str);
int _strlen(const char *s);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char _strcmp(char *s1, char *s2);
int _putchar(char c);

char *read_cmd(void);

#endif

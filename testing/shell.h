#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void print_prompt1(void);
void print_prompt2(void);

char *read_cmd(void);

#endif

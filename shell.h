#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>

#define MAX_LINE_LENGTH 1024

void print_prompt(void);
char main(void);
char *_strcat(char *dest, const char *source);
int _strcmp(char *first, char *second);
int _strlen(char *string);
int _strncmp(char *string1, char *string2, int n);
void free_grid(char **grid);
int func_exec(char **args);
void _printenv(void);
char *read_func(void);

#endif

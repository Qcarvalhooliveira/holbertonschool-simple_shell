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
#include <limits.h>
#include <signal.h>

extern char **environ;

int main(int argc, char **argv, char **environ);
char *_strcat(char *dest, char *src);
void free_grid(char **grid);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _putchar(char c);
void _puts(char *str);
int _strlen(char *string);
int _strncmp(char *string1, char *string2, int n);
void free_grid(char **grid);
int func_exec(char **parse);
char *_getenv(char **environ, char *dirname);
void _printenv(void);
char *read_func(void);
char **find_path(char **environ);
char *args_path(char **parse, char **new);
int handle_ctrl_d(char *buf);
char **func_split(char *line);
char **split_env(char *path);
char **func_split(char *line);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **splits(char *line, char *delim);
char **split_env(char *path);
char *length(char *str);
int compare(char *varname, char *dirname);

#endif


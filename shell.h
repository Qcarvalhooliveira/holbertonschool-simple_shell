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
#include <signal.h>

extern char **environ;

#define BUFSIZE 1024
#define MAX_LINE_LENGTH 1024

int main(int argc, char **argv, char **environ);
char *_strcat(char *dest, const char *source);
int _strcmp(char *first, char *second);
int _strlen(char *string);
int _strncmp(char *string1, char *string2, int n);
void free_grid(char **grid);
int func_exec(char **args);
void _printenv(void);
char *read_func(void);
void free_grid(char **grid);
char *get_path(char *getcmd);
int handle_ctrl_d(char *buf);
char **func_split(char *line);
char **split_env(char *path);
char **func_split(char *line);
char *trim(char *str);
void child_process(char **args);
void parent_process(pid_t pid);

#endif

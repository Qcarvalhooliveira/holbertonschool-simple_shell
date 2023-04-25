#include "shell.h"

/**
 * main - Function that start the shell.
 * 
 * Return: 1.
 */

int main(void)
{
	char line[MAX_LINE_LENGTH];
	char *args[2];
	int status, pid;

	while (1)
	{
	printf("$ ");
	fflush(stdout);

	if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL)
	{
	printf("\n");
	exit(EXIT_SUCCESS);
	}
	line[strcspn(line, "\n")] = '\0';

	if (strlen(line) == 0)
	{
	continue;
	}
	args[0] = strtok(line, " ");
	args[1] = NULL;

	pid = fork();

	if (pid < 0)
	{
	perror("fork");

	exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
	struct stat st;

	if (stat(args[0], &st) == -1)
	{

	fprintf(stderr, "%s: command not found\n", args[0]);
	exit(EXIT_FAILURE);
	}

	if (execve(args[0], args, environ) == -1)
	{
	perror("execve");
	exit(EXIT_FAILURE);
	}
	}

	else
	{

	if (waitpid(pid, &status, 0) == -1)
	{
	perror("waitpid");

	exit(EXIT_FAILURE);
	}
	}
	}
	return (0);
}

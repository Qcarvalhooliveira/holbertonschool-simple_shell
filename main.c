#include "shell.h"

/*
 * main - Function that start the shell.
 * @argc: is an integer
 * @argv: is a char
 * @environ: global variable
 * Return: 0
 */
int main(void)
{
	while (1)
	{
		printf("$ ");
		fflush(stdout);

		char line[MAX_LINE_LENGTH];

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

		char *args[2];

		args[0] = strtok(line, " ");
		args[1] = NULL;

		pid_t pid = fork();

		if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			child_process(args);
		}
		else
		{
			parent_process(pid);
		}
	}

	return (0);
}
/**
 * child_process - Function that start the shell.
 * @args: is an integer
 *
 * Return: 0
 */
void child_process(char **args)
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

/**
 * parent_process - Function that start the shell.
 * @pid: Process ID
 *
 * Return: 0
 */
void parent_process(pid_t pid)
{
	int status;

	if (waitpid(pid, &status, 0) == -1)
	{
		perror("waitpid");
		exit(EXIT_FAILURE);
	}
}

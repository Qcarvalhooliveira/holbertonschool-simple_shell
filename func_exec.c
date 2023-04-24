#include "shell.h"

/**
 * func_exec - function that executes the commands.
 * @args: list of commands.
 *
 * Return: If sucess return 1.
 */

int func_exec(char **args)
{
	pid_t pid;
	int status;
	char *getcmd;

	pid = fork();
	if (pid == -1)
	{
	perror("Error: fork");
	return (0);
	}

	if (pid == 0)
	{
	if (args[0][0] == '/' || args[0][0] == '.')

	getcmd = args[0];
	else
	getcmd = get_path(args[0]);

	if (getcmd == NULL)
	{
	perror("Error: command not found");
	exit(0);
	}

	if (execve(getcmd, args, environ) == -1)
	{
	perror("Error: execve");
	free(getcmd);
	exit(EXIT_FAILURE);
	}
	}
	else
	{
	waitpid(pid, &status, 0);
	}
	return (1);
}

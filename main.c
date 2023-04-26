#include "shell.h"

/*
 * main - Function that start the shell.
 * @argc: is an integer
 * @argv: is a char
 * @environ: global variable
 * Return: 0
 */

int main(int argc, char **argv, char **environ)
{
	char *line = NULL;
	char *delim = "\t \a\n";
	char *command;
	char **tokens;

	tokens = find_path(environ);

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		line = read_line();
		char **args = splits(line, delim);
		command = args_path(args, tokens);
		if (command == NULL)
			execute(args);
		free(line);
		free(args);
		free(command);
	}
	return (0);
}

#include "shell.h"

/**
 * read_func - reads input from stdin.
 *
 * Return: line if successful, NULL if failed.
 */

char *read_func(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);
	if (read == -1)
	{
	free(line);
	exit(EXIT_SUCCESS);
	}
	line[read - 1] = '\0';

	if (*line == '\0')
	{
	free(line);
	return (NULL);
	}
	return (line);
}


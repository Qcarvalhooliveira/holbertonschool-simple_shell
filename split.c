#include "shell.h"

/**
  * _func_split- Function to make tokens (what is reading)
  * @line: the line to be tokenize
  * @
  *
  * Return: tokens's array
  */
char **func_split(char *line);
{
	char **tokens = malloc(sizeof(char *));
	char *token = strtok(line, " ");
	int i = 0;

	while (token != NULL)
	{
	tokens[i] = token;
	i++;
	tokens = realloc(tokens, (i + 1) * sizeof(char *));
	token = strtok(NULL, " ");
	}
	tokens[i] = NULL;

	return (tokens);
}

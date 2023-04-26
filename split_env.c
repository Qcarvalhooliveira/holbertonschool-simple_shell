#include "shell.h"

/**
  * split_env - Permits to tokenize path
  * @path: The path toward tokenize
  *
  * Return: Array containing tokens
  */


char **split_env(char *path)

{
	int i = 0;
	char **tokens = malloc(sizeof(char *));
	char *token = strtok(path, "/");

	while (token != NULL)
{
	tokens[i] = token;
	i++;
	tokens = realloc(tokens, (i + 1) * sizeof(char *));
	token = strtok(NULL, "/");
}
	tokens[i] = NULL;

	return (tokens);
}


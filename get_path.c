#include "shell.h"

/**
  * find_path - permits to get command's path
  * @environ: environment global variable
  *
  * Return: to tokens'path
  */

char **find_path(char **environ)
{
	char *get_path, **tokens, *delim;

	delim = ":";
	get_path = _getenv(environ, "PATH");
	tokens = splits(get_path, delim);
	return (tokens);
}

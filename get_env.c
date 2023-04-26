#include "shell.h"

/**
 * _getenv - function that gets the path in the environ
 * @environ: global variable
 * @dirname: is a char
 * Return: final or null
 */

char *_getenv(char **environ, char *dirname)
{
	int k, j;
	char *varname, *final;

	for (j = 0; environ[j]; j++)
	{
	varname = malloc(1024);

	for (k = 0; environ[j][k] != '='; k++)
	varname[k] = environ[j][k];

	if (compare(varname, dirname))
	{
	final = length(environ[j]);
	free(varname);

	return (final);
	}
	free(varname);
	}
	return (NULL);
}


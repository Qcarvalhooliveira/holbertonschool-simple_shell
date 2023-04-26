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

/**
 * args_path - concatenates the arguments
 * @parse: is a char
 * @new: is a char
 * Return: total or null
 */

char *args_path(char **parse, char **new)
{
	char *total, **cat;
	int i, j, k;
	struct stat status;

	for (i = 0; new[i]; i++)
	{
		total = malloc(60);
		_strcat(total, new[i]);
		_strcat(total, "/");
		_strcat(total, parse[0]);

		if (stat(total, &status) == 0)
		{
			for (k = 0; parse[k] != '\0'; k++)
				;
			cat = malloc(sizeof(char *) * (k + 1));
			cat[k] = NULL;
			cat[0] = _strdup(total);

			for (j = 1; parse[j]; j++)
				cat[j] = _strdup(parse[j]);
			execute(cat);
			return (total);
		}
		free(total);
	}
	return (NULL);
}

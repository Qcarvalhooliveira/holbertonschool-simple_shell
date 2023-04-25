#include "shell.h"

/**
 * _printenv - function that prints the environment variables.
 *
 */

void _printenv(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	printf("%s\n", environ[i]);
}


#include "shell.h"

/**
 * length - function that checks the = character
 * @str: is a char
 * Return: str
 */

char *length(char *str)
{
	int i;

	for (i = 0; str[i] != '='; i++)
		;
	return (str + i + 1);
}

/**
 * compare - function that compares two strings
 * @varname: is a char
 * @dirname: is a char
 * Return: 1
 */

int compare(char *varname, char *dirname)
{
	int i;

	for (i = 0; dirname[i] != '\0'; i++)
	{
		if (dirname[i] != varname[i])
			return (0);
	}
	return (1);
}

/**
 * free_grid - frees the memory allocated for a 2D array of strings
 * @grid: the 2D array of strings to free
 *
 * Return: nothing
 */

void free_grid(char **grid)
{
	int i;

	if (grid == NULL)
		return;

	for (i = 0; grid[i] != NULL; i++)
		free(grid[i]);

	free(grid);
}

/**
 *_strcat - concatenate 2 strings
 *@dest: is a character
 *@src: is a character
 *Return: dest concatenated strind
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	{ }

	for (j = 0; src[j] != '\0'; j++, i++)
		dest[i] = src[j];

	dest[i] = '\0';
	return (dest);
}

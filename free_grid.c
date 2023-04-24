#include "shell.h"

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


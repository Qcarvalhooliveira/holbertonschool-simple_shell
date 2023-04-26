#include "shell.h"

/**
 *_strdup - duplicate a string
 *@str: is a pointer
 *Return: pointer to array
 */

char *_strdup(char *str)
{
	char *new;
	int i;

	if (str == NULL)
		return (NULL);

	new = malloc(_strlen(str) + 1);

	if (new == NULL)
		return (NULL);

	i = 0;

	while (str[i] != '\0')
	{
		new[i] = str[i];
		i++;
	}

	new[i] = '\0';

	return (new);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 *_puts - prints a string
 *@str: is a character
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}

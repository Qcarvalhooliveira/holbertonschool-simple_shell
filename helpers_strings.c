#include "shell.h"

/**
 *tokenizer - Function that break characters into tokens
 *@input_string: input to analyse
 *@delim: This is a delimiter who need to be a character string
 *
 *Return: as an array of tokens
 */

char **tokenizer(char *input_string, char *delim)
{
	int num_delim = 0;
	char **av = NULL;
	char *token = NULL;
	char *save_ptr = NULL;

	token = _strtok_r(input_string, delim, &save_ptr);

	while (token != NULL)
	{
		av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
		av[num_delim] = token;
		token = _strtok_r(NULL, delim, &save_ptr);
		num_delim++;
	}

	av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
	av[num_delim] = NULL;

	return (av);
}

/**
 *print - Function that print a string to stdout
 *@string: Is the string to print out
 *@stream: Is the stream to print out
 *
 *Return: void, return nothing
 */
void print(char *string, int stream)
{
	int i = 0;

	for (; string[i] != '\0'; i++)
		write(stream, &string[i], 1);
}

/**
 *remove_newline - Function that remove a new line from a string
 *@str: Is the string to use
 *
 *
 *Return: void
 */

void remove_newline(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	str[i] = '\0';
}

/**
 *_strcpy - Function that copy a string to another buff
 *@source: Is the source to copy from
 *@dest: Is the destination to copy to
 *
 * Return: void
 */

void _strcpy(char *source, char *dest)
{
	int i = 0;

	for (; source[i] != '\0'; i++)
		dest[i] = source[i];
	dest[i] = '\0';
}

/**
 *_strlen - Function that count the length of string
 *@string: Is the string to be counted
 *
 * Return: length of the string
 */

int _strlen(char *string)
{
	int len = 0;

	if (string == NULL)
		return (len);
	for (; string[len] != '\0'; len++)
		;
	return (len);
}

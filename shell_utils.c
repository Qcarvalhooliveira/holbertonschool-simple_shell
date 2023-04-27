#include "shell.h"

/** parse_cmd - Function that determines the type of the command
 * @cmd: command to be parsed
 *
 * Return: constant representing the type of the command
 */

int parse_cmd(char *cmd)
{
	int i;
	char *internal_cmd[] = {"env", "exit", NULL};
	char *path = NULL;

	for (i = 0; cmd[i] != '\0'; i++)
	{
		if (cmd[i] == '/')
			return (EXTERNAL_COMMAND);
	}
	for (i = 0; internal_cmd[i] != NULL; i++)
	{
		if (_strcmp(cmd, internal_cmd[i]) == 0)
			return (INTERNAL_COMMAND);
	}

	path = check_path(cmd);
	if (path != NULL)
	{
		free(path);
		return (PATH_COMMAND);
	}

	return (INVALID_COMMAND);
}

/**
 * execute_cmd - Function that executes a command based on it's type
 * @tokenized_cmd: tokenized form of the command (ls -l == {ls, -l, NULL})
 * @cmd_type: type of the command
 *
 * Return: void
 */
void execute_cmd(char **tokenized_cmd, int cmd_type)
{
	void (*func)(char **cmd);

	if (cmd_type == EXTERNAL_COMMAND)
	{
		if (execve(tokenized_cmd[0], tokenized_cmd, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (cmd_type == PATH_COMMAND)
	{
		if (execve(check_path(tokenized_cmd[0]), tokenized_cmd, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (cmd_type == INTERNAL_COMMAND)
	{
		func = get_func(tokenized_cmd[0]);
		func(tokenized_cmd);
	}
	if (cmd_type == INVALID_COMMAND)
	{
		print(shell_name, STDERR_FILENO);
		print(": 1: ", STDERR_FILENO);
		print(tokenized_cmd[0], STDERR_FILENO);
		print(": not found\n", STDERR_FILENO);
		status = 127;
	}
}

/**
 * check_path - Function that checks if a command is found in the PATH
 * @command: command to be used
 *
 * Return: path where the command is found in, NULL if not found
 */
char *check_path(char *cmd)
{
	char **path_array = NULL;
	char *temp, *temp2, *path_cpy;
	char *path = _getenv("PATH");
	int i;

	if (path == NULL || _strlen(path) == 0)
		return (NULL);
	path_cpy = malloc(sizeof(*path_cpy) * (_strlen(path) + 1));
	_strcpy(path, path_cpy);
	path_array = tokenizer(path_cpy, ":");
	for (i = 0; path_array[i] != NULL; i++)
	{
		temp2 = _strcat(path_array[i], "/");
		temp = _strcat(temp2, cmd);
		if (access(temp, F_OK) == 0)
		{
			free(temp2);
			free(path_array);
			free(path_cpy);
			return (temp);
		}
		free(temp);
		free(temp2);
	}
	free(path_cpy);
	free(path_array);
	return (NULL);
}

/**
 * get_func - Function that retrieves a function based on the command given and a mapping
 * @command: string to check against the mapping
 *
 * Return: pointer to the proper function, or null on fail
 */
void (*get_func(char *cmd))(char **)
{
	int i;
	function_map mapping[] = {
		{"env", env}, {"exit", quit}
	};

	for (i = 0; i < 2; i++)
	{
		if (_strcmp(cmd, mapping[i].command_name) == 0)
			return (mapping[i].func);
	}
	return (NULL);
}

/**
 * _getenv - Function that gets the value of an environment variable
 * @name: name of the environment variable
 *
 * Return: the value of the variable as a string
 */
char *_getenv(char *name)
{
	char **my_env;
	char *pair_ptr;
	char *name_cpy;

	for (my_env = environ; *my_env != NULL; my_env++)
	{
		for (pair_ptr = *my_env, name_cpy = name;
		     *pair_ptr == *name_cpy; pair_ptr++, name_cpy++)
		{
			if (*pair_ptr == '=')
				break;
		}
		if ((*pair_ptr == '=') && (*name_cpy == '\0'))
			return (pair_ptr + 1);
	}
	return (NULL);
}

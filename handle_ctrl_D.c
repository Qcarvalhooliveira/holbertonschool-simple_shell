#include "shell.h"

#define BUFSIZE 1024

/**
 * handle_ctrl_d - Handles ctrl + d
 * @buf: buffer to read input from
 *
 * Return: 1 if ctrl + d was pressed, otherwise 0
 */

int handle_ctrl_d(char *buf)
{
	ssize_t num_read;

	num_read = read(STDIN_FILENO, buf, BUFSIZE);
	if (num_read == 0)
	{
	write(STDOUT_FILENO, "exit\n", 5);
	return (1);
	}
	return (0);
}

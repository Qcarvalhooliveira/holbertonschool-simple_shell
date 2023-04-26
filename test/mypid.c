#include <stdio.h>
#include <unistd.h>

/**
 * gitpid - program that prints the PID of the parent process.
 *
 * Return: Sucess 0.
 */

int main(void)
{
	pid_t my_pid;

	my_pid = getppid();
	printf("The PID of the parent process is:%u\n", my_pid);
	return (0);
}

#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints all the arguments.
 *
 * Return: sucess 0.
 */
int main(int ac, char **av)
{
	int i = 0;
	while (av[i] != NULL) 
	{
	printf("%s\n", av[i]);
	i++;
	}
	return 0;
}

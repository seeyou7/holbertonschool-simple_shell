#include "shell.h"
/**
 * print_env - is a function that print the variables environment
 *
 * Return: 0 (Success)
 */

int print_env(void)
{
	int i;

	i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}

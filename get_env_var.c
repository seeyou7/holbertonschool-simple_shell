#include "shell.h"
/**
 * get_env - is a function that extarct the path from the environment
 *@input_cmd: user input command
 * Return: a string wich store the path variable
 */
char *get_env(char *input_cmd)
{
	int i, size;

	size = strlen(input_cmd);
	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], input_cmd, size) == 0)
			return (environ[i] + size + 1);
	}
	return (NULL);
}

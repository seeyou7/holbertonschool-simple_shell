#include "shell.h"
/**
 * get_env - is a function that extarct the path from the environment
 *
 * Return: a string wich store the path variable
 */
char *get_env()
{
	char *path;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], "PATH", 4) == 0)
		{
			path = environ[i];
		}
		i++;
	}
	return (path);
}

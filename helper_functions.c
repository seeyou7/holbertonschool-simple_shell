#include "shell.h"
/**
 * get_env - is a function that extarct the path from the environment
 *
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
#include "shell.h"

/**
  * split_env - tokenize the path
  * @path: path to tokenize
  * Return: array of tokens
  */
char **split_env(char *path)
{
        int size = 1024;
        int i = 0;
        char **arr_path = malloc(size * sizeof(char *));
        char *token;

        if (arr_path == NULL)
        {
                perror("Error : malloc");
                exit(1);
        }
        token = strtok(path, ":");
        while (token != NULL)
        {
                arr_path[i] = token;
                i++;
        	token = strtok(NULL, ":");
        }
        arr_path[i] = NULL;
        return (arr_path);
}

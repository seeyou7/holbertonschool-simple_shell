#include "shell.h"
/**
 * execute_cmd - is a function that execute a not builtin command
 * Return: an integer 
 */
int execute_cmd(char **arr_cmd)
{
	char *arg = arr_cmd[0];
	char *newcmd = NULL;
	pid_t _pid = fork();
	int status;

	if (_pid == -1)
	{
		perror("Error: fork");
	}

	if (_pid == 0)
	{
		if (arg[0] != '/' && arg[0] != '.')
		{
			newcmd = find_path(arr_cmd[0]);
		}
		if (newcmd == NULL)
		{
			perror("Error: find_path");
			exit(EXIT_FAILURE);
		}
		free(arg);

		arg = newcmd;

		if (arr_cmd[0] == NULL)
		{
			perror("Error: No argument");
			exit(EXIT_FAILURE);
		}

		if (arg == NULL)
		{
			perror("Error: axecve");
			return (0);
		}
		else
		{	execve(arg, arr_cmd, NULL);
			perror("Error: exeve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	return (1);
}

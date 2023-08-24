#include "shell.h"
/**
 *exit_func - function for exiting the program
 *
 *Return: 0 for success
 */
int exit_func(void)
{
	exit(0);
}

/**
 * free_cmd - is a function that frees all the memory allocated for command
 * @arr_cmd: array storing the user command
 * Return: void
 */
/**void free_cmd(char **arr_cmd)
{
	size_t i = 0;
	
	if (arr_cmd == NULL)
		return;
	
	while (arr_cmd[i])
	{
		free(arr_cmd[i]);
		i++;
	}
	
	if (arr_cmd[i] == NULL)
	{	
		free(arr_cmd[i]);
	}
	free(arr_cmd);
}
*/

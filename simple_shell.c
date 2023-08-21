#include "shell.h"
/**
 * main - entry point of the program
 * Return: 0 Success
 */
int main(void)
{
	char **arr_cmd;
	char *input_cmd;
	int i = 0;
	int true_builtin = 0;

	builtin_t builtins[] = {
		{"exit", exit_func},
		{"env", print_env},
		{NULL, NULL}
	};
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "new_shell>> ", 12);
		}
		input_cmd = read_command();
		arr_cmd = split_cmd(input_cmd);
		while (builtins[i].cmd != NULL)
		{
			if (strcmp(builtins[i].cmd, arr_cmd[0]) == 0)
			{
				builtins[i].func(arr_cmd);
				true_builtin = 1;
				break;
			}
			i++;
		}
		if (true_builtin != 1)
		{
			if (arr_cmd != NULL)
			{
				execute_cmd(arr_cmd);
			}
			free(input_cmd);
			free(arr_cmd);
		}
		true_builtin = 0;
		i = 0;
	}
	return (0);
}

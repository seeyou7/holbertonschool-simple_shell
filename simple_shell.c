#include "shell.h"
/**
 * main - entry point of the program
 * Return: 0 Success
 */
int main()
{
	char **arr_cmd;
	char *input_cmd;
	int i = 0;
	int true_builtin = 0;
	int interactive_mode = 0;

	builtin_t builtins[] = {
		{"exit", exit_func},
		{"env", print_env},
		{NULL, NULL}
	};

	if (isatty(STDIN_FILENO) == 1)
		interactive_mode = 1;

	while (1)
	{
		if (interactive_mode)
		{
			write(STDOUT_FILENO, "$shell>> ", 9);
		}

		input_cmd = read_command();
		if (input_cmd == NULL)
		{
			if (!interactive_mode)
			{
				break;
			}
			continue;
		}
		arr_cmd = split_cmd(input_cmd);
		while (builtins[i].cmd != NULL)
		{
			if (strcmp(builtins[i].cmd, arr_cmd[0]) == 0)
			{
				builtins[i].func();
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

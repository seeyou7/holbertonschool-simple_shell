#include "shell.h"
/**
 * main - entry point of the program
 * Return: 0 Success
 */
int main(void)
{
	char **arr_cmd;
	char *input_cmd;
	int true_builtin = 0;
	int i = 0;
	int interactive_mode = isatty(STDIN_FILENO);

	builtin_t builtins[] = {
		{"exit", exit_func},
		{"env", print_env},
		{NULL, NULL}
	};

	while (1)
	{
		if (interactive_mode)
		{
			write(STDOUT_FILENO, "top_shell>> ", 12);
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

		i = 0;
		while (builtins[i].cmd != NULL)
		{
			if (strcmp(builtins[i].cmd, arr_cmd[0]) == 0)
			{
				true_builtin = 1;
				builtins[i].func();
				free(input_cmd);
				free(arr_cmd);
				break;
			}
			i++;
		}
		if (!true_builtin)
		{
			if (arr_cmd != NULL)
			{
				execute_cmd(arr_cmd);
			}
			free(input_cmd);
			free(arr_cmd);
		}
		true_builtin = 0;
	}
	return (0);
}

#include "shell.h"
/**
 * main: entry point of the program
 *
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
			write(STDOUT_FILENO, "new_shell>>", 11)
		}
		input_cmd = read_command();
		arr_cmd = split_input(input_cmd);
		while (builtins[i].cmd != NULL)
		{
			if (strcmp(builtins[i].cmd, input_cmd) == 0)
			{
				builtins[i].func(arr_cmd);
				true_builtin = 1;
				break;
			}
			i++;
		}
		if (!true_builtin)
		{
			if (arr_cmd != NULL)
			{
				if (input_cmd[0] != '\n' || input_cmd[1] != '\0')
				{
					execute_cmd(arr_cmd);
				}
				free(input_cmd);
				free(arr_cmd);
			}
		}
		return (0);
	}
}

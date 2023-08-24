#ifndef _SHELL_H_
#define _SHELL_H_

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

extern char **environ;

/**
 * struct builtIn - is a structure that contains 2 elements
 * @cmd: is a pointer to chatracter
 * @func: is a pointer to function
 * Description: this structure defines a built-in shell command
 */
typedef struct builtIn
{
	char *cmd;
	int (*func)(void);
} builtin_t;

int main(void);
int print_env(void);
char *read_command(void);
char **split_cmd(char *input);
int execute_cmd(char **arr_cmd);
char *get_env(char *input_cmd);
char **split_env(char *path);
char *find_path(char *input_cmd);
int exit_func(void);

#endif

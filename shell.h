#ifndef _SHELL_H_
#define _SHELL_H_

#define IN 1
#define OUT 0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

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
	()(*func)();
} builtin_t;

int main(void);
int exit_func(void);
int print_env(void);
char *read_command(void);
char **split_cmd(char *input);

#endif

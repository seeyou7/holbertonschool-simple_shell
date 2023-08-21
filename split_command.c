#include "shell.h"
/**
 * split_cmd - function that split the command into array
 *@input: the user input to be parsed
 *Return: an array of strings
 */

char **split_cmd(char *input)
{
	char *tok;
	char **tokens;
	int i = 0;
	int max_tokens = 30;

	tokens = malloc(sizeof(char *) * max_tokens);
	if (tokens == NULL)
	{
		perror("malloc_fails");
		free(tokens);
		free(input);
		exit(EXIT_FAILURE);
	}

	tok = strtok(input, " ");
	while (tok != NULL)
	{

		tokens[i] = tok;
		i++;
		tok = strtok(NULL, " ");
	}
	tokens[i] = NULL;
	return (tokens);
}

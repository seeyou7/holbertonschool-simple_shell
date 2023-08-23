#include "shell.h"

/**
 * find_path - find the path of the command
 * @input_cmd: user command
 * Return: path of the command
 */
/**char *find_path(char *input_cmd)
{
        struct stat st;
        int i;
        char *path = get_env("PATH");
        char **arr_path = split_env(path);
        char *full_path = NULL;

        for (i = 0; arr_path[i] != NULL; i++)
        {
                size_t path_len = strlen(arr_path[i]);
		size_t cmd_len = strlen(input_cmd);
                full_path = malloc(path_len + cmd_len + 2);
                if (full_path == NULL)
                {
                        perror("Error: malloc");
                        exit(EXIT_FAILURE);
                }

                strcpy(full_path, arr_path[i]);
                strcat(full_path, "/");
                strcat(full_path, input_cmd);

                if (stat(full_path, &st) == 0)
                {
                        free(arr_path);
                        return (full_path);
                }

                free(full_path);
        }

        free(arr_path);
        return (NULL);
}*/

char *find_path(char *input_cmd) {
    struct stat st;
    char *path = get_env("PATH");
    char *full_path = strdup(path);
    char *token = strtok(full_path, ":");

    while (token) {
        char full_cmd[1024];
        strcpy(full_cmd, token);
        strcat(full_cmd, "/");
        strcat(full_cmd, input_cmd);

        if (stat(full_cmd, &st) == 0) {
            free(full_path);
            return strdup(full_cmd);
        }

        token = strtok(NULL, ":");
    }

    free(full_path);
    return NULL;
}

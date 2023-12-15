#include "simple_shell.h"

/**
 * get_path - search file between the paths from environ
 * @command: command to add on to the path
 * Return: cmd path with command for execution
 */

char *get_path(char *command)
{
	char *env_path = get_env("PATH"), *path = NULL;
	char **parsed_string;
	char *actual_path = NULL;
	int i = 0, length = 0;

	if (access(command, R_OK & X_OK) == 0)
		return (command);

	path = strdup(env_path);
	if (path == NULL)
		return (NULL);
	parsed_string = parse_string(path, ":");
	free(path);
	for (i = 0; parsed_string[i]; i++)
	{
		actual_path = NULL;

		length = strlen(parsed_string[i]);
		actual_path = malloc(length + strlen(command) + 2);
		if (actual_path == NULL)
		{
			free(parsed_string);
			return (NULL);
		}
		strcpy(actual_path, parsed_string[i]);
		if (actual_path[length - 1] != '/')
			strcat(actual_path, "/");
		strcat(actual_path, command);

		if (access(actual_path, X_OK) == 0)
			break;
		free(actual_path);
		actual_path = NULL;
	}
	free(parsed_string);
	if (actual_path == NULL)
		return (NULL);
	return (actual_path);
}

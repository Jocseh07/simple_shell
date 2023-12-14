#include "simple_shell.h"

/**
 * get_path - search file between the paths from environ
 * @command: command to add on to the path
 * Return: cmd path with command for execution
 */

char *get_path(char *command)
{
	char *env_path = get_env("PATH"), *path;
	char **parsed_string;
	char *actual_path = NULL;
	int i = 0, length = 0;

	if (access(command, F_OK) == 0)
		return (command);

	path = malloc(_strlen(env_path) + 1);
	if (path == NULL)
		return (NULL);
	path = strdup(env_path);
	parsed_string = parse_string(path, ":");
	free(path);

	for (i = 0; parsed_string[i]; i++)
	{
		length = _strlen(parsed_string[i]);

		if (parsed_string[i][length - 1] != '/')
			actual_path = strcat(parsed_string[i], "/");

		actual_path = strcat(parsed_string[i], command);

		if (access(actual_path, F_OK) == 0)
			break;
	}

	if (parsed_string[i] == NULL)
	{
		free(parsed_string);
		return (NULL);
	}

	return (actual_path);
}

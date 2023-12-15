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
	struct stat info;

	if (stat(command, &info) == 0)
		return (command);

	path = malloc(strlen(env_path) + 1);
	if (path == NULL)
		return (NULL);
	path = strcpy(path, env_path);
	parsed_string = parse_string(path, ":");

	for (i = 0; parsed_string[i]; i++)
	{
		length = strlen(parsed_string[i]);

		if (parsed_string[i][length - 1] != '/')
			actual_path = strcat(parsed_string[i], "/");

		actual_path = strcat(parsed_string[i], command);

		if (stat(actual_path, &info) == 0)
			break;
	}

	free(path);

	if (parsed_string[i] == NULL)
	{
		free(parsed_string);
		return (NULL);
	}

	free(parsed_string);
	return (actual_path);
}

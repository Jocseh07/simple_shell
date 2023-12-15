#include "simple_shell.h"

/**
 * get_path - search file between the paths from environ
 * @command: command to add on to the path
 * Return: cmd path with command for execution
 */

char *get_path(char *command)
{
	char *env_path = getenv("PATH"), *path = NULL;
	char **parsed_string;
	char *actual_path = NULL;
	int i = 0, length = 0;

	if (access(command, F_OK) == 0)
		return (command);

	path = strdup(env_path);
	if (path == NULL)
		return NULL;
	parsed_string = parse_string(path, ":");
	free(path);

	for (i = 0; parsed_string[i]; i++)
	{
		length = strlen(parsed_string[i]);
		actual_path = malloc(length + strlen(command) + 2);
		if (actual_path == NULL)
		{
			freess(parsed_string);
			return NULL;
		}
		strcpy(actual_path, parsed_string[i]);
		if (actual_path[length - 1] != '/')
			strcat(actual_path, "/");
		strcat(actual_path, command);

		if (access(actual_path, F_OK) == 0)
			break;
		free(actual_path);
	}
	freess(parsed_string);
	return (actual_path);
}

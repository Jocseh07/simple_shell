#include "simple_shell.h"

/**
 * check_commands - check for some arguments
 * @commands: first argument to check
 * Return: direction to follow
 */

size_t check_commands(char **commands)
{
	size_t exit_status = 0;

	commands[0] = get_path(commands[0]);
	if (commands[0] != NULL)
		exit_status = execute(commands);
	else
		perror("Path Error");
	free(commands);
	return (exit_status);
}

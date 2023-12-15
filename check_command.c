#include "simple_shell.h"

/**
 * check_commands - check for some arguments
 * @commands: first argument to check
 * Return: direction to follow
 */

size_t check_commands(char **commands)
{
	size_t exit_status = 0, skip = 0, a = 1, b = 0;
	char *actual_path = NULL;

	if ((_strcmp("echo", commands[0]) == 0) && (commands[1] != NULL))
	{
		skip = 1;
		if (_strcmp("$?", commands[1]) == 0)
			printf("%ld\n", exit_status);
		else if (_strcmp("$$", commands[1]) == 0)
			printf("%d\n", getpid());
		else if (_strcmp("$PATH", commands[1]) == 0)
			printf("%s\n", get_env("PATH"));
		else
			skip = 0;
	}
	if (skip == 0)
	{
		actual_path = get_path(commands[0]);
		commands[0] = strdup(actual_path);
		free(actual_path);
		for (a = 1; commands[a]; a++)
		{
			if (_strcmp("#", commands[a]) == 0)
			{
				b = a;
				while (commands[b])
				{
					commands[b] = NULL;
					b++;
				}
			}
		}
		if (commands[0] != NULL)
			exit_status = execute(commands);
		else
			perror("Path Error");
		free(commands[0]);
		free(commands);
	}
	return (exit_status);
}

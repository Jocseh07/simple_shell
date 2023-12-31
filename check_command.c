#include "simple_shell.h"

/**
 * check_commands - check for some arguments
 * @commands: first argument to check
 * Return: direction to follow
 */

size_t check_commands(char **commands)
{
	size_t exit_status = 0, skip = 0, a = 1, b;

	if (strcmp("echo", commands[0]) == 0)
	{
		skip = 1;
		if (strcmp("$?", commands[1]) == 0)
			printf("%ld\n", exit_status);
		else if (strcmp("$$", commands[1]) == 0)
			printf("%d\n", getpid());
		else if (strcmp("$PATH", commands[1]) == 0)
			printf("%s\n", get_env("PATH"));
		else
			skip = 0;
	}
	if (skip == 0)
	{
		for (a = 0; commands[a]; a++)
		{
			if (commands[a][0] == '#')
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
		{
			commands[0] = get_path(commands[0]);
			if (commands[0] != NULL)
				exit_status = execute(commands);
			else
				perror("Path Error");
		}

		free(commands);
	}
	return (exit_status);
}

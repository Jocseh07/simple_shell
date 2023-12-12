#include "simple_shell.h"

/**
 * simple_shell - handle the inputs in terminal
 * Return: exit_status of the execution
 */

int simple_shell(void)
{
	char *input = NULL, **commands;
	size_t length = 0, exit_status = 0, skip = 0;
	ssize_t chars_read = 0;

	while (1)
	{
		skip = 0;
		if (isatty(0))
			printf("$ ");
		chars_read = getline(&input, &length, stdin);
		if (chars_read == -1 || _strcmp("exit\n", input) == 0)
		{
			free(input);
			break;
		}
		input[chars_read - 1] = '\0';
		if (empty_line(input) == 0)
		{
			exit_status = 0;
			skip = 1;
		}
		if (_strcmp("env", input) == 0)
		{
			print_env();
			skip = 1;
		}
		if (skip == 0)
		{
			commands = parse_string(input, " ");
			commands[0] = get_path(commands[0]);

			if (commands[0] != NULL)
				exit_status = execute(commands);
			else
				perror("Path Error");
			free(commands);
		}
	}
	return (exit_status);
}

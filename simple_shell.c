#include "simple_shell.h"

/**
 * simple_shell - handle the inputs in terminal
 * Return: exit_status of the execution
 */

void simple_shell(void)
{
	char *input = NULL, **commands;
	size_t length = 0, exit_status = 0;
	ssize_t chars_read = 0;

	while (1)
	{
		if (isatty(0))
			printf("$ ");
		chars_read = getline(&input, &length, stdin);
		if (chars_read == -1 || _strcmp("exit\n", input) == 0)
		{
			free(input);
			exit(0);
		}
		input[chars_read - 1] = '\0';
		if (empty_line(input) == 0)
		{
			exit_status = 0;
			continue;
		}
		commands = parse_string(input, " ");
		if (_strcmp("exit", commands[0]) == 0)
			exit(atoi(commands[1]));
		if (_strcmp("env", commands[0]) == 0)
		{
			print_env();
			exit_status = 0;
			free(commands);
			continue;
		}
		exit_status = check_commands(commands);
	}
	exit(exit_status);
}

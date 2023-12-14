#include "simple_shell.h"

/**
 * check_exit - checks the exit code
 * @commands: where to check the exit codes
 * Return: None
 */

void check_exit(char **commands, char *input)
{
	int n = 0;

	if (commands[1])
		n = atoi(commands[1]);
	else
	{
		fprintf(stderr, "exit: Illegal number: %d\n", n);
		exit(1);
	}
	free(commands);
	free(input);
	if (n < 0)
	{
		fprintf(stderr, "exit: Illegal number: %d\n", n);
		exit(1);
	}
	else
		exit(n);
}
#include "simple_shell.h"

/**
 * print_env - prints the environment
 */

void print_env(void)
{
	char **s = environ;

	for (; *s; s++)
		printf("%s\n", *s);
}

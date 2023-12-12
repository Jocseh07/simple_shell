#include "simple_shell.h"

/**
 * print_env - prints the environment
 */

void print_env(void)
{
	int a = 0;

	while (environ[a])
	{
		printf("%s\n", environ[a]);
		a++;
	}
}

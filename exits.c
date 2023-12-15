#include "simple_shell.h"

/**
 * exits - handle exits
 * @n: exit status
 * Return: void
 */

void exits(int n)
{
	printf("test");
	if (n == 0)
		exit(EXIT_FAILURE);
	else if (n < 0)
		exit(EXIT_FAILURE);
	else
		exit(n);
}
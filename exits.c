#include "simple_shell.h"

/**
 * exits - handle exits
 * @n: exit status
 * Return: void
 */

void exits(int n)
{
	if (!n)
		perror("Error");
	else if (n < 0)
		perror("Error");
	else
		exit(n);
}
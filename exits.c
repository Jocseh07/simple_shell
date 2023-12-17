#include "simple_shell.h"

/**
 * exits - handle exits
 * @n: exit status
 * Return: void
 */

void exits(int n)
{
	if (n == 0)
		exit(1);
	else if (n < 0)
		exit(1);
	else
		exit(n);
}

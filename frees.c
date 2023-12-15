#include "simple_shell.h"

/**
 * freess - frees char **
 * @parsed_string: what to free
 */

void freess(char **parsed_string)
{
	int a = 0;

	for (a = 0; a < 64; a++)
	{
		free(parsed_string[a]);
	}
	free(parsed_string);
}

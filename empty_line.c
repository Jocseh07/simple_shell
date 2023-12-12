#include "simple_shell.h"

/**
 * empty_line - check if line only has spaces or is empty
 * @line: is pointer to the line
 * Return: 0 if empty and -1 if not empty
 */

int empty_line(char *line)
{
	int a;

	for (a = 0; line[a] != '\0'; a++)
	{
		if (line[a] != ' ')
			return (-1);
	}

	return (0);
}

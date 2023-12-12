#include "simple_shell.h"

/**
 * parse_string - parse strings with strtok
 * @input: the string to parse with strtok
 * @sep: the delim to pass to strtok
 * Return: a double pointer to the parsed strings
 */

char **parse_string(char *input, char *sep)
{
	char **parsed_string;
	int b = 0;

	parsed_string = calloc(64, sizeof(char *));
	if (parsed_string == NULL)
		return (NULL);

	parsed_string[b++] = strtok(input, sep);

	while (strtok(NULL, sep))
	{
		parsed_string[b] = strtok(NULL, sep);
		b++;
	}

	return (parsed_string);
}

#include "simple_shell.h"

/**
 * parse_string - parse strings with strtok
 * @input: the string to parse with strtok
 * @sep: the delim to pass to strtok
 * Return: a double pointer to the parsed strings
 */

char **parse_string(char *input, char *sep)
{
	char **parsed_string = NULL;
	char *token;
	int size = 64, b = 0;

	parsed_string = calloc(size, sizeof(char *));
	if (parsed_string == NULL)
		return (NULL);

	token = strtok(input, sep);

	while (token != NULL)
	{
		parsed_string[b] = token;
		token = strtok(NULL, sep);
		b++;
	}
	free(token);
	return (parsed_string);
}

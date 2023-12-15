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
	char *actual_token;
	int b = 0;

	parsed_string = calloc(64, sizeof(char *));
	if (parsed_string == NULL)
		return (NULL);

	actual_token = strtok(input, sep);

	while (actual_token != NULL)
	{
		parsed_string[b] = actual_token;
		actual_token = strtok(NULL, sep);
		b++;
	}
	free(actual_token);
	return (parsed_string);
}

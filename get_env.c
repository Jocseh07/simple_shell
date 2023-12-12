#include "simple_shell.h"

/**
 * get_env - get environment variables
 * @_env: env variables to get from environ
 * Return: env varible result from specific variable
 */

char *get_env(char *_env)
{
	int a = 0, b = 0;
	int found;

	for (a = 0; environ[a]; a++)
	{
		found = 1;

		for (b = 0; environ[a][b] != '='; b++)
		{
			if (environ[a][b] != _env[b])
				found = 0;
		}
		if (found == 1)
			break;
	}
	return (&environ[a][b + 1]);
}

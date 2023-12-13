#include "simple_shell.h"

/**
 * main - handle the command line arguments
 * @ac: number of command line arguments
 * @av: pointer to the command line arguments
 * Return: exit status
 */

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av)
{
	size_t exit_status = 0;
	int r, file;
	char *buffer;
	int skip = 0;

	if (ac == 2)
	{
		buffer = malloc(sizeof(char) * 1024);
		if (buffer == NULL)
			perror("malloc error in buffer");
		file = open(av[1], O_RDONLY);
		r = read(file, buffer, 1024);
		if (file == -1 || r == -1)
		{
			perror("Error: Can't read from file\n");
		}
	}

	if (skip == 0)
		exit_status = simple_shell();

	return (exit_status);
}

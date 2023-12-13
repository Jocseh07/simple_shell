#include "simple_shell.h"

/**
 * execute - execute command path with execve
 * @commands: commands to execute with execve
 * Return: exitstatus of the child process
 */

int execute(char **commands)
{
	int c_id;
	int wstatus, n;

	c_id = fork();

	if (c_id == 0)
	{
		n = execve(commands[0], commands, environ);
		if (n == -1)
			perror("Execve");
	}
	else
	{
		wait(&wstatus);
		if (WIFEXITED(wstatus))
			wstatus = WEXITSTATUS(wstatus);
	}

	return (wstatus);
}

#include "simple_shell.h"

/**
 * execute - execute command path with execve
 * @commands: commands to execute with execve
 * Return: exitstatus of the child process
 */

int execute(char **commands)
{
	pid_t c_id;
	int wstatus;

	c_id = fork();

	if (c_id == 0)
	{
		if (execve(commands[0], commands, environ) == -1)
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

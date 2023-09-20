#include "main.h"

/**
 * forkFunc - custom fork function
 * @tokArray: aray of tokens
 * @command: command string
 * Return: 0 if successful
 */
int forkFunc(char *command, char **tokArray)
{
	pid_t pid;
	int status, is_execve_error;

	pid = fork();
	if (pid == -1)
	{
		perror("forkFunc() Error: fork child unable to create");
		return (-1);
	}
	if (pid == 0)
	{
		is_execve_error = execve(command, tokArray, __environ);
		if (is_execve_error == -1)
		{
			perror("execve: ");
			return (-1);
		}
	}
	else
	{
		wait(&status);
		free(command);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		if (!isatty(STDIN_FILENO))
			return (status);
	}
	return (0);
}

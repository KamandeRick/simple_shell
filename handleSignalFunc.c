#include "main.h"

/**
 * handleSignalFunc - sissgnal handler
 * @signal: signal description
 * Return: nothing
 */
void handleSignalFunc(int signal)
{
	if (signal == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		prompt();
		fflush(stdout);
	}
}

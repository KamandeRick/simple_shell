#include "main.h"

/**
 * prompt - user prompt
 * Return: more than 0 on success else ruturns -1
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", strlen("$ "));
}


#include "main.h"

/**
 * exitBuiltin - Implement the exit built-in, that exits the shell
 * @tokenArray: command for array
 * Return: 1 if successfl else returns 0
 */
int exitBuiltin(char **tokenArray)
{
	if (tokenArray[1] != NULL)
		exit(atoi(tokenArray[1]));
	else
		return (EXIT_SUCCESS);
}

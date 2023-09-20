#include "main.h"

/**
 * exitFunc -  built-in command handler for the "exit" command
 * @tokArray: pointer to array of strings taken from command line
 * Return:  1 if successful 0 if failure
 */
int exitFunc(char **tokArray)
{
	if (tokArray[1] != NULL)
		exit(atoi(tokArray[1]));
	else
		return (EXIT_CODE);
}

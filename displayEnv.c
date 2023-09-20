#include "main.h"

/**
 * displayEnv - print environment
 * @tokArray: command array
 * Return: 0 for failure 1 for Sucess
 */
int displayEnv(__attribute((unused)) char **tokArray)
{
	int envIndex;

	for (envIndex = 0; __environ[envIndex]; envIndex++)
	{
		write(STDOUT_FILENO, __environ[envIndex],
				strlen(__environ[envIndex]));
		write(STDOUT_FILENO, "\n", strlen("\n"));
	}
	return (envIndex);
}

#include "main.h"

/**
 * displayEnvironment - prints working environment
 * @tokenArray: commands array
 * Return: 1 if successful else 0 on failure
 */
int displayEnvironment(__attribute((unused)) char **tokenArray)
{
	int envIndex;

	for (envIndex = 0; customEnviron[envIndex]; envtIndex++)
	{
		write(STDOUT_FILENO, customEnviron[envIndex],
				strlen(customEnviron[envIndex]));
		write(STDOUT_FILENO, "\n", strlen("\n"));
	}
	return (envIndex);
}

#include "main.h"

/**
 * printEnvFunc - print the contents of the environment vars to the stdo
 * Return: return 0
 */
int printEnvFunc(void)
{
	unsigned int indexEnv;

	for (indexEnv = 0; __environ[indexEnv]; indexEnv++)
		printf("%s\n", __environ[indexEnv]);
	return (0);
}

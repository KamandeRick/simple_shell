#include "main.h"

/**
 * unsetEnv - Removes an environment variable specified by the name parameter
 * @name: parameter for unsetEnv
 * Return: 0 on success and -1 on failure.
 */
int unsetEnv(const char *name)
{
	unsigned int envIndex;
	int new_envIndex, freeNew_EnvIndex, indexFound;
	char **environNew;

	environNew = NULL;
	envIndex = envLength();
	indexFound = envNameExists(name);
	if (indexFound != -1)
	{
		environNew = arrayMalloc(environNew, envIndex,
				"unsetEnv() Error: environNew malloc failed");
		for (new_envIndex = 0; __environ[new_envIndex]; new_envIndex++)
		{
			if (new_envIndex != indexFound)
			{
				environNew[new_envIndex] = malloc(sizeof(char) *
						strlen(__environ[new_envIndex]));
				if (environNew[new_envIndex] == NULL)
				{
					perror("unsetEnv() Error: environNew[new_envIndex] malloc failed");
					for (freeNew_EnvIndex = 0; freeNew_EnvIndex < new_envIndex;
							freeNew_EnvIndex++)
						free(environNew[new_envIndex]);
					free(environNew);
					return (-1);
				}
				strcpy(environNew[new_envIndex], __environ[new_envIndex]);
			}
		}
		environNew[envIndex] = NULL;
		__environ = environNew;
	}
	return (0);
}


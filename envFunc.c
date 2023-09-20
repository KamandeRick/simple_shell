#include "main.h"

/**
 * envFunc - custom function that handles the environment function
 * @name: environmtnt name
 * Return: return description
 */
char *envFunc(const char *name)
{
	unsigned int envIndex, enVarLen;
	char *enVar;
	char *enVarCopy;

	for (envIndex = 0; __environ[envIndex]; envIndex++)
	{
		if (strncmp(__environ[envIndex], name, strlen(name)) == 0)
		{
			enVarLen = strlen(__environ[envIndex]) - (strlen(name));
			enVar = malloc(sizeof(char) * enVarLen);
			if (enVar == NULL)
			{
				perror("envFunc() Error: enVar malloc failed");
				return (NULL);
			}
			charMalloc(&enVarCopy, strlen(__environ[envIndex]) + 1,
					"envFunc() malloc error");
			strcpy(enVarCopy, __environ[envIndex]);
			strncpy(enVar, enVarCopy += (strlen(name) + 1), enVarLen);
			free(enVarCopy -= (strlen(name) + 1));
			return (enVar);
		}
	}
	return (NULL);
}

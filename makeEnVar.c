#include "main.h"

/**
 * makeEnVar - Create env var str by concatenating name and value
 * @enVar: Stores the environment variable string created
 * @enVarLen: Stores the length of the environment variable
 * @name: nameof environment variable
 * @value: value to be assigned to environment variable
 * Return: returns value
 */
void makeEnVar(char **enVar, unsigned int enVarLen, const char *name,
		const char *value)
{
	*enVar = charMalloc(enVar, enVarLen,
			"_setenv() Error: enVar malloc failed");
	enVarLen = strlen(name) + strlen(value) + 2;
	*enVar = charMalloc(enVar, enVarLen,
			"_setenv() Error: enVar malloc failed");
	strcpy(*enVar, name);
	strcat(*enVar, "=");
	strcat(*enVar, value);
	strcat(*enVar, "\0");
}

/**
 * envExist - Check if env var with the same name as name exists
 * @enVar: Stores the environment variable string created
 * @enVarLen: Stores the length of the environment variable
 * @name: name string
 * @overwrite: overwrite integer
 * Return: return int
 */
int envExist(char *enVar, unsigned int enVarLen, const char *name,
		int overwrite)
{
	unsigned int envIndex;

	for (envIndex = 0; __environ[envIndex]; envIndex++)
	{
		if (strncmp(__environ[envIndex], name, strlen(name)) == 0 && overwrite != 0)
		{
			free(__environ[envIndex]);
			__environ[envIndex] = malloc(sizeof(char) * enVarLen);
			if (__environ[envIndex] == NULL)
			{
				perror("_setenv() Error: __environ[envIndex] malloc failed");
				free(enVar);
				return (-1);
			}
			strcpy(__environ[envIndex], enVar);
			free(enVar);
			return (0);
		}
	}
	return (0);
}

/**
 * envNoExist - Create a new env with an additional variable
 * @enVar: argument_1 description
 * @enVarLen: argument_2 description
 * @env_length: length of environment
 * Return: int
 */
int envNoExist(char *enVar, unsigned int enVarLen,
		unsigned int env_length)
{
	unsigned int freeNew_EnvIndex;
	char **environNew;

	environNew = (char **) malloc(sizeof(char *) * (env_length + 2));
	if (environNew == NULL)
	{
		perror("_setenv() Error: environNew malloc failed");
		free(enVar);
		return (-1);
	}
	arrayCopy(environNew, __environ);
	environNew[env_length] = malloc(sizeof(char) * enVarLen);
	if (environNew[env_length] == NULL)
	{
		perror("_setenv() Error: environNew[envIndex] malloc failed");
		for (freeNew_EnvIndex = 0; freeNew_EnvIndex < env_length;
				freeNew_EnvIndex++)
			free(environNew[freeNew_EnvIndex]);
		free(environNew);
		free(enVar);
		return (-1);
	}
	strcpy(environNew[env_length], enVar);
	environNew[env_length + 1] = NULL;
	free(enVar);
	__environ = environNew;
	return (0);
}

/**
 * _setenv - Set an env var  name to value
 * @name: name string
 * @value: value string
 * @overwrite: overwrite intger
 *
 * Return: -1 on failure 0 on success
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	unsigned int enVarLen;
	char *enVar;

	enVarLen = strlen(name) + strlen(value) + 2;
	makeEnVar(&enVar, enVarLen, name, value);
	envExist(enVar, enVarLen, name, overwrite);
	if (envNameExists(name) != -1)
		envExist(enVar, enVarLen, name, overwrite);
	else
		envNoExist(enVar, enVarLen, envLength());
	return (0);
}

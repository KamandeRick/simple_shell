#include "main.h"

/**
 * charMalloc - allocates memory for a character string
 * @string: pointer to character string
 * @mallocSize: malloc size int to be allocated
 * @error_message: error message string
 * Return: malloc returns
 */
char *charMalloc(char **string, size_t mallocSize, char *error_message)
{
	*string = (char *) malloc(sizeof(char) * mallocSize);
	if (string == NULL)
	{
		perror(error_message);
		return (NULL);
	}
	return (*string);
}

/**
 * arrayMalloc - array of memory alocated int
 * @array: reference to string
 * @mallocSize: int size of malloc
 * @error_message: string error message
 * Return: return description
 */
char **arrayMalloc(char **array, size_t mallocSize, char *error_message)
{
	array = (char **) malloc(sizeof(char *) * mallocSize);
	if (array == NULL)
	{
		perror(error_message);
		return (NULL);
	}
	return (array);
}

/**
 * arrayCopy - copies array
 * @destination: destination description
 * @source: source description
 * Return: return describr
 */
int arrayCopy(char **destination, char **source)
{
	size_t new_envIndex, freeNew_EnvIndex;

	for (new_envIndex = 0; source[new_envIndex]; new_envIndex++)
	{
		destination[new_envIndex] = malloc(sizeof(char) *
				strlen(source[new_envIndex]));
		if (destination[new_envIndex] == NULL)
		{
			perror("_setenv() Error: environNew[new_envIndex] malloc failed");
			for (freeNew_EnvIndex = 0; freeNew_EnvIndex < new_envIndex;
					freeNew_EnvIndex++)
				free(destination[new_envIndex]);
			free(destination);
			return (-1);
		}
		strcpy(destination[new_envIndex], source[new_envIndex]);
	}
	return (0);
}

/**
 * envNameExists - shows if env name exists
 * @name: name string
 * Return: is found
 */
int envNameExists(const char *name)
{
	int envIndex, is_found;

	is_found = -1;
	for (envIndex = 0; __environ[envIndex]; envIndex++)
		if (strncmp(__environ[envIndex], name, strlen(name)) == 0)
			is_found = envIndex;
	return (is_found);
}

/**
 * envLength - shows lenght
 * Return: return description
 */
int envLength(void)
{
	unsigned int env_length;

	for (env_length = 0; __environ[env_length]; env_length++)
		;
	return (env_length);
}


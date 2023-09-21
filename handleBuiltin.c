#include "main.h"

/**
 * yesBuiltin - Checks if given command is biultin
 * @tokArray: tokens in array representing the commands
 * Return: 1 if success 0 if failure
 */
int yesBuiltin(char **tokArray)
{
	int indexBuiltin;
	const struct builtin_command builtins[] = {
		{"env", displayEnv},
		{"exit", exitFunc},
		{NULL, NULL}
	};

	if (tokArray == NULL)
		return (0);
	if (tokArray[0] == NULL)
		return (0);

	for (indexBuiltin = 0; builtins[indexBuiltin].name != NULL;
			indexBuiltin++)
		if (strcmp(tokArray[0],
					builtins[indexBuiltin].name) == 0)
			return (1);
	return (0);
}

/**
 * handleBuiltinFunc - handles exec of builtins
 * @tokArray: array representing commands
 * Return: 1 if success 0 if failure
 */
int handleBuiltinFunc(char **tokArray)
{
	int indexBuiltin;
	const struct builtin_command builtins[] = {
		{"env", displayEnv},
		{"exit", exitFunc},
		{NULL, NULL}
	};

	if (tokArray == NULL)
		return (0);
	if (tokArray[0] == NULL)
		return (0);

	for (indexBuiltin = 0; builtins[indexBuiltin].name != NULL;
			indexBuiltin++)
	{
		if (strcmp(tokArray[0],
					builtins[indexBuiltin].name) == 0)
			return (builtins[indexBuiltin].function(tokArray));
	}
	return (0);
}



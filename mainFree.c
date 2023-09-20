#include "main.h"

/**
 * mainFree - frees memory assoc with array of toks and input str
 * @tokArray: tokenized string
 * @input: string
 * Return: void
 */
void mainFree(char **tokArray, char *input)
{
	int index;

	for (index = 0; tokArray[index]; index++)
		free(tokArray[index]);
	free(tokArray);
	free(input);
}

/**
 * whichFree - describe which
 * @pathVariable: argument_1 description
 * @tokArray: argument_2 description
 * Return: return description
 */
void whichFree(char **pathVariable, char **tokArray)
{
	int index;

	if (tokArray != NULL)
	{
		for (index = 0; tokArray[index]; index++)
			if (tokArray[index] != NULL)
				free(tokArray[index]);
		free(tokArray);
	}
	if (*pathVariable != NULL)
		free(*pathVariable);
}

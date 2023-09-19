#include "main.h"

/**
 * customFreeMain -  frees memory associated with an array of tokens
 * @tokenArray: array of stings tokenized
 * @input: string to generate tokenArray
 *
 * Return: void
 */
void customFreeMain(char **tokenArray, char *input)
{
	int index;

	for (index = 0; tokenArray[index]; index++)
		free(tokenArray[index]);
	free(tokenArray);
	free(input);
}

/**
 * customFreeWhich - frees memory associated with tokenarray and path variables
 * @customPathVar: pointer to path variable
 * @tokenArray: array of strigngs tokenized
 * Return: void
 */
void customFreeWhich(char **customPathVar, char **tokenArray)
{
	int index;

	if (tokenArray != NULL)
	{
		for (index = 0; tokenArray[index]; index++)
			if (tokenArray[index] != NULL)
				free(tokenArray[index]);
		free(tokenArray);
	}
	if (*customPathVar != NULL)
		free(*customPathVar);
}

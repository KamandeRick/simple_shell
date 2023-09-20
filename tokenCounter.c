#include "main.h"

/**
 * tokenCounter - Tokenizes input string and counts number of tokens
 * @input: input string
 * @delimiter: delimiter string
 * Return: Number on success else returns NULL
 */
size_t tokenCounter(char *input, char *delimiter)
{
	char *token;
	size_t tokCount;

	tokCount = 0;
	token = strtok(input, delimiter);
	while (token != NULL)
	{
		tokCount++;
		token = strtok(NULL, delimiter);
	}
	return (tokCount);
}
/**
 * makeTokArray - create NULL terminated array ofstring delimited
 * @input: input string
 * @delimiter: delimiter string
 * Return: returns NULL on failure and the array on success
 */
char **makeTokArray(char *input, char *delimiter)
{
	char *inputCopy, *token;
	char **tokArray;
	size_t tokCount, tokIndex, tokFreeIndex;

	tokArray = NULL;
	charMalloc(&inputCopy, strlen(input) + 1,
			"makeTokArray() Error: inputCopy malocc failure");
	strcpy(inputCopy, input);
	tokCount = tokenCounter(inputCopy, delimiter);
	tokArray = arrayMalloc(tokArray, tokCount + 1,
			"makeTokArray() Error: tokArray** malocc failure");
	strcpy(inputCopy, input);
	token = strtok(inputCopy, delimiter);
	for (tokIndex = 0; tokIndex < tokCount; tokIndex++)
	{
		tokArray[tokIndex] = (char *) malloc(sizeof(char) *
				strlen(token) + 1);
		if (tokArray[tokIndex] == NULL)
		{
			for (tokFreeIndex = 0;
					tokFreeIndex < tokIndex;
					tokFreeIndex++)
				free(tokArray[tokFreeIndex]);
			free(inputCopy);
			free(tokArray);
			perror("makeTokArray() Error: tokArray malocc failure");
			return (NULL);
		}
		strcpy(tokArray[tokIndex], token);
		token = strtok(NULL, delimiter);
	}
	free(inputCopy);
	tokArray[tokCount] = NULL;
	return (tokArray);
}

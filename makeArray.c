#include "main.h"

/**
 * countTokens - Returns number of tokens in a string
 * @delimiter: delimiter string
 * @input: input string
 * Return: number on success, else returns -1
 */
size_t countTokens(char *input, char *delimiter)
{
	char *token;
	size_t tokenCount;

	tokenCount = 0;
	token = strtok(input, delimiter);
	while (token != NULL)
	{
		tokenCount++;
		token = strtok(NULL, delimiter);
	}
	return (tokenCount);
}
/**
 * makeTokenArray - Takes string delimited and creates a null terminated array
 * @input: input string
 * @delimiter: delimiter string
 * Return: returns array on success else returns NULL
 */
char **makeTokenArray(char *input, char *delimiter)
{
	char *inputCopy, *token;
	char **tokenArray;
	size_t tokenCount, tokenIndex, tokenFreeIndex;

	tokenArray = NULL;
	customMallocChar(&inputCopy, strlen(input) + 1,
			"makeTokenArray() Error: inputCopy maoloc failure");
	strcpy(inputCopy, input);
	tokenCount = countTokens(inputCopy, delimiter);
	tokenArray = customMallocArray(tokenArray, tokenCount + 1,
			"makeTokenArray() Error: tokenArray** maoloc failure");
	strcpy(inputCopy, input);
	token = strtok(inputCopy, delimiter);
	for (tokenIndex = 0; tokenIndex < tokenCount; tokenIndex++)
	{
		tokenArray[tokenIndex] = (char *) malloc(sizeof(char) *
				strlen(token) + 1);
		if (tokenArray[tokenIndex] == NULL)
		{
			for (tokenFreeIndex = 0;
					tokenFreeIndex < tokenIndex;
					tokenFreeIndex++)
				free(tokenArray[tokenFreeIndex]);
			free(inputCopy);
			free(tokenArray);
			perror("makeTokenArray() Error: tokenArray maoloc failure");
			return (NULL);
		}
		strcpy(tokenArray[tokenIndex], token);
		token = strtok(NULL, delimiter);
	}
	free(inputCopy);
	tokenArray[tokenCount] = NULL;
	return (tokenArray);
}

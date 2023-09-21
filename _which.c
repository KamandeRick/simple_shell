#include "main.h"

/**
 * pathIsValid - function to tell if path is valid
 * @filename: string of file name
 * Return: 1 if file is executable 0 if non executable
 */
int pathIsValid(char *filename)
{
	size_t length = strlen(filename);

	if (length >= strlen("../"))
		if (strncmp(filename, "../", strlen("../")) == 0)
			return (1);
	if (length >= strlen("./"))
		if (strncmp(filename, "./", strlen("./")) == 0)
			return (1);
	if (length >= strlen("/"))
		if (strncmp(filename, "/", strlen("/")) == 0)
			return (1);
	return (0);
}

/**
 * createFilePath - function to create file path
 * @filePath: file path
 * @tokArray: array of tokens
 * @filename: file name string
 * @tokIndex: index to copy
 * Return: void
 */
void createFilePath(char **filePath, char **tokArray,
		char *filename, int tokIndex)
{
	charMalloc(filePath,
			(strlen(tokArray[tokIndex]) + strlen(filename) + 2),
			"_which Error: malloc failed for filePath");
	strcpy(*filePath, tokArray[tokIndex]);
	strcat(*filePath, "/");
	strcat(*filePath, filename);
	strcat(*filePath, "\0");
}

/**
 * _which - function for which
 * @filename: name of file
 * Return: return description
 */
char *_which(char *filename)
{
	struct stat sb;
	char *pathVariable, *delimiter, *filePath;
	char **tokArray;
	int tokIndex, filePathExist;

	delimiter = ":";
	pathVariable = envFunc("PATH");
	if (pathVariable != NULL)
	{
		tokArray = makeTokArray(pathVariable, delimiter);
		if (tokArray != NULL)
		{
			for (tokIndex = 0; tokArray[tokIndex]; tokIndex++)
			{
				createFilePath(&filePath, tokArray, filename, tokIndex);
				filePathExist = stat(filePath, &sb);
				if (filePathExist == 0)
				{
					whichFree(&pathVariable, tokArray);
					return (filePath);
				}
				free(filePath);
			}
			whichFree(&pathVariable, tokArray);
		}
		else
			free(pathVariable);
	}
	filePathExist = stat(filename, &sb);
	if (filePathExist == 0 && pathIsValid(filename))
		return (strdup(filename));
	return (NULL);
}

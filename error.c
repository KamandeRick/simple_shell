#include "main.h"

/**
 * error_not_found - Prints custommessage if command isnntnot found
 * @arvs: command-line args
 * @tokArray: tokenized array of strings
 * @cmdNum: counter
 * Return: void
 */
int error_not_found(char **arvs, char **tokArray, size_t cmdNum)
{
	char *error_str;
	char *cmdNum_str = _itoa(cmdNum);
	int size = (strlen(arvs[0]) + (2 * strlen(": ")) +
			digCounter(cmdNum) + strlen(tokArray[0]) +
			strlen(": not found\n") + 1);

	charMalloc(&error_str, size, "error_not_found Error: malloc error");
	strcpy(error_str, arvs[0]);
	strcat(error_str, ": ");
	strcat(error_str, cmdNum_str);
	strcat(error_str, ": ");
	strcat(error_str, tokArray[0]);
	strcat(error_str, ": not found\n");
	strcat(error_str, "\0");

	write(STDERR_FILENO, error_str, strlen(error_str));
	free(error_str);
	free(cmdNum_str);
	return (127);
}


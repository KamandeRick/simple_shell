#include "main.h"

/**
 * main - entrypoint of the program
 * @ac: arguments
 * @arvs: describe arg 2
 * @envp: describe arg 3
 * Return: description
 */
int main(__attribute((unused)) int ac,
		__attribute((unused)) char **arvs,
		__attribute((unused)) char **envp)
{
	int status = 0;
	char *input, *delimiter, *which;
	size_t mallocBytesAlloc, cmdNum;
	char **tokArray;

	signal(SIGINT, handleSignalFunc);
	input = NULL;
	mallocBytesAlloc = cmdNum = 0;
	delimiter = " \n";
	while (1)
	{
		cmdNum++;
		lineGet(&input, &mallocBytesAlloc, status);
		tokArray = makeTokArray(input, delimiter);
		if (!(*tokArray))
			status = 0;
		else
		{
			if (yesBuiltin(tokArray))
			{
				if (handleBuiltinFunc(tokArray) == EXIT_CODE)
				{
					mainFree(tokArray, input);
					exit(status);
				}
			}
			else
			{
				which = _which(tokArray[0]);
				if (which !=  NULL)
					status = forkFunc(which, tokArray);
				else
					status = error_not_found(arvs, tokArray, cmdNum);
			}
		}
		mainFree(tokArray, input);
		input = NULL;
	}
	return (0);
}

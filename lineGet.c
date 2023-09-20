#include "main.h"

/**
 * lineGet - gets the line
 * @input: input string
 * @mallocBytesAlloc: gives number of bytes allocated
 * @status: exit status
 *Return: more that 0 on success -1 if fail
 */
ssize_t lineGet(char **input,
		size_t *mallocBytesAlloc, int status)
{
	ssize_t charsRead;

	prompt();
	charsRead = getline(input,
			mallocBytesAlloc, stdin);
	if (charsRead == -1)
	{
		free(*input);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", strlen("\n"));
		exit(status);
	}
	return (charsRead);
}

#include "main.h"

/**
 * digCounter - counts the digits
 * @cmdNum: the number to be counted representing a command
 * Return: the number of the digits
 */
int digCounter(size_t cmdNum)
{
	int digitNumber = 0;

	if (cmdNum == 0)
		return (1);
	while (cmdNum != 0)
	{
		cmdNum /= 10;
		digitNumber++;
	}

	return (digitNumber);
}

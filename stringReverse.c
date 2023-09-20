#include "main.h"

/**
 * stringReverse - reverses a string
 * @str: the string
 * Return: void
 */
void stringReverse(char *str)
{
	int x, len;
	char tmp;

	len = 0;
	while (str[len] != '\0')
		len++;
	len--;
	for (x = 0; x < len; x++, len--)
	{
		tmp = str[x];
		str[x] = str[len];
		str[len] = tmp;
	}
}

/**
 * _itoa - converts int to a string
 * @cmdNum: number to convert
 * Return: the converted integer
 */
char *_itoa(size_t cmdNum)
{
	char *str = malloc(sizeof(char) * (32 + 1));
	int x = 0;

	do {
		str[x++] = cmdNum % 10 + '0';
		cmdNum /= 10;
	} while (cmdNum > 0);
	str[x] = '\0';
	stringReverse(str);

	return (str);
}


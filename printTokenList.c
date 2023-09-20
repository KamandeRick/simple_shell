#include "lists.h"
#include <stdio.h>

/**
 * printTokenList - prints all the elements of a tokenList list
 * @head: points to the first node
 * Return: node number
 */
size_t printTokenList(const tokenList *head)
{
	int count = 0;
	const tokenList *current;

	if (head == NULL)
		return (0);

	current = head;
	while (current != NULL)
	{
		printf("%s\n", current->token);
		count++;

		current = current->next;
	}

	return (count);
}

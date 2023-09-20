#include "lists.h"

/**
 * freeTokenList - frees a tokenList list
 * Description: free a tokenList list
 * @head: pointer to pointer that points to the first node
 * Return: void
 */
void freeTokenList(tokenList **head)
{
	tokenList *node;

	if (head == NULL)
		return;

	while (*head != NULL)
	{
		node = *head;
		*head = node->next;
		free(node->token);
		free(node);
	}
	head = NULL;
}

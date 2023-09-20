#include "lists.h"

/**
 * addTokenEnd - adds a new node at the end of a tokenList list
 * @head: pointer to  pointer that points to the first node
 * @token: the token to add
 * Return: the address of the new element, or NULL if it failed
 */
tokenList *addTokenEnd(tokenList **head, char *token)
{
	tokenList *nodeNew, *nodeLast;

	if (head == NULL)
		return (NULL);

	nodeNew = malloc(sizeof(tokenList));
	if (nodeNew == NULL)
		return (NULL);

	nodeNew->token = token;
	nodeNew->tokLen = strlen(token);
	nodeNew->next = NULL;

	if (*head == NULL)
		*head = nodeNew;
	else
	{
		nodeLast = *head;
		while (nodeLast->next != NULL)
			nodeLast = nodeLast->next;

		nodeLast->next = nodeNew;
	}

	return (nodeLast);
}

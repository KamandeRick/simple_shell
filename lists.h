#ifndef LISTS_H_
#define LISTS_H_

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct tokenList_s - singly linked list
 * @token: pointer to list
 * @tokLen: shows length of token
 * @next: points to the next node
 * Description: singly linked list node structure
 *
 */
typedef struct tokenList_s
{
	char *token;
	int tokLen;
	struct tokenList_s *next;
} tokenList;

size_t printTokenList(const tokenList *head);
size_t tokenListLen(const tokenList *head);
tokenList *addTokenEnd(tokenList **head, char *token);
void freeTokenList(tokenList **head);

#endif

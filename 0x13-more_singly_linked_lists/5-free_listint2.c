#include "lists.h"

/**
 * free_listint2 - lists of linked lists are freed by this
 * @head: listint_t list current are pointed by this
 */
void free_listint2(listint_t **head)
{
	listint_t *node, *temp;

	if (!head)
		return;
	node = *head;
	while (node)
	{
		temp = node;
		free(temp);
		node = node->next;
	}
	*head = NULL;
}

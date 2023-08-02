#include "lists.h"

/**
 * @head: lists of listint to release
 * free_listint linked lists are released by this
 *
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

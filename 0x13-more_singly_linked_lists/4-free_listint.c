#include "lists.h"

/**
 * free-listint - linked lists are freed by this one
 *
 * @head: lists of listint_t will be released
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

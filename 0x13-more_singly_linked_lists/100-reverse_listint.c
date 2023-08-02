#include "lists.h"

/**
 * reverse_listint - lists are reversed by this
 * @head- indicator of the first node
 *
 * Return- indicator of the first node, but on a brande new list
 *
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}

	*head = prev;

	return (*head);
}

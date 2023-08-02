#include "lists.h"

/**
 * @head- Linked lists very first node
 * sum_listint - calculator of the sum for the whole information
 *
 * Return- Whole sum
 *
 */
int sum_listint(listint_t *head)
{
	int summary = 0;
	listint_t *temp = head;

	while (temp)
	{
		summary += temp->n;
		temp = temp->next;
	}

	return (summary);
}

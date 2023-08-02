#include "lists.h"

/**
 * pop_listint Terminates the head node
 * @head: Destination of pointer
 * Return: Information of the terminated headnode
 *
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (!head || !*head)
		return (0);

	n = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (n);
}

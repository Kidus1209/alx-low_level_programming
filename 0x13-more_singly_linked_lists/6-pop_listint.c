#include "lists.h"

/**
 * pop_listint - destroys the head node of a linked_list
 * @head: A pointer to the 1st category in linked_list
 * Return: The value of the destroyed category
 *
 */
int pop_listint(listint_t **head)
{
	listint_t *node;
	int n;

	if (!head || !*head)
		return (0);

	num = (*head)->n;
	node = (*head)->next;
	free(*head);
	*head = node;

	return (num);
}

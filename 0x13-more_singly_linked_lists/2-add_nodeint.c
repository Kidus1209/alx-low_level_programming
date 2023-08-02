#include "lists.h"

/**
 * @n: information which will be inserted in the new node
 * @head: The first node is pointed by this
 * add_nodeint - brand new nods in  the beginning of a the list are added by this
 *
 * Return: indicator of the brand new node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}

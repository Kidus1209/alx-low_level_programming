#include "lists.h"

/**
 * print_listint - All categories of linked list are printed by this
 * @h: A list of listint_t type to be prited
 *
 * Return: All nodes together
 *
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
		printf("%d\n", h->n);
		num++;
		h = h->next;
	}

	return (num);
}

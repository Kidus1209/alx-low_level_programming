#include "lists.h"

/**
 * print_listint - It Prints All Section Of Singly Linked lists
 * @h: A Category Of Linked List That Points To The First Node
 *
 * Return: Amount Of node List
 */
size_t print_listint(const listint_t *h)
{
	size_t b = 0;

	while (h)
	{
		printf("%d\n", h->n);
		b++;
		h = h->next;
	}
	return (b);
}

#include <stdio.h>

/**
 * listint_len - Amount of categories in linked lists are returned back by this
 *
 * @h: The first node which is listint_t is pointed by this, its used as a pointer
 * Return: Amount of categories in listint_t
 */
size_t listint_len(const listint_t *h)
{
	size_t C = 0;

	while (h)
	{
		h = h->next;
		C++;
	}
	return (C);
}

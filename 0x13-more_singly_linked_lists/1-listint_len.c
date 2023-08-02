#include "lists.h"

/**
* @h: types of linked list listint_t
* listint_len - number of categories in linked list are returned by this
*
* Return: amount of nodes
*/
size_t listint_len(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
		num++;
		h = h->next;
	}

	return (num);
}

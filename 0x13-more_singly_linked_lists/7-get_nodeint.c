#include "lists.h"

/**
 * @index- indexes of the node
 *
 * @head: Indicator of the first node
 * get_nodeint_at_index nodes at returned back.
 *
 * Return- indicator of node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int n = 0;
	listint_t *temp = head;

	while (temp && n < index)
	{
		temp = temp->next;
		n++;
	}

	return (temp ? temp : NULL);
}

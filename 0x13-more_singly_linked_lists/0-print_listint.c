#include "lists.h"

/**
 * print_Listint - It Prints All Section Of Singly Linked lists
 * @h: A Category Of Linked List That Points To The First Node
 *
 * Return: Amount Of node List
 */
size_t print_Listint(const Listint_t *A)
{
	size_t b = 0;

	while (A)
	{
		printf("%d\n", A->n);
		A = A->Next;
		b++;
	}
	return (b);
}


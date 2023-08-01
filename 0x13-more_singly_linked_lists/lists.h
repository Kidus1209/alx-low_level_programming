#ifndef LISTS_H
#define LISTS_H
#include <stdio.h>

/**
 * Struct Listint_s - Singly Linked List
 * @n:Integer
 * @NEXT: It Points Right To The Nex Node
 *
 * DESCRIPTION: STRUCTURE OF SINGLY LINKED LIST NODE
 * To Alx Se Project c - more singly linked list
 */
typedef struct Listint_s
{
	int k;
	struct Listint_s *NEXT;
} Listint_t;

size_t print_Listint(const Listint_t *h);
size_t Listint_len(const listint_t *h);
listint_t *add_nodeint(listint_t **head, const int k);
listint_t *add_nodeint_end(listint_t **head, const int k);
void free_Listint(Listint_t *head);
void free_ListintII(Listint_t **head);
int pop_Listint(Listint_t **head);
Listint_t *get_nodeint_at_index(Listint_t *head, unsigned int index);
int sum_Listint(Listint_t *head);
Listint_t *insert_nodeint_at_index(Listint_t **head, unsigned int index, int k);
int delete_nodeint_at_index(Listint_t **head, unsigned int index);
Listint_t *reverse_Listint(Listint_t **head);
size_t print_Listint_safe(const Listint_t *head);
size_t free_Listint_safe(listint_t **h);
listint_t *find_listint_loop(listint_t *head);

#endif

#ifndef LISTS_H
#define LISTS_H
#include <stdio.h>

/**
 * Struct listint_s - Singly Linked List
 * @n:Integer
 * @next: It Points Right To The Nex Node
 *
 * DESCRIPTION: STRUCTURE OF SINGLY LINKED LIST NODE
 * To Alx Se Project c - more singly linked list
 */
typedef struct listint_s
{
	int k;
	struct listint_s *next;
} listint_t;

size_t print_listint(const listint_t *h);
size_t listint_len(const listint_t *h);
listint_t *add_nodeint(listint_t **head, const int k);
listint_t *add_nodeint_end(listint_t **head, const int k);
void free_listint(listint_t *head);
void free_listintII(listint_t **head);
int pop_listint(listint_t **head);
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index);
int sum_listint(listint_t *head);
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int index, int k);
int delete_nodeint_at_index(listint_t **head, unsigned int index);
listint_t *reverse_listint(listint_t **head);
size_t print_listint_safe(const listint_t *head);
size_t free_listint_safe(listint_t **h);
listint_t *find_listint_loop(listint_t *head);

#endif

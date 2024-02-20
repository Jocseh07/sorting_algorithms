#include "sort.h"

/**
 * swap_nodes - swap 2 nodes in a doubly linked list
 * @list: head of the doubly linked list
 * @p: pointer to first node to swap
 * @n: pointer to second node to swap
 */

void swap_nodes(listint_t **list, listint_t **p, listint_t **n)
{
	(*p)->next = (*n)->next;
	if ((*n)->next != NULL)
		(*n)->next->prev = (*p);
	(*n)->prev = (*p)->prev;
	(*n)->next = (*p);
	if ((*p)->prev != NULL)
		(*p)->prev->next = (*n);
	else
		*list = (*n);
	(*p)->prev = (*n);
	(*p) = (*n)->prev;
}

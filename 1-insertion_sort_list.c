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

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: list to be sorted in ascending order
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *n, *p, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (n = (*list)->next; n != NULL; n = temp)
	{
		temp = n->next;
		p = n->prev;
		while (p != NULL && n->n < p->n)
		{
			swap_nodes(list, &p, &n);
			print_list((const listint_t *)*list);
		}
	}
}

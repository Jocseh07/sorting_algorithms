#include "sort.h"

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

#include "sort.h"

/**
 * insertion_sort_list - Function sorting a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm.
 * @list: Doubly linked list from an array of integers.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *iteration, *insertion, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	
	/* Move through the list from 2nd node until end */
	for (iteration = (*list)->next; iteration != NULL; iteration = temp)
	{
		temp = iteration->next;
		insertion = iteration->prev;
		
		/* Match correct position of iteration in list */
		while (insertion != NULL && iteration->n < insertion->n)
		{
			swap_nodes(list, &insertion, iteration);
			print_list((const listint_t *)*list);
		}
	}
}

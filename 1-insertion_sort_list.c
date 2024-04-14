#include "sort.h"

/**
 * swap_nodes - Swap two nodes in listint_t doubly-linked list.
 * @h: Pointer to head of doubly-linked list.
 * @n1: Pointer to first node to swap.
 * @n2: Second node to swap.
 */

void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;

        if (n2->next != NULL)
        {
                n2->next->prev = *n1;
        }

        n2->prev = (*n1)->prev;
        n2->next = *n1;

        if ((*n1)->prev != NULL)
        {
                (*n1)->prev->next = n2;
        }
        else
        {
                *h = n2;
        }

        (*n1)->prev = n2;
        *n1 = n2->prev;
}

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

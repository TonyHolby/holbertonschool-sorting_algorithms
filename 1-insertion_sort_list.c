#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm.
 * @list: a doubly linked list from an array of integers.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *prev_node, *next_node;

	if (*list == NULL || (*list)->next == NULL)
	{
		return;
	}

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			prev_node = temp->prev;
			next_node = temp->next;
			if (prev_node->prev != NULL)
			{
				prev_node->prev->next = next_node;
			}

			temp->prev = prev_node->prev;
			temp->next = prev_node;
			prev_node->prev = temp;
			prev_node->next = next_node;

			if (next_node != NULL)
			{
				next_node->prev = prev_node;
			}

			if (temp->prev == NULL)
			{
				*list = temp;
			}
			print_list(*list);
		}
		current = current->next;
	}
}


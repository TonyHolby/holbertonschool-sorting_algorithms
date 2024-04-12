#include "sort.h"

/**
 * bubble_sort - a function that sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 * @array: an array of integers.
 * @size: the size of the array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, k;
	int temp, swap_elements;

	for (i = 0; i < size - 1; i++)
	{
		swap_elements = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			/**
			 * if two integers are switched, swap_elements takes
			 * the value 1.
			 */
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				swap_elements = 1;
			}
		}

		/**
		 * if no integers are switched, the array is already sort and
		 * the algorithme is stopped.
		 */
		if (swap_elements == 0)
		{
			break;
		}

		for (k = 0; k < size; k++)
		{
			printf("%d", array[k]);
			if (k < size - 1)
			{
				printf(", ");
			}
		}
	}

	printf("\n");
}

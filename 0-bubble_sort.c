#include "sort.h"

/**
 * bubble_sort - Sort array with bubble sort algorithm.
 * @array: Array of integers.
 * @size: Size of array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, k;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;

				for (k = 0; k < size; k++)
				{
					printf("%d", array[k]);
					if (k < size - 1)
					{
						printf(", ");
					}
				}
				printf("\n");
			}
		}
	}
}


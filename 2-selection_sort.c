#include "sort.h"

/**
 * swap_values - Swap two values.
 * @a: First value to swap.
 * @b: Second value to swap.
 */

void swap_values(int *a, int *b)
{
        int tmp;

        tmp = *a;
        *a = *b;
        *b = tmp;
}
/**
 * selection_sort - Sort array with selection sort algorithm.
 * @array: Array of integers.
 * @size: Size of array.
 */

void selection_sort(int *array, size_t size)
{
        int *min;
        size_t i, j;

        if (array == NULL || size < 2)
        {
                return;
        }

        for (i = 0; i < size - 1; i++)
        {
                min = array + i;

                for (j = i + 1; j < size; j++)
                {
                        min = (array[j] < *min) ? (array + j) : min;
                }

                if ((array + i) != min)
                {
                        swap_values(array + i, min);
                        print_array(array, size);
                }
        }
}

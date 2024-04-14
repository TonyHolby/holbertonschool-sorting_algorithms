#include "sort.h"

void swap_values(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - Order subset according to the last element as pivot.
 * @array: Array of integers.
 * @size: Size of the array.
 * @left: Starting index of the subset to order.
 * @right: Ending index of the subset to order.
 * Return: Final partition index.
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
        int *pivot, greater, lower;

        /* Define pivot as last element of sub-array */
        pivot = array + right;
        for (greater = lower = left; lower < right; lower++)
        {
                if (array[lower] < *pivot)
                {
                        if (greater < lower)
                        {
                                swap_values(array + lower, array + greater);
                                print_array(array, size);
                        }
                        greater++;
                }
        }

        if (array[greater] > *pivot)
        {
                swap_values(array + greater, pivot);
                print_array(array, size);
        }

        return (greater);
}

/**
 * lomuto_sort - Use the Lomuto partition scheme.
 * @array: Array of integers.
 * @size: Size of array.
 * @left: Starting index of array to order.
 * @right: Ending index of array to order.
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
        int part;

        if (right - left > 0)
        {
                /* get index of pivot */
                part = lomuto_partition(array, size, left, right);
                /* sort array part before pivot */
                lomuto_sort(array, size, left, part - 1);
                /* sort array part after pivot */
                lomuto_sort(array, size, part + 1, right);
        }
}

/**
 * quick_sort - Sort array with quicksort algorithm.
 * @array: Array of integers.
 * @size: Size of array.
 */

void quick_sort(int *array, size_t size)
{
        if (array == NULL || size < 2)
        {
                return;
        }

        lomuto_sort(array, size, 0, size - 1);
}

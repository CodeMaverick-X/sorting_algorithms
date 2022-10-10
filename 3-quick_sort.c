#include "sort.h"

/**
 * swap - performs value swap at indexes
 * @x: first value to swap
 * @y: second value to swap
 *
 */

void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * partition - performs lomuto partition in the array
 * @array: the array to be sorted
 * @size: size of the array
 * @min: the left-most element in the array (minimum index)
 * @max: the right-most element in the array (maximum index)
 *
 * Return: the partition index (location to partition from)
 */

int lomuto_partition(int *array, size_t size, int min, int max)
{
	int i, j, pivot_val;

	i = min;
	pivot_val = array[max];

	for (j = min; j < max; j++)
	{
		if (array[j] <= pivot_val)
		{
			swap(&array[i], &array[j]);
			i++;
		}
	}

	swap(&array[i], &array[max]);
	print_array(array, size);

	return (i);
}


/**
 * quicksort_recursion - performs quicksort using lomuto partition recursively
 * @array: array to be sorted
 * @size: size of the array
 * @min: leftmost elememt in array
 * @max: rightmost element in the array
 *
 */

void quicksort_recursion(int *array, size_t size, int min, int max)
{
	int pivot_idx;

	if (min < max)
	{
		pivot_idx = lomuto_partition(array, size, min, max);
		quicksort_recursion(array, size, min, pivot_idx - 1);
		quicksort_recursion(array, size, pivot_idx + 1, max);
	}
}


/**
 * quick_sort - calls recursive quicksort function
 * @array: array to be sorted
 * @size: size of the array
 *
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_recursion(array, size, 0, size - 1);
}

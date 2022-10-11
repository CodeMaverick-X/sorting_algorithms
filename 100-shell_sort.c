#include "sort.h"

/**
 * shell_sort - sorts an array using the shell sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: No return
 */

void shell_sort(int *array, size_t size)
{
	int value;
	size_t n = 1;
	size_t i, j;

	while (n < size / 3)
		n = n * 3 + 1;

	while (n > 0)
	{
		for (i = n; i < size; i++)
		{
			value = array[i];
			j = i;

			while (j > n - 1 && array[j - n] >= value)
			{
				array[j] = array[j - n];
				j = j - n;
			}

			array[j] = value;
		}
		n = (n - 1) / 3;
		print_array(array, size);
	}
}

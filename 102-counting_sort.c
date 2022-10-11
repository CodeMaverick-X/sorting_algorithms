#include "sort.h"

/**
 * counting_sort - sorts an array using the counting sort algo
 * @array: the array to be sorted
 * @size: size of the array
 *
 * Return: None
 */

void counting_sort(int *array, size_t size)
{
	int *new_arr, *count, i, max;

	new_arr = malloc(sizeof(int) * size);
	if (!array)
	{
		free(new_arr);
		return;
	}
	max = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * (max + 1));
	for (i = 0; i <= max; ++i)
		count[i] = 0;

	if (!count)
	{
		free(count);
		return;
	}
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = size - 1; i >= 0; i--)
	{
		new_arr[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int)size; ++i)
		array[i] = new_arr[i];

	free(count);
	free(new_arr);
}

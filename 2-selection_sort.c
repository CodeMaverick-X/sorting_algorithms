#include "sort.h"
/**
 * selection_sort - slection sort for arrays
 * @array: array to be sorted
 * @size: size of the array to be sorted
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min_pos, temp;

	for (i = 0; i < size - 1; i++)
	{
		min_pos = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_pos])
				min_pos = j;
		}
		if (min_pos != i)
		{
			temp = array[i];
			array[i] = array[min_pos];
			array[min_pos] = temp;
			print_array(array, size);
		}
	}
}

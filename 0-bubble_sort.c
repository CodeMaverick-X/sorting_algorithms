#include "sort.h"

/**
 * bubble_sort - a sorting algorithm that sorts arrays
 * @array: the array to be sorted
 * @size: size of the array to be sorted
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int flag = 1;

	for (i = 0; i < size && flag == 1; i++)
	{
		flag = 0;
		for (j = 0; j < (size - 1 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = 1;
			}
		}
	}
}

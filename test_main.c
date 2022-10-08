#include "sort.h"

/**
 * main - testsing the sorting function
 * Description: tests funcion
 * Return: 0
 */

int main(void)
{
	int array[] = {19, 48, 99, 6, 9, 11, 13, 20, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	bubble_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}

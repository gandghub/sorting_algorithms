#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, min_idx = 0;
	int tmp;

	if (!array || size < 2)
		return;
	while (i < size - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
			j++;
		}
		if (min_idx != i)
		{
			tmp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}
		i++;
	}
}

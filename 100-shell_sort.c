#include "sort.h"
/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm with Knuth sequence
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
	size_t kunth[1000], k = 0, j = 0, i;
	int n, g;

	if (!array)
		return;
	while (j * 3 + 1 < size)
	{
		kunth[k] = j * 3 + 1;
		j = kunth[k++];
	}
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < size; j++)
		{
			if ((j + kunth[k - i - 1]) > size - 1)
				break;
			g = j;
			while (array[g] > array[g + kunth[k - i - 1]])
			{
				n = array[g];
				array[g] =  array[g + kunth[k - i - 1]];
				array[g + kunth[k - i - 1]] = n;
				g = g - kunth[k - i - 1];
				if (g < 0)
					break;
			}
		}
		print_array(array, size);
	}
}

#include "sort.h"

/**
 * partition scheme
 * @array: The array to be sorted
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 * @size: Number of elements in @array
 * Return: index of the pivot
*/
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i = low - 1, tmp;
	int j = low;

	while (j < high)
	{
		if (array[j] <= pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (i != j)
				print_array(array, size);
		}
		j++;
	}
	tmp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = tmp;
	if (i + 1 != j)
		print_array(array, size);
	return (i + 1);
}

/**
  * quick_sort_recursive - Recursive function to perform quick sort
 * @array: The array to be sorted
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 * @size: Number of elements in @array
*/

void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high, size);

		quicksort(array, low, pivot_index - 1, size);
		quicksort(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	quicksort(array, 0, size - 1, size);
}

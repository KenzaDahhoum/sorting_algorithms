#include "sort.h"

/**
 * partition - Implements the Lomuto partition scheme.
 * @array: The array to partition.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: The size of the array.
 *
 * Return: The partition index.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
			{
				print_array(array, size);
			}
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	if (i + 1 != high)
	{
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_rec - applies the Quick sort algorithm using the Lomuto
 * partition scheme.
 * @array: The array to sort.
 * @low: Starting index.
 * @high: Ending index.
 * @size: The size of the array.
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partition(array, low, high, size);

		quick_sort_rec(array, low, pi - 1, size);
		quick_sort_rec(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Main entry point for the Quick sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	quick_sort_rec(array, 0, size - 1, size);
}

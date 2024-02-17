#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, smaller;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		smaller = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smaller])
			{
				smaller = j;
			}
		}
		if (smaller != i)
		{
			temp = array[i];
			array[i] = array[smaller];
			array[smaller] = temp;
			print_array(array, size);
		}
	}
}

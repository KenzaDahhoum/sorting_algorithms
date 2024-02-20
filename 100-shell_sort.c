#include "sort.h"

/**
  *max_gap - a largest knuth sequence gap for this size
  *@size: the size of array
  *
  *Return: the gap size
  */

size_t max_gap(size_t size)
{
	size_t n;

	n = 1;
	while (n < size)
	{
		n = n * 3 + 1;
	}
	return ((n - 1) / 3);

}

/**
  *shell_sort - shell sort function
  *@array: the integer array of sort
  *@size: size of array
  *
  *Return: void
  */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int tmp;

	if (!array || !size)
		return;

	for (gap = max_gap(size); gap; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j > gap - 1 && array[j - gap] > tmp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}

}

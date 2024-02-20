#include "sort.h"

/**
  *compare_merge - compare merges
  *@array: integer array to sort
  *@start: the index to start
  *@stop: the index to stop
  *@new_array: the output array
  */

void compare_merge(int *array, size_t start, size_t stop, int *new_array)
{
	size_t i, j, k, midle;

	i = start;
	j = midle = (start + stop) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, midle - start);
	printf("[right]: ");
	print_array(array + midle, stop - midle);
	for (k = start; k < stop; k++)
	{
		if (i < midle && (j >= stop || array[i] <= array[j]))
		{
			new_array[k] = array[i++];
		}
		else
		{
			new_array[k] = array[j++];
		}
	}
	printf("[Done]: ");
	print_array(new_array + start, stop - start);
}

/**
 *sort_top_down - sort top-down recursively
 *@array: the integer array to sort
 *@start: the start index
 *@stop: the stop index
 *@new_array: the output array
 *
 *Return: void
 */

void sort_top_down(int *array, size_t start, size_t stop, int *new_array)
{
	size_t midle;

	midle = (start + stop) / 2;
	if (stop - start < 2)
	{
		return;
	}
	sort_top_down(new_array, start, midle, array);
	sort_top_down(new_array, midle, stop, array);
	compare_merge(array, start, stop, new_array);

}

/**
  *merge_sort - sorts by merge sort algo
  *@array: the integer array of sort
  *@size: the size of array
  *
  *Return: void
  */
void merge_sort(int *array, size_t size)
{
	int *new_array;
	size_t i;

	if (!array || size < 2)
		return;

	new_array = malloc(sizeof(int) * size);
	if (!new_array)
		return;
	for (i = 0; i < size; i++)
	{
		new_array[i] = array[i];
	}
	sort_top_down(new_array, 0, size, array);
	free(new_array);
}


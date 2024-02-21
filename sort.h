#ifndef _SORT_H
#define _SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define parent(x) (((x) - 1) / 2)
#define leftchild(x) (((x) * 2) + 1)

/**
 *struct listint_s - Doubly linked list node
 *
 *@n: Integer stored in the node
 *@prev: Pointer to the previous element of the list
 *@next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*print */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
/* prototype */

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);

/* helper functions */
void swap(listint_t *a, listint_t *b);
size_t max_gap(size_t size);
void compare_merge(int *array, size_t start, size_t stop, int *new_array);
void sort_top_down(int *array, size_t start, size_t stop, int *new_array);
void swap(int *array, size_t size, int *a, int *b);
void siftdown(int *array, size_t start, size_t end, size_t size);
void heapify(int *array, size_t size);

#endif

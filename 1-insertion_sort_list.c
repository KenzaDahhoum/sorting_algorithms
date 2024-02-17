#include "sort.h"

/**
 * swap - Swaps two adjacent nodes in a doubly linked list
 * @a: The first node to swap
 * @b: The second node to swap
 */
void swap(listint_t *a, listint_t *b)
{
	if (a->prev != NULL)
	{
		a->prev->next = b;
	}
	if (b->next != NULL)
	{
		b->next->prev = a;
	}

	a->next = b->next;
	b->next = a;
	b->prev = a->prev;
	a->prev = b;
}

/**
 * insertion_sort_list - Sorts a doubly linked list
 *of integers in ascending order
 * using the Insertion sort algorithm
 * @list: A double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (!list || !*list || !(*list)->next)
		return;

	i = (*list)->next;
	while (i != NULL)
	{
		j = i;
		i = i->next;
		while (j && j->prev && j->prev->n > j->n)
		{
			swap(j->prev, j);
			if (!j->prev)
			{
				*list = j;
			}
			print_list(*list);
		}
	}
}

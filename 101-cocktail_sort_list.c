#include "sort.h"

/**
 * find_len - find the length of a list
 * @list: pointer to a list
 *
 * Description: This function finds the length of a list
 * Return: int
 */
int find_len(listint_t *list)
{
	int list_len = 0;

	while (list)
	{
		list_len++;
		list = list->next;
	}
	return (list_len);
}

/**
 * swap - swap pointers to nodes
 * @list: a list
 * @pointer: a pointer to a node
 *
 * Description: This function switches the node pointing to different head
 * Return: void
 */
void swap(listint_t **list, listint_t **pointer)
{
	listint_t *pt1, *pt2;
	listint_t *pt3, *pt4;

	pt1 = (*pointer)->prev;
	pt2 = *pointer;
	pt3 = (*pointer)->next;
	pt4 = (*pointer)->next->next;
	pt2->next = pt4;
	if (pt4)
		pt4->prev = pt2;
	pt3->next = pt2;
	pt3->prev = pt2->prev;
	if (pt1)
		pt1->next = pt3;
	else
		*list = pt3;
	pt2->prev = pt3;
	*pointer = pt3;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * @list: a doubly linked list
 *
 * Description: This function sorts a doubly linked list of integers in
 * ascending order using the cocktail shaker sort algorithm
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *pointer;
	int s = 0;

	if (!list || !*list || find_len(*list) < 2)
		return;
	pointer = *list;
	do {
		s = 1;
		do {
			if (pointer->n > pointer->next->n)
			{
				s = 0;
				swap(list, &pointer);
				print_list(*list);
			}
			else
				pointer = pointer->next;
		} while (pointer->next);
		if (s)
			break;
		pointer = pointer->prev;
		do {
			if (pointer->n < pointer->prev->n)
			{
				s = 0;
				pointer = pointer->prev;
				swap(list, &pointer);
				print_list(*list);
			}
			else
				pointer = pointer->prev;
		} while (pointer->prev);
	} while (!s);
}


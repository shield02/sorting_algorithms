#include "sort.h"

/**
 * find_len - find te length of a list
 * @list: pointer to a list
 *
 * Description: This function finds the length of a list
 * Returns: int
 */
int find_len(listint_t *list)
{
	int list_len = 0;

	while (list)
	{
		list_len++;
		list = list->next;
	}
	return list_len;
}

/**
 * insertion_sort_list - sorts linked list of integers in ascending order
 * @list: pointer to a pointer of a list
 *
 * Description: function that sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *clist, *pst1, *pst2;
	listint_t *pst3, *pst4;

	if (!(*list) || find_len(*list) < 2)
		return;
	clist = *list;
	while (clist)
	{
		if (clist->prev && clist->n < clist->prev->n)
		{
			pst1 = clist->prev->prev;
			pst2 = clist->prev;
			pst3 = clist;
			pst4 = clist->next;

			pst2->next = pst4;
			if (pst4)
				pst4->prev = pst2;
			pst3->next = pst2;
			pst3->prev = pst1;
			if (pst1)
				pst1->next = pst3;
			else
				*list = pst3;
			pst2->prev = pst3;
			clist = *list;
			print_list(*list);
			continue;
		}
		else
			clist = clist->next;
	}
}

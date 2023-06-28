#include "sort.h"

/**
 * selection_sort - sort array of integers
 * @array: array of int
 * @size: size of the array
 *
 * Description: This function sorts an array of integers in ascending
 * order using the selection algorithm
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t k, l, lest, temp;

	if (size < 2)
		return;

	for (k = 0; k < size; k++)
	{
		lest = k;
		for (l = k + 1; l < size; l++)
		{
			if (array[l] < array[lest])
				lest = l;
		}
		temp = array[k];
		array[k] = array[lest];
		array[lest] = temp;
		print_array(array, size);
	}
}

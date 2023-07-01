#include "sort.h"

/**
 * merge_seq - merge a sorted sequence
 * @array: array to be sorted
 * @first: index of first element
 * @last: index of last element
 * @dir: direction of sorting
 *
 * Description: This function sorts and merges an array
 * in increasing or decreasing direction
 * Return: void
 */
void merge_seq(int *array, int first, int last, int dir)
{
	int temp, i, s, m;

	s = (first + last) / 2;
	m = ((last - first) + 1) / 2;

	if (last - first >= 1)
	{
		for (i = first; i < first + m; i++)
		{
			if (dir == (array[i] > array[i + m]))
			{
				temp = array[i + m];
				array[i + m] = array[i];
				array[i] = temp;
			}
		}
		merge_seq(array, first, s, dir);
		merge_seq(array, s + 1, last, dir);
	}
}

/**
 * apply_recursion - recursively apply bitonic sort
 * @array: array to be sorted
 * @first: index of first element
 * @last: index of last element
 * @dir: direction of sorting
 * @size: size of array
 *
 * Description: The function will recursively apply the bitonic sort
 * algorithm to an array of integers
 * Return: void
 */
void apply_recursion(int *array, int first, int last, int dir, size_t size)
{
	int m;

	if (last - first >= 1)
	{
		m = (last + first) / 2;
		printf("Merging[%d/%lu] ", (last - first) + 1, size);
		if (dir)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + first, (last - first) + 1);
		apply_recursion(array, first, m, 1, size);
		apply_recursion(array, m + 1, last, 0, size);
		merge_seq(array, first, last, dir);
		printf("Result [%d/%lu] ", (last - first) + 1, size);
		if (dir)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + first, (last - first) + 1);
	}
}

/**
 * bitonic_sort - sorts an array of integers using bitonic sort algo
 * @array: array to be sorted
 * @size: size of the array
 *
 * Description: The function sorts an array of integers in ascending
 * order using the Bitonic sort algorithm
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	apply_recursion(array, 0, size - 1, 1, size);
}


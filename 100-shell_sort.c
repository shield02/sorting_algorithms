#include "sort.h"

/**
 * shell_sort - sort array of integers using shell sort algo
 * @array: array of int
 * @size: size of the array
 *
 * Description: This function that sorts an array of integers in
 * ascending order using the Shell sort algorithm,
 * using the Knuth sequence
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j;
	size_t gap = 0;
	int temp;

	if (size < 2 || array == NULL)
		return;
	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;
	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && temp <= array[j - gap]; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}


#include "sort.h"

/**
 * counting_sort - sorts an array of integers using counting sort algo
 * @array: an array
 * @size: the size of the array
 *
 * Description: function that sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max;
	int i;

	if (size < 2 || array == NULL)
		return;
	max = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(size_t) * (max + 1));
	if (count == NULL)
		return;
	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
	{
		free(count);
		return;
	}
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];
	free(count);
	free(sorted);
}


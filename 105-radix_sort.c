#include "sort.h"

/**
 * lsd_count - least significant digit count
 * @array: array of elements
 * @size: size of the array
 * @lsd: least significant digit
 *
 * Description: This function performs a sort using least significant digit
 * Return: void
 */
void lsd_count(int *array, size_t size, size_t lsd)
{
	int lsd_array[10] = {0}, *p, i;

	p = malloc(sizeof(int) * size);
	if (p == NULL)
		return;

	for (i = 0; i < (int)size; i++)
		lsd_array[(array[i] / lsd) % 10]++;
	for (i = 1; i < 10; i++)
		lsd_array[i] += lsd_array[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		p[lsd_array[(array[i] / lsd) % 10] - 1] = array[i];
		lsd_array[(array[i] / lsd) % 10]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = p[i];
	free(p);
}

/**
 * radix_sort - sorts an array of integers using radix sort algo
 * @array: array of elements
 * @size: size of the array
 *
 * Description: This function sorts an array of integers in ascending
 * order using the Radix sort algorithm
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	size_t lsd, i;
	int max = 0;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	for (lsd = 1; max / lsd > 0; lsd *= 10)
	{
		lsd_count(array, size, lsd);
		print_array(array, size);
	}
}


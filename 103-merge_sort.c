#include "sort.h"

/**
 * merge_sub - makes subarray and merges them
 * @carray: a copy of array
 * @array: the array to be merged
 * @left: left element index
 * @middle: middle element index
 * @right: right element index
 *
 * Description: This function merges the elements of a subarray
 * Return: void
 */
void merge_sub(int *carray, int *array, size_t left, size_t middle, size_t right)
{
	size_t i, j, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, middle  - left);
	printf("[right]: ");
	print_array(array + middle, right - middle);

	for (i = left, j = middle; i < middle && j < right; k++)
	{
		if (array[i] < array[j])
			carray[k] = array[i++];
		else
			carray[k] = array[j++];
	}
	do {
		carray[k++] = array[i++];
	} while (i < middle);
	do {
		carray[k++] = array[j++];
	} while (j < right);
	for (k = left, i = 0; k < right; k++)
		array[k] = carray[i++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * apply_recursion - recursively apply the merge sort
 * @carray: a copy of the array
 * @array: array of elements to be used
 * @left: int variable
 * @right: int variable
 *
 * Description: This function recursively apply the merge sort to an array
 * Return: void
 */
void apply_recursion(int *carray, int *array, int left, int right)
{
	int mid;

	if (right - left > 1)
	{
		mid = (right - left) / 2 + left;
		apply_recursion(carray, array, left, mid);
		apply_recursion(carray, array, mid, right);
		merge_sub(carray, array, left, mid, right);
	}
}

/**
 * merge_sort - sorts an array of integers using merge sort algo
 * @array: array of elements
 * @size: size of the array
 *
 * Description: This function sorts an array of integers in ascending
 * order using the Merge sort algorithm
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *pointer;

	if (size < 2 || array == NULL)
		return;
	pointer = malloc(sizeof(int) * size);
	if (pointer == NULL)
		return;
	apply_recursion(pointer, array, 0, size);
	free(pointer);
}


#include "sort.h"

/**
 * create_partition - rearrange all smaller elements to the left of pivot
 * @array: array of elements to be used
 * @left: int variable
 * @right: int variable
 * @size: size of the array
 *
 * Description: This function rearranges the elements such that all
 * the elemets lower than the pivot are on the left
 * Return: int
 */
int create_partition(int *array, int left, int right, size_t size)
{
	int temp;
	int pivot = array[right];
	size_t i = left - 1;
	size_t j = right + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i >= j)
			return (i);
		if (i != j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	return (0);
}

/**
 * apply_recursion - repeat selecting pivot and partition
 * @array: array of elements to be used
 * @left: int variable
 * @right: int variable
 * @size: size of the array
 *
 * Description: This function repeats pivot selection and creating of
 * partition
 * Return: void
 */
void apply_recursion(int *array, int left, int right, size_t size)
{
	int pos;

	if (left < right)
	{
		pos = create_partition(array, left, right, size);
		apply_recursion(array, left, pos - 1, size);
		apply_recursion(array, pos, right, size);
	}
}

/**
 * quick_sort_hoare - sorts array of int using quick sort hoare algo
 * @array: array of elements
 * @size: size of the array
 *
 * Description: The function sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	apply_recursion(array, 0, (int)size - 1, size);
}


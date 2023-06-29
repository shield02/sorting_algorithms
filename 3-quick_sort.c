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
	int pivot, i, j, temp;

	pivot = array[right];
	i = left;
	for (j = left; j < right; j++)
	{
		if (array[j] <= pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
		i++;
	}
	temp = array[i];
	array[i] = array[right];
	array[right] = temp;
	if (i != j)
		print_array(array, size);
	return (i);
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
		apply_recursion(array, pos + 1, right, size);
	}
}

/**
 * quick_sort - sort an array of integers using qucik sort
 * @array: array of elements
 * @size: size of the array
 *
 * Description: function that sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (size > 2)
		return;
	apply_recursion(array, 0, (int)size - 1, size);
}

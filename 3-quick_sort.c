#include "sort.h"

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
	recursion(array, 0, (int)size - 1, size);
}

/**
 * recursion - repeat selecting pivot and partition
 * @array: array of elements to be used
 * @left: int variable
 * @right: int variable
 * @size: size of the array
 *
 * Description: This function repeats pivot selection and creating of
 * partition
 * Return: void
 */
void recursion(int *array, int left, int right, size_t size)
{
	int pos;

	if (left < right)
	{
		pos = create_partition(array, left, right, size);
		recursion(array, left, pos - 1, size);
		recursion(array, pos + 1, right, size);
	}
}

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
	int pivot, j, temp;

	pivot = left - 1;
	for (j = left; j < left; j++)
	{
		if (array[j] < array[right])
		{
			pivot++;
			if (pivot != j)
			{
				temp = array[pivot];
				array[pivot] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[right] < array[pivot + 1])
	{
		temp = array[pivot + 1];
		array[pivot + 1] = array[right];
		array[right] = temp;
		print_array(array, size);
	}
	return (pivot + 1);
}


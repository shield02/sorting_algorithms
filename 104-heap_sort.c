#include "sort.h"

/**
 * heapify - put elements of array in heap order
 * @array: the array to be used
 * @sud_size: size of the subtree
 * @root: subtree index
 * @size: size of the array
 *
 * Description: This function put elements of the array in
 * in heap order
 * Return: void
 */
void heapify(int *array, size_t sub_size, size_t root, size_t size)
{
	size_t m, l, r;
	int temp;

	m = root;
	l = (2 * root) + 1;
	r = (2 * root) + 2;
	if (l < sub_size && array[l] > array[m])
		m = l;
	if (r < sub_size && array[r] > array[m])
		m = r;
	if (m != root)
	{
		temp = array[root];
		array[root] = array[m];
		array[m] = temp;
		print_array(array, size);
		heapify(array, sub_size, m, size);
	}
}

/**
 * heap_sort - sort an array using hash algo
 * @array: array of elements
 * @size: size of the array
 *
 * Description: This function sorts integers in array in ascending order
 * using heap algo
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int k, temp;

	if (array == NULL || size < 2)
		return;
	for (k = (size / 2) - 1; k >= 0; k--)
		heapify(array, size, k, size);
	for (k = size - 1; k > 0; k--)
	{
		temp = array[k];
		array[k] = array[0];
		array[0] = temp;
		print_array(array, size);
		heapify(array, (size_t)k, 0 , size);
	}
}


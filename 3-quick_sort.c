#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_child(array, size, &array, size);
}

/**
 * quick_sort_child - Recursive helper function for quick sort
 * @array: The sub-array to be sorted
 * @size: Number of elements in the sub-array
 * @first_element: Pointer to the first element of the original array
 * @size_total: Total length of the original array
 */
void quick_sort_child(int *array, size_t size, int **first_element,
			  int size_total)
{
	int *pivot = &array[size - 1];
	size_t j, i = 0;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (j = 0 ; j < size - 1 ; j++)
		if (array[j] <= *pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(*first_element, size_total);
			}
			i++;
		}
	if (i != size - 1)
	{
		temp = array[i];
		array[i] = *pivot;
		*pivot = temp;
		print_array(*first_element, size_total);
	}

	if (size < 2)
		return;
	quick_sort_child(array, i, first_element, size_total);
	quick_sort_child(&array[i + 1], size - i - 1, first_element, size_total);
}

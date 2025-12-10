#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	int saved_value, saved_pos;
	size_t unsorted, pass;

	for (unsorted = 0 ; unsorted < size ; unsorted++)
	{	/* everything at the left of unsorted is already sorted so we start after */
		saved_value = array[unsorted];
		for (pass = unsorted ; pass < size ; pass++)
		{ /* that mean if the actual number if less than the first */
			if (array[pass] < saved_value)
			{ /* save the smallest number value and pos*/
				saved_value = array[pass];
				saved_pos = pass;
			}
		} /* a verifiation to don't replace a number by itself */
		if (saved_value != array[unsorted])
		{ /* swap the far left number by the smallest already find */
			array[saved_pos] = array[unsorted];
			array[unsorted] = saved_value;

			print_array(array, size);
		}
	}
}

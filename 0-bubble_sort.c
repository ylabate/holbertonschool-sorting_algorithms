#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using bubble sort
 * @array: pointer to the array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t pass, iteration;
	int temp = 0;

	for (pass = 0; pass < size; pass++)
		for (iteration = 0; iteration < size; iteration++)
		{
			if (array[iteration + 1] && array[iteration] > array[iteration + 1])
			{
				temp = array[iteration];
				array[iteration] = array[iteration + 1];
				array[iteration + 1] = temp;

				print_array(array, size);
			}
		}
}

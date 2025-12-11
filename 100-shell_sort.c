#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using Shell sort
 * @array: pointer to the array to be sorted
 * @size: number of elements in the array
 *
 * Description: Uses the Knuth sequence for gap values
 */
void shell_sort(int *array, size_t size)
{
	int *current = array;
	size_t gap = 0, progress, temp_progress;
	int temp;

	if (!array || size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;
	if (gap == 0)
		gap = 1;

	while (gap >= 1)
	{
		for (progress = gap; progress < size; progress++)
		{
			temp_progress = progress;
			while (temp_progress >= gap &&
				current[temp_progress] < current[temp_progress - gap])
			{
				temp = current[temp_progress];
				current[temp_progress] = current[temp_progress - gap];
				current[temp_progress - gap] = temp;

				temp_progress -= gap;
			}
		}

		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}

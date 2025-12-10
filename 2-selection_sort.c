#include "sort.h"

void selection_sort(int *array, size_t size)
{
	int temp, temp_pos;
	size_t pass_nbr, pass;

	for (pass_nbr = 0 ; pass_nbr < size ; pass_nbr++)
	{
		temp = array[pass_nbr];
		for (pass = pass_nbr ; pass < size ; pass++)
		{
			if (array[pass] < temp)
			{
				temp = array[pass];
				temp_pos = pass;
			}
		}
		if (temp != array[pass_nbr])
		{
			array[temp_pos] = array[pass_nbr];
			array[pass_nbr] = temp;
			print_array(array, size);
		}
	}
}

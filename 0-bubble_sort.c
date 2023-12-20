#include "sort.h"

/**
 * bubble_sort - This function sorts an array of integers
 * @array: The array to be sorted
 * @size: Size of the array
 * Return: Void
 */

void bubble_sort(int *array, size_t size)
{
	size_t index1, index2;
	int position_swap, flag = 0;

	/*Check for inputs*/
	if (array == NULL || size == 0)
	{
		return;
	}

	/* Counts through the current step in the sort */
	for (index1 = 0; index1 < (size - 1); index1++)
	{
		
		for (index2 = 0; index2 < (size - index1 - 1); index2++)
		{
			if (array[index2] > array[index2 + 1])
			{
				/* Swap their positions */
				position_swap = array[index2];
				array[index2] = array[index2 + 1];
				array[index2 + 1] = position_swap;
				/* Print result */
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}


#include "sort.h"

/**
 * shell_sort - sort an array of integers in ascending order with shell sort
 * @array: the array to be sorted
 * @size: size of the array
 */

void shell_sort(int *array, size_t size)
{
	int gap, i, temp, j, n;

	if (array == NULL || size < 2)
		return;

	n = size;
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		print_array(array, size);
		for (i = gap; i < n; i += 1)
		{
			temp = array[i];
			for (j = i; j >= gap && (array[j - gap] > temp); j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
	}
}

#include "sort.h"

/**
 * swap - swap two numbers
 * @a: first number
 * @b: second number
 */

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * selection_sort - sort an array of integers in ascending order
 * @array: array to sort
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t a, b, temp, l = size - 1;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < l; a++)
	{
		temp = a;

		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[temp])
				temp = b;
		}
		if (temp != a)
		{
			swap(array + a, array + temp);
			print_array(array, size);
		}
	}
}

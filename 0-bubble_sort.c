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
 * bubble_sort - sort array of integers in asscending order with bubble sort
 * @array: the array to sort
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t a, l = size - 1;
	bool swapped = false;

	if (array == NULL || size < 2)
		return;

	while (swapped == false)
	{
		swapped = true;
		for (a = 0; a < l; a++)
		{
			if (array[a] > array[a + 1])
			{
				swap(array + a, array + a + 1);
				print_array(array, size);
				swapped = false;
			}
		}
	}
}

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
 * partition - take last element as pivot, places the pivot element
 * at its correct position
 * @array: array to sort
 * @size: size of the array
 * @left: starting index
 * @right: final index
 * Return: final partition index
 */

int partition(int *array, size_t size, int left, int right)
{
	int temp[64];
	int pivot = array[right];
	int a = (left - 1);
	int b = 0;
	size_t c = 0;
	int skip = 1;

	for (c = 0; c < size; c++)
	{
		temp[c] = array[c];
	}

	for (b = left; b <= right - 1; b++)
	{
		if (array[b] <= pivot)
		{
			a++;
			swap(&array[a], &array[b]);
			for (c = 0; c < size; c++)
			{
				if (temp[c] != array[c])
					skip = 0;
			}
			if (skip == 0)
				print_array(array, size);
		}
	}
	swap(array + a + 1, array + right);
	for (c = 0; c < size; c++)
	{
		if (temp[c] != array[c])
			skip = 0;
	}
	if (skip == 0)
		print_array(array, size);

	return (a + 1);
}

/**
 * lomuto_sort - sort using lomuto sort
 * @array: array to sort
 * @size: size of the array
 * @left: starting index
 * @right: final index
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part = 0;

	if (left < right)
	{
		part = partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}
/**
 * quick_sort - sort an array in ascending order
 * @array: array to be sorted
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

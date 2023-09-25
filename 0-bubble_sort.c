#include "sort.h"

/**
 * bubble_sort - bubble sort algorithm
 * @array: array to be sorted
 * @size: the length of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	bool check;

	check = false;
	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size; j++)
		{
			if (array[j] < array[j - 1])
			{
				check = true;
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
				print_array(array, size);
			}
		}
		if (!check)
			return;
	}
}

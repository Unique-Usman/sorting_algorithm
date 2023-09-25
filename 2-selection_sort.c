#include "sort.h"

/**
 * selection_sort - the selection sort algorithm
 * @array: the array which we want to sort
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, k;
	int smallest, temp;

	for (i = 0; i < size; i++)
	{

		smallest = array[i];
		k = i;

		for (j = i; j < size; j++)
		{
			if (smallest > array[j])
			{
				k = j;
				smallest = array[j];
			}
		}

		temp = array[i];
		array[i] = smallest;
		array[k] = temp;
		if (k != i)
			print_array(array, size);
	}
}

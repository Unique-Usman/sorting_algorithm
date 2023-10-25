#include "sort.h"

/**
 * sort - the recursive sort function
 * @array: the array to be sorted
 * @low: to indicate the start of the partition
 * @high: to indicate the end of the partition
 * @size: the sixe of the array
 */
void sort(int *array, int low, int high, int size)
{
	int pivot, start, end, temp, mid;

	start = low;
	end = high;
	temp = 0;
	mid = start + (end - start) / 2;
	pivot = array[mid];

	if (low >= high)
		return;
	while (start <= end)
	{
		while (array[start] < pivot)
		{
			start++;
		}

		while (array[end] > pivot)
		{
			end--;
		}

		if (start <= end)
		{
			temp = array[start];
			array[start] = array[end];
			array[end] = temp;
			end--;
			start++;
		}
	}

	print_array(array, size);

	sort(array, low, end, size);
	sort(array, start, high, size);
}
/**
 * quick_sort - the quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort(array, 0, size - 1, size);
}

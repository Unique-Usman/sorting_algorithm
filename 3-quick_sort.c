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
	int pivot, start, end, temp;

	pivot = array[high];
	start = low;
	end = high;
	temp = 0;

	if (low >= high)
		return;
	while (start < end)
	{
		while (array[start] < pivot && start < end)
		{
			start++;
		}
		while (array[end] >= pivot && start < end)
		{
			end--;
		}

		if (start < end)
		{
			temp = array[start];
			array[start] = array[end];
			array[end] = temp;
			print_array(array, size);
		}
	}

	if (high != end)
	{
		array[high] = array[start];
		array[start] = pivot;
		print_array(array, size);
	}

	sort(array, low, start - 1, size);
	sort(array, start + 1, high, size);
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

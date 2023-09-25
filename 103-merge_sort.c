#include "sort.h"

void merge(int *nums, int low, int mid, int end)
{
	int *res, o, m, p, k;

	res = malloc(sizeof(int) * (end - low + 1));

	if (res == NULL)
		return;
	k = low;
	m = mid + 1;
	p = 0;

	while (k <= mid && m <= end){
		if (nums[k] < nums[m]){
			int tmp = nums[k];
			nums[k] = nums[p];
			nums[p] = tmp;
		} else{
			res[p] = nums[m];
			m++;
		}
		p++;
	}


	while (k <= mid){
		res[p] = nums[k];
		k++;
		p++;
	}
	while (m <= end){
		res[p] = nums[m];
		m++;
		p++;
	}


	for (o = 0; o < (end - low + 1); o++){
		nums[low + o] = res[o];
	}
	free(res);
}
void mergeSort(int *array, int low, int end)
{
	if (low >= end)
		return;
	int mid = low + (end - low) / 2;
	mergeSort(array, low, mid);
	mergeSort(array, mid + 1, end);
	merge(array, low, mid, end);
}
void merge_sort(int *array, size_t size)
{
	mergeSort(array, 0, size - 1);
}

#pragma once
#include "mergeSort.h"

void hybridSort(int arr[], int start, int end) {
	if(start + 1 == end) return;
	if (start + 32 == end) {
		insertionSort(arr, start, end);
		return;
	}
	int mid = (start + end) / 2;
	hybridSort(arr, start, mid);
	hybridSort(arr, mid, end);
	merge(arr, start, mid, end);
}
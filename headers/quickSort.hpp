#pragma once

void swap(int& x, int& y) {
	int tmp = y;
	y = x;
	x = tmp;
}

int partition(int arr[], int start, int end) {
	int pivot = arr[end - 1];
	int i = start - 1;
	for (int j = start; j < (end - 1); j++) {
		if (arr[j] < pivot) {
			if( (i+1) != j ) swap(arr[i + 1], arr[j]);
			i++;
		}
	}
	swap(arr[end - 1], arr[i + 1]);
	return i + 1;
}

void quickSort(int arr[], int start, int end) {
	if (start >= end - 1) return;
	int mid = partition(arr, start, end);
	quickSort(arr, start, mid);
	quickSort(arr, mid + 1, end);
}
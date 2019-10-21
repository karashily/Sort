#pragma once

void merge(int arr[], int start, int mid, int end) {
	int nLeft = mid - start;
	int nRight = end - mid;
	int* left = new int[nLeft];
	int* right = new int[nRight];
	for (int i = 0; i < nLeft; i++) {
		left[i] = arr[start + i];
	}
	for (int j = 0; j < nRight; j++) {
		right[j] = arr[mid + j];
	}
	int i = 0;
	int j = 0;
	int k = start;
	while (i < nLeft && j < nRight) {
		if (left[i] < right[j]) {
			arr[k] = left[i];
			i++;
		}
		else {
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	if (i == nLeft) {
		while (j < nRight) {
			arr[k] = right[j];
			k++;
			j++;
		}
	}
	else if (j == nRight) {
		while (i < nLeft) {
			arr[k] = left[i];
			k++;
			i++;
		}
	}
	delete[] left;
	delete[] right;
}

void mergeSort(int arr[], int start, int end) {
	if (start + 1 == end) return;
	int mid = (start + end) / 2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid, end);
	merge(arr, start, mid, end);
}
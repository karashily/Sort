#pragma once

void insertionSort(int arr[], int start, int n) {
	for (int i = 1; i < n; i++) {
		int curr = arr[i];
		int j = i - 1;
		while (j >= 0 && curr < arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = curr;
	}
}
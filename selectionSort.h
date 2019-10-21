#pragma once

void selectionSort(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int minIndx = i;
		int min = arr[i];
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < min) {
				minIndx = j;
				min = arr[j];
			}
		}
		int tmp = arr[i];
		arr[i] = min;
		arr[minIndx] = tmp;
	}
}
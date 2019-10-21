#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

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

void swap(int& x, int& y) {
	int tmp = y;
	y = x;
	x = tmp;
}

int partition(int arr[], int start, int end) {
	int pivot = arr[end - 1];
	int i = start - 1;
	for (int j = start; j < (end - start - 1); j++) {
		if (arr[j] < pivot) {
			swap(arr[i + 1], arr[j]);
			i++;
		}
	}
	swap(arr[end - 1], arr[i + 1]);
	return i + 1;
}

void quickSort(int arr[], int start, int end) {
	if (start == end) return;
	int mid = partition(arr, start, end);
	quickSort(arr, start, mid);
	quickSort(arr, mid + 1, end);
}

void hybirdSort(int arr[], int start, int end) {
	if (start >= end - 64) {
		insertionSort(arr, start, end);
		return;
	}
	int mid = (start + end) / 2;
	hybirdSort(arr, start, mid);
	hybirdSort(arr, mid, end);
	merge(arr, start, mid, end);
}


int main(int argc, char* argv[]) {
	// TODO: read arguments from terminal and use it to read the input, 
	// write the output and output the time taken by the algorithm.
	
	

	return 0;
}
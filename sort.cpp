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


int main(int argc, char* argv[]) {

	string sortType = argv[1];
	string inputFile = argv[2];
	string outputFile = argv[3];
	string TimeFile = argv[4];

	ifstream fin;
	fin.open(inputFile);

	vector<int> input;
	int x;
	while (fin >> x) input.push_back(x);

	ofstream fout;

	auto start = high_resolution_clock::now();
		
	if (sortType == "selection") {
		selectionSort(input.data(), input.size());	
	}
	else if (sortType == "insertion") {
		insertionSort(input.data(), 0, input.size());
	}
	else if (sortType == "merge") {
		mergeSort(input.data(), 0, input.size());
	}
	else if (sortType == "quick") {
		quickSort(input.data(), 0, input.size());
	}
	else if (sortType == "hybrid") {
		hybridSort(input.data(), 0, input.size());
	}
	else cout << sortType << " sorting algorithm isn't supported yet.\n"
		<< "supported algorithms are:\nselection, insertion, merge, quick " 
		<< "and hybrid\n";

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
		
	fout.open(TimeFile, std::ofstream::app);
	fout << sortType << ": " << input.size() << ": " << duration.count()/1000 
		<< " ms" << endl;
	fout.close();

	fout.open(outputFile);
	for (int i = 0; i < input.size(); i++) fout << input[i] << endl;
	fout.close();

	return 0;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

#include "headers/selectionSort.hpp"
#include "headers/insertionSort.hpp"
#include "headers/mergeSort.hpp"
#include "headers/quickSort.hpp"
#include "headers/hybridSort.hpp"

int main(int argc, char* argv[]) {

	string sortType = argv[1];
	string inputFile = argv[2];
	string outputFile = argv[3];
	string timeFile;

	bool calcTime=false;

	if(argc == 5) {
		calcTime = true; 
		timeFile = argv[4];
	}

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
	else {
		cout << sortType << " sorting algorithm isn't supported yet.\n"
		<< "supported algorithms are:\nselection, insertion, merge, quick " 
		<< "and hybrid\n";
		return 0;
	}

	if(calcTime) {
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		
		fout.open(timeFile, std::ofstream::app);
		fout << sortType << ": " << input.size() << ": " << duration.count()/1000 
			<< " ms" << endl;
		fout.close();
	}

	fout.open(outputFile);
	for (int i = 0; i < input.size(); i++) fout << input[i] << endl;
	fout.close();

	return 0;
}
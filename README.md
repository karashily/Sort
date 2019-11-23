# Sort
Different sorting algorithms (insertion, selection, merge, quick and hybrid) implemented in C++.
Input is read from file and output is written to a file, which names is given from the terminal.

(optional) Time is calculated for the operation and is appended to a file, which name is given from the terminal too :v

### Hybrid Sort 
a mix between insertion and merge sorts to exploit the strengths of both; 
insertion sort works best with ordered and almost-ordered lists,
while merge sort works best in the rest of the cases.

## Prerequisites

* g++
```sh
apt-get install g++
```

## Installation

1. Build the file using the makefile by simply opening the shell and typing:
```sh
make
```
  or Build using g++ by typing:
```sh
g++ sort.cpp -o sort.out
```
2. Run the program
```sh
./sort sort_type input_data.txt output_file.txt (time_calc_file.txt)
```
sort_type can be: 
* insertion 
* selection 
* merge 
* quick 
* hybrid

/*
Grant Stoebner
MS549 - Selection Sort
Assignment #3
Part 1
*/

#include <iostream>
#include <chrono>
#include <algorithm>
#include <iomanip>  
using namespace std;

// Function for Selection sort 
void selectionSort(int nums[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray 
	for (i = 0; i < n - 1; i++) {

		// Find the minimum element in unsorted array 
		min_idx = i;
		for (j = i + 1; j < n; j++) {
			if (nums[j] < nums[min_idx])
				min_idx = j;
		}

		// Swap the found minimum element with the first element 
		if (min_idx != i)
			swap(nums[min_idx], nums[i]);
	}
}

// Function to print an array 
void printArray(int nums[], int size)
{
	int i;
	for (i = 0; i < size; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
}

// Driver program 
int main()
{

	int nums[1000];

	for (int i = 0; i < 1000; i++) {
		nums[i] = rand() % 1000;
	}

	int n = sizeof(nums) / sizeof(nums[0]);

	
	// Function Call 
	auto start = chrono::high_resolution_clock::now();
	selectionSort(nums, n);
	auto end = chrono::high_resolution_clock::now();
	cout << "Sorted array: \n";
	printArray(nums, n);

	double elapsedTime = chrono::duration<double, micro>(end - start).count() / 1000.0;
	cout << fixed << setprecision(3);
	cout << "Selection Sort Time (MS)= " << elapsedTime << " ms" << endl;

	return 0;
}


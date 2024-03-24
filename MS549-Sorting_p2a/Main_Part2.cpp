/*
Grant Stoebner
MS549 - Selection Sort
Assignment #3
Part 2
*/
#include <iostream>
#include <chrono>
#include <algorithm>
#include <iomanip>  
using namespace std;

void heapify(int nums[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && nums[left] > nums[largest])
        largest = left;

    if (right < n && nums[right] > nums[largest])
        largest = right;

    if (largest != i) {
        swap(nums[i], nums[largest]);
        heapify(nums, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to print an array 
void printArray(int nums[], int size) {
    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    int nums[100000];

    for (int i = 0; i < 100000; i++) {
        nums[i] = rand() % 100000;
    }

    int n = sizeof(nums) / sizeof(nums[0]);


    // Function Call w/ timing
    auto start = chrono::high_resolution_clock::now();
    heapSort(nums, n);
    auto end = chrono::high_resolution_clock::now();
    cout << "Sorted array is \n";
    printArray(nums, n);

    double elapsedTime = chrono::duration<double, micro>(end - start).count() / 1000.0;
    cout << fixed << setprecision(3);
    cout << "Heap Sort Time (MS)= " << elapsedTime << " ms" << endl;

    return 0;
}

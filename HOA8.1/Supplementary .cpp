#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "HybridSorting.h"

int main() {
    srand(time(0));
    std::vector<int> baseArr(10);
    for (int& num : baseArr) num = rand() % 100 + 1;

    std::vector<int> arr = baseArr;

    std::cout << "Original Array: ";
    printArray(arr);

    int pivotIndex = partition(arr, 0, arr.size() - 1);
    std::cout << "\nAfter Partition (Pivot is " << arr[pivotIndex] << "):\n";
    printArray(arr);

    selectionSort(arr, 0, pivotIndex - 1);
    selectionSort(arr, pivotIndex + 1, arr.size() - 1);
    std::cout << "\nFinal Sorted Array: ";
    printArray(arr);

    return 0;
}
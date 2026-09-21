#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "SortingAlgo_P2.h"

void printArray(const std::vector<int>& arr) {
    for (int val : arr) std::cout << val << " ";
    std::cout << "\n";
}

int main() {
    srand(time(0));
    std::vector<int> baseArr(10);
    for (int& num : baseArr) num = rand() % 100 + 1;

    // Array Generation
    std::cout << "array of values\n";
    std::cout << "generated: ";
    printArray(baseArr);

    // Shell Sort
    std::vector<int> arr = baseArr;
    std::cout << "\nshell sort\n";
    std::cout << "unsorted: ";
    printArray(arr);
    shellSort(arr);
    std::cout << "sorted: ";
    printArray(arr);

    // Merge Sort
    arr = baseArr;
    std::cout << "\nmerge sort\n";
    std::cout << "unsorted: ";
    printArray(arr);
    mergeSort(arr, 0, arr.size() - 1);
    std::cout << "sorted: ";
    printArray(arr);

    // Quick Sort
    arr = baseArr;
    std::cout << "\nquick sort\n";
    std::cout << "unsorted: ";
    printArray(arr);
    quickSort(arr, 0, arr.size() - 1);
    std::cout << "sorted: ";
    printArray(arr);

    return 0;
}
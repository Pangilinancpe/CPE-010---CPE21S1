#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "SortingAlgo.h"

std::vector<int> generateRandomValues() {
    srand(time(0));
    std::vector<int> values(100);
    for (int& num : values) num = rand() % 100 + 1;
    return values;
}
void displayArr(const int arr[], int size) {
    for (int i = 0; i < size; i++) { 
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    auto numbers = generateRandomValues();
    const int maxSize = 100;

    int originalArr[maxSize];
    int workArr[maxSize];

    // Copy generated vector into raw array
    for (int i = 0; i < maxSize; i++) {
        originalArr[i] = numbers[i];
    }

    std::cout << "Original Array: \n";
    displayArr(originalArr, maxSize);

    // 1. Bubble Sort Technique
    std::copy(originalArr, originalArr + maxSize, workArr);
    std::cout << "\nBubble Sort Technique:\n";
    bubbleSort(workArr, maxSize);
    displayArr(workArr, maxSize);

    // 2. Selection Sort Algorithm
    std::copy(originalArr, originalArr + maxSize, workArr);
    std::cout << "\nSelection Sort Algorithm:\n";
    selectionSort(workArr, maxSize);
    displayArr(workArr, maxSize);

    // 3. Insertion Sort Algorithm
    std::copy(originalArr, originalArr + maxSize, workArr);
    std::cout << "\nInsertion Sort Algorithm:\n";
    insertionSort(workArr, maxSize);
    displayArr(workArr, maxSize);

    return 0;
}
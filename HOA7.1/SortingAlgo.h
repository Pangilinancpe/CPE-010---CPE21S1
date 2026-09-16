#ifndef HOA7_1_SORTINGALGO_H
#define HOA7_1_SORTINGALGO_H

#include <utility>

template <typename T>
int routine_smallest(const T A[], int max_size, int k);

template <typename T>
void bubbleSort(T arr[], int arrsize) {
    for (int i = 0; i < arrsize - 1; i++) {
        for (int j = 0; j < arrsize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
int routine_smallest(const T A[], int max_size, int k) {
    int position = k;
    T smallestElement = A[k];

    for (int j = k + 1; j < max_size; j++) {
        if (A[j] < smallestElement) {
            smallestElement = A[j];
            position = j;
        }
    }
    return position;
}

template <typename T>
void selectionSort(T arr[], int arrSize) {
    for (int i = 0; i < arrSize - 1; i++) {
        int pos = routine_smallest(arr, arrSize, i);
        std::swap(arr[i], arr[pos]);
    }
}

template <typename T>
void insertionSort(T arr[], int arrsize) {
    int k = 1, j;
    T temp;
    while (k < arrsize) {
        temp = arr[k];
        j = k - 1;
        while (j >= 0 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
        k++;
    }
}

#endif // HOA7_1_SORTINGALGO_H
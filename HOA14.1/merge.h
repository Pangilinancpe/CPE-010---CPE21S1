#ifndef HOA14_1_MERGE_H
#define HOA14_1_MERGE_H

#include <vector>
#include <chrono>

template <typename T>
void mergeSort(std::vector<T>& a, std::vector<T>& temp, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(a, temp, left, mid);
    mergeSort(a, temp, mid + 1, right);

    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        temp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];

    for (k = left; k <= right; k++) a[k] = temp[k];
}

template <typename T>
double timeSort(const std::vector<T>& data, int reps) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int r = 0; r < reps; r++) {
        std::vector<T> copy = data;
        std::vector<T> temp(data.size());
        mergeSort(copy, temp, 0, static_cast<int>(copy.size()) - 1);
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::micro>(end - start).count() / reps;
}

#endif // HOA14_1_MERGE_H
#ifndef HOA14_1_QUICK_H
#define HOA14_1_QUICK_H

#include <vector>
#include <chrono>

template <typename T>
int partitionLast(std::vector<T>& a, int low, int high) {
    T pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i + 1], a[high]);
    return i + 1;
}

template <typename T>
void quickSort(std::vector<T>& a, int low, int high) {
    if (low >= high) return;
    int p = partitionLast(a, low, high);
    quickSort(a, low, p - 1);
    quickSort(a, p + 1, high);
}

template <typename T>
void makeBestCase(std::vector<T>& a, int low, int high) {
    if (low >= high) return;
    int mid = low + (high - low) / 2;
    makeBestCase(a, low, mid - 1);
    makeBestCase(a, mid + 1, high);
    std::swap(a[mid], a[high]);
}

template <typename T>
double timeSort(const std::vector<T>& data, int reps) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int r = 0; r < reps; r++) {
        std::vector<T> copy = data;
        quickSort(copy, 0, static_cast<int>(copy.size()) - 1);
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::micro>(end - start).count() / reps;
}

#endif // HOA14_1_QUICK_H
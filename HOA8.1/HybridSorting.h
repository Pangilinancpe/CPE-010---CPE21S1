#ifndef HOA8_1_HYBRIDSORTING_H
#define HOA8_1_HYBRIDSORTING_H

void printArray(const std::vector<int>& arr) {
    for (int val : arr) std::cout << val << " ";
    std::cout << "\n";
}
// Selection Sort
void selectionSort(std::vector<int>& arr, int start, int end) {
    for (int i = start; i < end; i++) {
        int minIdx = i;
        for (int j = i + 1; j <= end; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        std::swap(arr[i], arr[minIdx]);
    }
}
// Quick Sort
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}


#endif //HOA8_1_HYBRIDSORTING_H

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < L.size()) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < R.size()) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right, int threads) {
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;

    if (threads > 1) {
        thread t(mergeSort, ref(arr), left, mid, threads / 2);
        mergeSort(arr, mid + 1, right, threads / 2);
        t.join();
    } else {
        mergeSort(arr, left, mid, 1);
        mergeSort(arr, mid + 1, right, 1);
    }

    merge(arr, left, mid, right);
}

double testSort(vector<int> arr, int threads) {
    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, arr.size() - 1, threads);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> time = end - start;
    return time.count();
}

int main() {
    int n = 100000;
    vector<int> arr(n);

    srand(42);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000;
    }

    cout << "Array size: " << n << endl;

    double singleTime = testSort(arr, 1);
    cout << "1 thread: " << singleTime << " ms" << endl;

    int threadCounts[] = {2, 4, 8};

    for (int i = 0; i < 3; i++) {
        double multiTime = testSort(arr, threadCounts[i]);
        cout << threadCounts[i] << " threads: " << multiTime << " ms" << endl;
    }

    return 0;
}
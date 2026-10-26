#include <iostream>
#include <iomanip>
#include <chrono>

template <typename T>
int linearSearch(const T data[], int arrSize, T dataFind){
    int i = 0;
    while(i < arrSize){
        if(dataFind == data[i]){
            return i;
        }
        i++;
    }
    return -1;
}

template <typename T>
int binarySearch(const T data[], int arrSize, T dataFind){
    int low = 0;
    int up = arrSize - 1;
    while(low <= up){
        int mid = low + (up - low) / 2;
        if(dataFind == data[mid]){
            return mid;
        }
        else if(dataFind < data[mid]){
            up = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

int main(){
    const int sizes[] = {1000, 10000, 100000};
    const int runs = 1000;
    volatile int sink = 0;

    std::cout << std::fixed << std::setprecision(6);
    std::cout << std::left << std::setw(12) << "N" << std::setw(34) << "Binary Search Worst-Case (ms)" << std::setw(34) << "Linear Search Worst-Case (ms)" << "\n";

    for(int s = 0; s < 3; s++){
        int n = sizes[s];
        int* data = new int[n];
        for(int i = 0; i < n; i++){
            data[i] = i * 2;
        }
        int target = -1;

        auto b0 = std::chrono::high_resolution_clock::now();
        for(int r = 0; r < runs; r++){
            sink = binarySearch(data, n, target);
        }
        auto b1 = std::chrono::high_resolution_clock::now();

        auto l0 = std::chrono::high_resolution_clock::now();
        for(int r = 0; r < runs; r++){
            sink = linearSearch(data, n, target);
        }
        auto l1 = std::chrono::high_resolution_clock::now();

        double binMs = std::chrono::duration<double, std::milli>(b1 - b0).count() / runs;
        double linMs = std::chrono::duration<double, std::milli>(l1 - l0).count() / runs;

        std::cout << std::left << std::setw(12) << n << std::setw(34) << binMs << std::setw(34) << linMs << "\n";
        delete[] data;
    }
    return 0;
}
#include <iostream>
#include <chrono>
#include <numeric>
#include "problem1.h"

int main() {
    std::cout << "Worst case (all elements unique)\n";
    for (int n : {1000, 2000, 4000, 8000, 16000}) {
        std::vector<int> A(n);
        std::iota(A.begin(), A.end(), 0);

        comparisons = 0;
        auto begin = std::chrono::steady_clock::now();
        bool result = unique_elements(A);
        auto end = std::chrono::steady_clock::now();

        auto us = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
        std::cout << "n = " << n
                  << " | unique = " << result
                  << " | comparisons = " << comparisons
                  << " | n(n-1)/2 = " << (long long)n * (n - 1) / 2
                  << " | time = " << us << " us\n";
    }

    std::cout << "\nBest case (first two elements equal)\n";
    for (int n : {1000, 16000}) {
        std::vector<int> A(n);
        std::iota(A.begin(), A.end(), 0);
        A[1] = A[0];

        comparisons = 0;
        unique_elements(A);
        std::cout << "n = " << n << " | comparisons = " << comparisons << "\n";
    }
    return 0;
}
#include <iostream>
#include <numeric>
#include "quick.h"

int main() {
    int sizes[] = {100, 1000, 10000};
    for (int n : sizes) {
        std::vector<int> worst(n);
        std::iota(worst.begin(), worst.end(), 0);      // sorted -> worst case
        std::vector<int> best = worst;
        makeBestCase(best, 0, n - 1);                  // balanced splits -> best case
        int reps = (n == 100) ? 2000 : (n == 1000 ? 50 : 3);

        std::cout << "n = " << n << std::endl;
        std::cout << "  Best case : " << timeSort(best, reps)  << " us" << std::endl;
        std::cout << "  Worst case: " << timeSort(worst, reps) << " us" << std::endl << std::endl;
    }
    return 0;
}

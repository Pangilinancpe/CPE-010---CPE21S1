#include <iostream>
#include "merge.h"



int main() {
    int sizes[] = {100, 1000, 10000};
    for (int n : sizes) {
        std::vector<int> best(n), worst(n);
        for (int i = 0; i < n; i++) {
            best[i] = i;
            worst[i] = n - 1 - i;
        }

        int reps = (n == 100) ? 2000 : (n == 1000 ? 50 : 3);

        std::cout << "n = " << n << std::endl;
        std::cout << "  Best case : " << timeSort(best, reps) << " us" << std::endl;
        std::cout << "  Worst case: " << timeSort(worst, reps) << " us" << std::endl << std::endl;
    }
    return 0;
}
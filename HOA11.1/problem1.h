#ifndef HOA11_1_PROBLEM1_H
#define HOA11_1_PROBLEM1_H

#include <vector>

// Counts how many times A[i] is compared with A[j]
inline long long comparisons = 0;

// Returns true if all elements in A are different
inline bool unique_elements(const std::vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (A[i] == A[j]) return false;
        }
    }
    return true;
}

#endif //HOA11_1_PROBLEM1_H

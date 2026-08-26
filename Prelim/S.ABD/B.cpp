#include <iostream>
#include <string>
#include "B.h"

int main() {
    std::string testCases[] = {"1 2 3 2 1", "12321", "eve", "kayak", "radar"};

    std::cout << "--- SET B: SYMMETRY CHECKER RESULTS ---" << std::endl;
    for (const auto& test : testCases) {
        std::cout << "Input: \"" << test << "\""
                  << " | Is Symmetric? " << (isSymmetric(test) ? "YES" : "NO")
                  << std::endl;
    }
    return 0;
}

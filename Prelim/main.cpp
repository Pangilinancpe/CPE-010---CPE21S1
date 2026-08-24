#include <iostream>
#include <vector>
#include <iomanip>
#include "Stack-Array.h"

int main() {
    // Inputs from the problem table
    std::vector<std::string> testCases = {
        "10201",
        "1003003001",
        "88",
        "0",
        "202"
    };

    std::cout << std::left
              << std::setw(15) << "Input"
              << std::setw(20) << "Output (Console)"
              << std::setw(15) << "Remark" << "\n";
    std::cout << std::string(50, '-') << "\n";

    for (const std::string& test : testCases) {
        bool result = isPalindrome(test);
        std::cout << std::left
                  << std::setw(15) << test
                  << std::setw(20) << (result ? "Yes" : "No")
                  << std::setw(15) << (result ? "Palindrome" : "Not Palindrome") << "\n";
    }

    std::cout << std::string(50, '-') << "\n";

    return 0;
}

#this section deines the exception of the code 
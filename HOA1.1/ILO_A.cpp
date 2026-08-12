// 1. HEADER FILE DECLARATION SECTION
#include <iostream>

// 2. GLOBAL DECLARATION SECTION
int sumOfTwoNumbers(int n1, int n2);
void DIFFERENCE(int n1, int n2);
bool logical(bool b1, bool b2);


// 3. CLASS DECLARATION AND METHOD DEFINITION SECTION
// (Left empty since this specific program is procedural and doesn't utilize OOP classes)

// 4. MAIN FUNCTION
int main() {
    std::cout << sumOfTwoNumbers(3, 4) << std::endl;
    DIFFERENCE(3, 4);
    logical(true, false);
    return 0;
}
// 5. METHOD DEFINITION
int sumOfTwoNumbers(int n1, int n2) {
    int sum = n1 + n2;
    return sum;
}

void DIFFERENCE(int n1, int n2) {
    if (n1 > n2) {
        std::cout << n1 << " is greater than " << n2 << std::endl;
    }
    else if (n1 < n2) {
        std::cout << n1 << " is less than " << n2 << std::endl;
    }
}

bool logical(bool b1, bool b2) {
    std::cout << std::boolalpha;

    std::cout << "AND: " << (b1 && b2) << std::endl;
    std::cout << "OR: " << (b1 || b2) << std::endl;
    std::cout << "NOT b1: " << (!b1) << std::endl;
    std::cout << "NOT b2: " << (!b2) << std::endl;
    return true;
}
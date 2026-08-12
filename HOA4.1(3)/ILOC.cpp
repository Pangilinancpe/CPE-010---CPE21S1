#include <iostream>
#include "ILOC.h"

bool isPair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '[' && close == ']') return true;
    if (open == '{' && close == '}') return true;
    return false;
}

bool isBalanced(const std::string& expr) {
    while (!isEmpty<char>()) {
        pop<char>();
    }

    for (char ch : expr) {
        if (ch == '(' || ch == '[' || ch == '{') {
            push<char>(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (isEmpty<char>()) {
                return false;
            }
            char topChar = pop<char>();
            if (!isPair(topChar, ch)) {
                return false;
            }
        }
    }

    bool result = isEmpty<char>();
    while (!isEmpty<char>()) {
        pop<char>();
    }

    return result;
}

int main() {
    std::string expr[] = {
        "(A+B)+(C-D)",
        "((A+B)+(C-D)",
        "((A+B)+[C-D])",
        "((A+B)+(C-D)}"
    };
    for (const std::string& expr : expr) {
        bool isValid = isBalanced(expr);

        std::cout << "Expression: " << expr << "\n";
        std::cout << "Is it Valid: " << (isValid? "Yes" : "No") << "\n\n";
    }
    return 0;
}



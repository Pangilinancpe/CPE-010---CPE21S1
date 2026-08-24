#include <iostream>
#include <string>
#include <cctype>
#include "B.h"

ArrayStack::ArrayStack(int size) {
    capacity = size;
    arr = new int[capacity];
    top = -1;
}

ArrayStack::~ArrayStack() {
    delete[] arr;
}

void ArrayStack::push(int val) {
    if (top < capacity - 1) arr[++top] = val;
}

int ArrayStack::pop() {
    return (top >= 0) ? arr[top--] : 0;
}

int ArrayStack::peek() const {
    return (top >= 0) ? arr[top] : 0;
}

bool ArrayStack::isEmpty() const {
    return top == -1;
}

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int evaluateInfix(const std::string& infix) {
    ArrayStack opStack(infix.length());
    std::string postfix = "";

    // Step 1: Infix to Postfix
    for (char ch : infix) {
        if (isdigit(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            opStack.push(ch);
        } else if (ch == ')') {
            while (!opStack.isEmpty() && opStack.peek() != '(') {
                postfix += (char)opStack.pop();
            }
            opStack.pop(); // Remove '('
        } else {
            while (!opStack.isEmpty() && getPrecedence((char)opStack.peek()) >= getPrecedence(ch)) {
                postfix += (char)opStack.pop();
            }
            opStack.push(ch);
        }
    }
    while (!opStack.isEmpty()) postfix += (char)opStack.pop();

    // Step 2: Evaluate Postfix
    ArrayStack evalStack(postfix.length());
    for (char ch : postfix) {
        if (isdigit(ch)) {
            evalStack.push(ch - '0');
        } else {
            int val2 = evalStack.pop();
            int val1 = evalStack.pop();
            switch (ch) {
                case '+': evalStack.push(val1 + val2); break;
                case '-': evalStack.push(val1 - val2); break;
                case '*': evalStack.push(val1 * val2); break;
                case '/': evalStack.push(val1 / val2); break;
            }
        }
    }
    return evalStack.pop();
}

int main() {
    std::string expr = "3+(2*4)-5";
    std::cout << "--- INFIX EVALUATOR ---" << std::endl;
    std::cout << "Infix Expression: " << expr << std::endl;
    std::cout << "Calculated Output: " << evaluateInfix(expr) << std::endl;
    return 0;
}
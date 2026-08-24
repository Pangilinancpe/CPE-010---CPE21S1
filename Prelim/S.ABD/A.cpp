#include <iostream>
#include <string>
#include "A.h"

LinkedStack::LinkedStack() : top(nullptr) {}

LinkedStack::~LinkedStack() {
    while (top) {
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }
}

void LinkedStack::push(char val) {
    StackNode* newNode = new StackNode(val);
    newNode->next = top;
    top = newNode;
}

char LinkedStack::pop() {
    if (!top) return '\0';
    StackNode* temp = top;
    char val = temp->data;
    top = top->next;
    delete temp;
    return val;
}

bool LinkedStack::isEmpty() const {
    return top == nullptr;
}

bool isBalanced(const std::string& expr) {
    LinkedStack stack;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.isEmpty()) return false;
            char topChar = stack.pop();
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) return false;
        }
    }
    return stack.isEmpty();
}

int main() {
    std::string testCases[] = {"{[()]}", "{[(])}", "((()))", "(()"};

    std::cout << "--- results ---" << std::endl;
    for (const auto& test : testCases) {
        std::cout << "Expression: " << test
                  << " | Balanced: " << (isBalanced(test) ? "YES" : "NO")
                  << std::endl;
    }
    return 0;
}
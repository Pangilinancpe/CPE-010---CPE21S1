#ifndef S_ABD_A_H
#define S_ABD_A_H

#include <string>

struct StackNode {
    char data;
    StackNode* next;
    StackNode(char val) : data(val), next(nullptr) {}
};

// --- Linked List-based Stack ---
class LinkedStack {
private:
    StackNode* top;

public:
    LinkedStack();
    ~LinkedStack();
    void push(char val);
    char pop();
    bool isEmpty() const;
};

bool isBalanced(const std::string& expr);

#endif //S_ABD_A_H

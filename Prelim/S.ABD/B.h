#ifndef S_ABD_B_H
#define S_ABD_B_H

// --- Array-based Stack ---
class ArrayStack {
private:
    int* arr;
    int top;
    int capacity;

public:
    ArrayStack(int size = 100);
    ~ArrayStack();
    void push(int val);
    int pop();
    int peek() const;
    bool isEmpty() const;
};

int evaluateInfix(const std::string& infix);

#endif //S_ABD_B_H

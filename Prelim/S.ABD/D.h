#ifndef S_ABD_D_H
#define S_ABD_D_H

#include <string>

struct Node {
    std::string state;
    Node* next;
    Node(std::string val) : state(val), next(nullptr) {}
};

// --- Linked List-based Stack (Undo) ---
class LinkedStack {
private:
    Node* top;

public:
    LinkedStack();
    ~LinkedStack();
    void push(std::string val);
    std::string pop();
    bool isEmpty() const;
};

// --- Array-based Stack (Redo) ---
class ArrayStack {
private:
    std::string* arr;
    int top;
    int capacity;

public:
    ArrayStack(int size = 100);
    ~ArrayStack();
    void push(std::string val);
    std::string pop();
    bool isEmpty() const;
    void clear();
};

class TextEditor {
private:
    std::string currentText;
    LinkedStack undoStack;
    ArrayStack redoStack;

public:
    TextEditor();
    void type(const std::string& text);
    void undo();
    void redo();
    void display() const;
};

#endif //S_ABD_D_H

#include <iostream>
#include <string>
#include "D.h"

// LinkedStack
LinkedStack::LinkedStack() : top(nullptr) {}
LinkedStack::~LinkedStack() {
    while (top) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}
void LinkedStack::push(std::string val) {
    Node* newNode = new Node(val);
    newNode->next = top;
    top = newNode;
}
std::string LinkedStack::pop() {
    if (!top) return "";
    Node* temp = top;
    std::string val = temp->state;
    top = top->next;
    delete temp;
    return val;
}
bool LinkedStack::isEmpty() const { return top == nullptr; }

// ArrayStack
ArrayStack::ArrayStack(int size) {
    capacity = size;
    arr = new std::string[capacity];
    top = -1;
}
ArrayStack::~ArrayStack() { delete[] arr; }
void ArrayStack::push(std::string val) { if (top < capacity - 1) arr[++top] = val; }
std::string ArrayStack::pop() { return (top >= 0) ? arr[top--] : ""; }
bool ArrayStack::isEmpty() const { return top == -1; }
void ArrayStack::clear() { top = -1; }

// TextEditor
TextEditor::TextEditor() : currentText("") {}

void TextEditor::type(const std::string& text) {
    undoStack.push(currentText);
    currentText += text;
    redoStack.clear();
}

void TextEditor::undo() {
    if (!undoStack.isEmpty()) {
        redoStack.push(currentText);
        currentText = undoStack.pop();
    }
}

void TextEditor::redo() {
    if (!redoStack.isEmpty()) {
        undoStack.push(currentText);
        currentText = redoStack.pop();
    }
}

void TextEditor::display() const {
    std::cout << "Editor Content: \"" << currentText << "\"" << std::endl;
}

int main() {
    TextEditor editor;
    std::cout << "--- SET D: UNDO/REDO SIMULATION ---" << std::endl;
    editor.type("Hello ");
    editor.type("Data ");
    editor.type("Structures!");
    editor.display();

    std::cout << "Action: Undo" << std::endl;
    editor.undo();
    editor.display();

    std::cout << "Action: Redo" << std::endl;
    editor.redo();
    editor.display();

    return 0;
}
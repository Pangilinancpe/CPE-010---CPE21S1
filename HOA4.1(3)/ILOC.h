#ifndef HOA4_1_STACKLIST_H
#define HOA4_1_STACKLIST_H
#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;
};

//global pointer for the top of the stack
template <typename T>
Node<T> *head = nullptr;

//operations for the stack

//push
template <typename T>
void push(T newData) {
    //create a new node and assign the newData
    Node<T> *newNode = new Node<T>;
    newNode->data = newData;

    //new node points to current top, then becomes the new top
    newNode->next = head<T>;
    head<T> = newNode;
}

//pop
template <typename T>
T pop() {
    //check if the stack is empty
    if (head<T> == nullptr) {
        std::cout << "Stack is empty" << std::endl;
        return T();
    }
    // save the current top node
    Node<T>* temp = head<T>;

    // store its data
    T tempVAL = temp->data;

    // move the head to the next node
    head<T> = head<T>->next;

    // free the removed node
    delete temp;

    //return the removed value
    return tempVAL;
}
//isEmpty
template <typename T>
bool isEmpty() {
    return head<T> == nullptr;
}

//top
template <typename T>
void Top() {
    // error catching:
    if (isEmpty<T>()) {
        std::cout << "Stack underflow" << std::endl;
        return;
    }

    // display the Top node
    std::cout << "Top of stack: " << head<T>-> data << std::endl;
}

template <typename T>
void print() {
    if (head<T> == nullptr) {
        std::cout << "Stack Underflow\n";
        return;
    }
    Node<T>* temp = head<T>;
    while (temp != nullptr) {
        std::cout << temp->data << ", ";
        temp = temp->next;
    }
    std::cout << "\n";
}

#endif //HOA4_1_STACKLIST_H

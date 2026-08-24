#ifndef PRELIM_STACK_ARRAY_H
#define PRELIM_STACK_ARRAY_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

// =================================================================
// 1. Array-Based Stack Implementation
// =================================================================
template <typename T>
class ArrayStack {
private:
    std::vector<T> data;

public:
    void push(T val) {
        data.push_back(val);
    }

    void pop() {
        if (!isEmpty()) {
            data.pop_back();
        }
    }

    T top() const {
        if (!isEmpty()) {
            return data.back();
        }
        throw std::runtime_error("Stack is empty");
    }

    bool isEmpty() const {
        return data.empty();
    }
};

// =================================================================
// 2. Linked List-Based Queue Implementation
// =================================================================
template <typename T>
class LinkedListQueue {
private:
    struct Node {
        T val;
        Node* next;
        Node(T value) : val(value), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;

public:
    LinkedListQueue() : frontNode(nullptr), rearNode(nullptr) {}

    ~LinkedListQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(T val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            Node* temp = frontNode;
            frontNode = frontNode->next;
            delete temp;
            if (frontNode == nullptr) {
                rearNode = nullptr;
            }
        }
    }

    T front() const {
        if (!isEmpty()) {
            return frontNode->val;
        }
        throw std::runtime_error("Queue is empty");
    }

    bool isEmpty() const {
        return frontNode == nullptr;
    }
};

// =================================================================
// 3. Palindrome Checker Function
// =================================================================
inline bool isPalindrome(const std::string& input) {
    ArrayStack<char> stack;
    LinkedListQueue<char> queue;

    // Push into stack (LIFO) and enqueue into queue (FIFO)
    for (char ch : input) {
        stack.push(ch);
        queue.enqueue(ch);
    }

    // Compare characters popped from Stack and dequeued from Queue
    while (!stack.isEmpty() && !queue.isEmpty()) {
        if (stack.top() != queue.front()) {
            return false; // Mismatch found
        }
        stack.pop();
        queue.dequeue();
    }

    return true;
}

#endif //PRELIM_STACK_ARRAY_H

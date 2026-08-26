#ifndef S_ABD_B_H
#define S_ABD_B_H

#include <string>
#include <cctype>

// --- Linked List-based Doubly Node ---
struct DequeNode {
    char data;
    DequeNode* next;
    DequeNode* prev;
    DequeNode(char val) : data(val), next(nullptr), prev(nullptr) {}
};

// --- Linked List-based Deque (Double-Ended Queue) ---
class LinkedDeque {
private:
    DequeNode* front;
    DequeNode* rear;

public:
    LinkedDeque() : front(nullptr), rear(nullptr) {}

    ~LinkedDeque() {
        while (front) {
            DequeNode* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void insertRear(char ch) {
        DequeNode* newNode = new DequeNode(ch);
        if (!rear) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }

    char removeFront() {
        if (!front) return '\0';
        DequeNode* temp = front;
        char val = temp->data;
        front = front->next;
        if (front) front->prev = nullptr;
        else rear = nullptr;
        delete temp;
        return val;
    }

    char removeRear() {
        if (!rear) return '\0';
        DequeNode* temp = rear;
        char val = temp->data;
        rear = rear->prev;
        if (rear) rear->next = nullptr;
        else front = nullptr;
        delete temp;
        return val;
    }

    bool isEmpty() const {
        return front == nullptr;
    }
};


// --- Symmetry Checking Function ---
inline bool isSymmetric(const std::string& input) {
    LinkedDeque deque;
    for (char ch : input) {
        if (!isspace(ch)) deque.insertRear(ch);
    }
    while (!deque.isEmpty()) {
        char first = deque.removeFront();
        if (deque.isEmpty()) break; // Middle character for odd lengths
        char last = deque.removeRear();
        if (first != last) return false;
    }
    return true;
}

#endif //S_ABD_B_H

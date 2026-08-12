#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H
#include <iostream>

template<typename T>
class DoubleList {
public:
    T data;
    DoubleList<T>* next = nullptr;
    DoubleList<T>* prev = nullptr;
};

template<typename T>
DoubleList<T>* new_Node (T newData) {
    DoubleList<T>* newNode = new DoubleList<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

template<typename T>
void dllTraverse(DoubleList<T>* currentNode) {
    DoubleList<T>* tail = nullptr;   // fixed: was uninitialized when list is empty

    std::cout << "Forward \n";
    while (currentNode != nullptr) {
        std::cout << currentNode->data << "->";
        tail = currentNode;
        currentNode = currentNode->next;
    }
    std::cout << std::endl;

    std::cout << "Reverse \n";
    while (tail != nullptr) {
        std::cout << tail->data << "->";
        tail = tail->prev;
    }
    std::cout << std::endl;
}

template<typename T>
void dllInsertHead(T newData, DoubleList<T>** currentHead) {
    DoubleList<T>* newNode = new_Node(newData);
    newNode->next = *currentHead;
    if (*currentHead != nullptr) {          // guard added: avoids null deref on empty list
        (*currentHead)->prev = newNode;
    }
    *currentHead = newNode;
}

template<typename T>
void dllInsertTail(T newData, DoubleList<T>* currentHead) {
    DoubleList<T>* newNode = new_Node(newData);

    while (currentHead->next != nullptr) {
        currentHead = currentHead->next;
    }
    currentHead->next = newNode;
    newNode->prev = currentHead;
}

template <typename T>
void dllInsertAny(T newData, DoubleList<T>* prevNode){
    if(prevNode == nullptr) {
        std::cout << "Previous node cannot be null";
        return;
    }

    DoubleList<T>* newNode = new_Node(newData);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if(prevNode->next != nullptr){
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
}

// deletes a single node by value (kept separate from full-list clear)
template<typename T>
void dllDelete(T targetData, DoubleList<T>** head){
    DoubleList<T>* currentNode = *head;

    while(currentNode != nullptr && currentNode->data != targetData){
        currentNode = currentNode->next;
    }

    if(currentNode == nullptr){
        std::cout << "Data not found\n";
        return;
    }

    if(currentNode->prev != nullptr){
        currentNode->prev->next = currentNode->next;
    } else {
        *head = currentNode->next;
    }

    if(currentNode->next != nullptr){
        currentNode->next->prev = currentNode->prev;
    }

    delete currentNode;
}

// clears the entire list, freeing all nodes
template <typename T>
void dllDeleteList(DoubleList<T>** head){
    DoubleList<T>* currentNode = *head;

    while(currentNode != nullptr){
        DoubleList<T>* temp = currentNode;
        currentNode = currentNode->next;
        delete temp;
    }

    *head = nullptr;
}
#endif
#ifndef SINGLY_LL_H
#define SINGLY_LL_H

#include <iostream>

template <typename T> //this makes a class accepts any data type
class SingleList{ // the actual node
    public:
    T data; // data of the node
    SingleList<T>* next = nullptr; // stores the address of the next node
};

template <typename T>
void listTraversal(SingleList<T>* head){
    while (head != nullptr){
        std::cout << head->data;
        if (head->next != nullptr){
            std::cout << "->";
        }

        head = head->next;
    }
    std::cout << std::endl;
}

template <typename T>
void sllinsterHead(T newData, SingleList<T>** currentHead){
    SingleList<T>* newNode = new SingleList<T>;
    newNode->data = newData;
    newNode->next = *currentHead;
    *currentHead = newNode;
}

template <typename T>
void sllGeneralinsertion(T newData, SingleList<T>* prevNode){
    if (prevNode == nullptr){
        std::cout << "Previous node cannot be null.\n";
        return;
    }
    SingleList<T>* newNode = new SingleList<T>;
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

template<typename T>
void sllinsertEnd(T newData, SingleList<T>** head){
    SingleList<T>* newNode = new SingleList<T>;

    SingleList<T>* currentNode = *head;

    newNode->data = newData;
    newNode->next = nullptr;

    if (currentNode == nullptr){
        currentNode = newNode;
        return;
    }
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}

template<typename T>
void sllDelete(T findData, SingleList<T>** head){
    if(*head == nullptr){
        return;
    }
    SingleList<T>* currentNode = *head;
    SingleList<T>* prevNode = nullptr;

    while(currentNode != nullptr && currentNode->data != findData){
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    if(currentNode == nullptr){
        return;
    }
    if (prevNode == nullptr){
        *head = currentNode->next;
    }
    else{
        prevNode->next = currentNode->next;
    }

    delete currentNode;
}
template <typename T>

void sllDeleteList(SingleList<T>** head){

    SingleList<T>* currentNode = *head;

    while(currentNode != nullptr){
        SingleList<T>* temp = currentNode;
        currentNode = currentNode->next;
        delete temp;
    }

    *head = nullptr;
}

#endif

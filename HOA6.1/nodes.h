//
// Created by Bienvenido on 8/18/2026.
//

#ifndef HOA6_1_NODES_H
#define HOA6_1_NODES_H

template <typename T>
class Node{
public:
    T data;
    Node *next;
};

template <typename T>
Node<T> *new_node(T newData){
    Node<T> *newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}

#endif //HOA6_1_NODES_H

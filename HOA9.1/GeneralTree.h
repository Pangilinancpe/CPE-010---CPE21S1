#ifndef HOA9_1_GENERALTREE_H
#define HOA9_1_GENERALTREE_H

#include <iostream>
#include <vector>

// Task 1: Node structure using vector for multi-child representation
template <typename T>
class GeneralTree {
private:
    T key;
    std::vector<GeneralTree<T>*> children;

    // Recursive search helpers for Task 3.3
    bool searchPreOrder(T value);
    bool searchPostOrder(T value);
    bool searchInOrder(T value);

public:
    GeneralTree(T value);
    ~GeneralTree();

    GeneralTree<T>* insert(T value);
    GeneralTree<T>* find(T value);

    // Task 3 (3.2): Traversals
    void preOrder();
    void inOrder();
    void postOrder();

    // Task 3 (3.3): findData Function
    void findData(int choice, T value);
};

// Constructor
template <typename T>
GeneralTree<T>::GeneralTree(T value) {
    key = value;
}

// Destructor
template <typename T>
GeneralTree<T>::~GeneralTree() {
    for (GeneralTree<T>* child : children) {
        delete child;
    }
}

// Insert child under current node
template <typename T>
GeneralTree<T>* GeneralTree<T>::insert(T value) {
    GeneralTree<T>* childNode = new GeneralTree<T>(value);
    children.push_back(childNode);
    return childNode;
}

// Find node pointer by value
template <typename T>
GeneralTree<T>* GeneralTree<T>::find(T value) {
    if (key == value) return this;
    for (GeneralTree<T>* child : children) {
        GeneralTree<T>* res = child->find(value);
        if (res != nullptr) return res;
    }
    return nullptr;
}

// Task 3 (3.2): Pre-order Traversal
template <typename T>
void GeneralTree<T>::preOrder() {
    std::cout << key << " ";
    for (GeneralTree<T>* child : children) {
        child->preOrder();
    }
}

// Task 3 (3.2): In-order Traversal (First Child -> Root -> Other Children)
template <typename T>
void GeneralTree<T>::inOrder() {
    if (!children.empty()) {
        children[0]->inOrder();
    }
    std::cout << key << " ";
    for (size_t i = 1; i < children.size(); ++i) {
        children[i]->inOrder();
    }
}

// Task 3 (3.2): Post-order Traversal
template <typename T>
void GeneralTree<T>::postOrder() {
    for (GeneralTree<T>* child : children) {
        child->postOrder();
    }
    std::cout << key << " ";
}

// Task 3.3 Helper Methods
template <typename T>
bool GeneralTree<T>::searchPreOrder(T value) {
    if (key == value) return true;
    for (GeneralTree<T>* child : children) {
        if (child->searchPreOrder(value)) return true;
    }
    return false;
}

template <typename T>
bool GeneralTree<T>::searchPostOrder(T value) {
    for (GeneralTree<T>* child : children) {
        if (child->searchPostOrder(value)) return true;
    }
    return (key == value);
}

template <typename T>
bool GeneralTree<T>::searchInOrder(T value) {
    if (!children.empty()) {
        if (children[0]->searchInOrder(value)) return true;
    }
    if (key == value) return true;
    for (size_t i = 1; i < children.size(); ++i) {
        if (children[i]->searchInOrder(value)) return true;
    }
    return false;
}

// Task 3 (3.3): findData Method
template <typename T>
void GeneralTree<T>::findData(int choice, T value) {
    bool found = false;
    if (choice == 1) found = searchPreOrder(value);
    else if (choice == 2) found = searchPostOrder(value);
    else if (choice == 3) found = searchInOrder(value);

    if (found) {
        std::cout << "{" << value << "} was found!" << std::endl;
    }
}

#endif

#ifndef HOA_9_BINARYSEARCH_H
#define HOA_9_BINARYSEARCH_H

template <typename T>
class BinarySearchTree {
private:
    T key;
    BinarySearchTree<T>* left;
    BinarySearchTree<T>* right;

public:
    BinarySearchTree(T value);

    void insert(T value);

    void preOrder();
    void inOrder();
    void postOrder();
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree(T value) {
    key = value;
    left = nullptr;
    right = nullptr;
}

template <typename T>
void BinarySearchTree<T>::insert(T value) {
    if (value < key) {
        if (left == nullptr) {
            left = new BinarySearchTree<T>(value);
        } else {
            left->insert(value);
        }
    } else if (value > key) {
        if (right == nullptr) {
            right = new BinarySearchTree<T>(value);
        } else {
            right->insert(value);
        }
    }
}

// Pre-order: Root -> Left -> Right
template <typename T>
void BinarySearchTree<T>::preOrder() {
    std::cout << key << " ";
    if (left != nullptr) {
        left->preOrder();
    }
    if (right != nullptr) {
        right->preOrder();
    }
}

// In-order: Left -> Root -> Right
template <typename T>
void BinarySearchTree<T>::inOrder() {
    if (left != nullptr) {
        left->inOrder();
    }
    std::cout << key << " ";
    if (right != nullptr) {
        right->inOrder();
    }
}

// Post-order: Left -> Right -> Root
template <typename T>
void BinarySearchTree<T>::postOrder() {
    if (left != nullptr) {
        left->postOrder();
    }
    if (right != nullptr) {
        right->postOrder();
    }
    std::cout << key << " ";
}

#endif //HOA_9_BINARYSEARCH_H

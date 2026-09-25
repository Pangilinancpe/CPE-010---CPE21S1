#ifndef HOA_9_BINARYTREE_H
#define HOA_9_BINARYTREE_H

template <typename T>
class BinaryTree {
    private:
        T key;
        BinaryTree<T>* left = nullptr;
        BinaryTree<T>* right = nullptr;
    public:

    BinaryTree(T rootObj);

    void insertLeft(T newNode);
    void insertRight(T newNode);

    BinaryTree<T>* getLeft();
    BinaryTree<T>* getRight();

    void setRootVal(T obj);
    T getRootVal();

    bool isLeaf();
};

template <typename T>
BinaryTree<T>::BinaryTree(T rootObj) {
    key = rootObj;
    left = nullptr;
    right = nullptr;
}

template <typename T>
void BinaryTree<T>::insertLeft(T newNode) {
    if (left == nullptr) {
        left = new BinaryTree<T>(newNode);
    }
    else {
        BinaryTree<T>* newChild = new BinaryTree<T>(newNode);
        newChild->left = left;
        left = newChild;
    }
}

template <typename T>
void BinaryTree<T>::insertRight(T newNode) {
    if (right == nullptr) {
        right = new BinaryTree<T>(newNode);
    }
    else {
        BinaryTree<T>* newChild = new BinaryTree<T>(newNode);
        newChild->right = right;
        right = newChild;
    }
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::getLeft() {
    return left;
}
template <typename T>
BinaryTree<T>* BinaryTree<T>::getRight() {
    return right;
}

template <typename T>
void BinaryTree<T>::setRootVal(T obj) {
    key = obj;
}

template <typename T>
T BinaryTree<T>::getRootVal() {
    return key;
}

template <typename T>
bool BinaryTree<T>::isLeaf() {
    return left == nullptr && right == nullptr;
}


#endif
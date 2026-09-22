#include <iostream>
#include "bst.h"

int main() {
    BinarySearchTree<int> tree(20);

    tree.insert(30);
    tree.insert(70);
    tree.insert(50);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    tree.insert(10);
    tree.insert(15);

    tree.preOrder();
    std::cout << "\n";

    tree.inOrder();
    std::cout << "\n";

    tree.postOrder();
    std::cout << "\n";

    return 0;
}
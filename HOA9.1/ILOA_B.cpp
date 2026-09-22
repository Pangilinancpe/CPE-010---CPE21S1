#include <iostream>
#include "GeneralTree.h"

int main() {
    // Task 1
    GeneralTree<char> tree('A'); // Root Node A

    // Level 1: Children of A
    tree.insert('B');
    tree.insert('C');
    GeneralTree<char>* D = tree.insert('D');
    GeneralTree<char>* E = tree.insert('E');
    GeneralTree<char>* F = tree.insert('F');
    GeneralTree<char>* G = tree.insert('G');

    // Level 2: Grandchildren
    D->insert('H');
    E->insert('I');
    GeneralTree<char>* J = E->insert('J');
    F->insert('K');
    F->insert('L');
    F->insert('M');
    G->insert('N');

    // Level 3: Great-Grandchildren
    J->insert('P');
    J->insert('Q');

    // Task 3 (3.2): Display Traversals
    std::cout << "--- Task 3.2: Traversals ---" << std::endl;
    std::cout << "Pre-order:  ";
    tree.preOrder();
    std::cout << "\nPost-order: ";
    tree.postOrder();
    std::cout << "\nIn-order:   ";
    tree.inOrder();
    std::cout << "\n\n";

    // Task 3 (3.3): Testing findData Function
    std::cout << "--- Task 3.3: findData Output ---" << std::endl;
    tree.findData(1, 'J');
    tree.findData(2, 'J');
    tree.findData(3, 'J');
    tree.findData(1, 'Z');

    // Task 3 (3.4): Adding leaf node 'O' under 'G' and searching
    std::cout << "\n--- Task 3.4: Add Node 'O' under 'G' ---" << std::endl;
    G->insert('O');
    tree.findData(1, 'O');

    std::cout << "\nPre-order after adding O: ";
    tree.preOrder();
    std::cout << std::endl;

    return 0;
}
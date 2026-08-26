#include <iostream>
#include "nodes.h"
#include "searchingAlgo.h"

int main() {
    int nums[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int len = 10;
    int k = 18;

    Node<int>* head = new_node(nums[0]);
    Node<int>* ptr = head;
    for (int i = 1; i < len; i++) {
        ptr->next = new_node(nums[i]);
        ptr = ptr->next;
    }

    // Problem 1
    std::cout << "\nProblem 1\n";
    std::cout << "[Array Search]\n";
    countComparisonsArr(nums, len, k);
    std::cout << "\n[Linked List Search]\n";
    countComparisonsLL(head, k);

    //Problem 2
    std::cout << "\nProblem 2\n";
    countOccurrencesArr(nums, len, k);
    countOccurrencesLL(head, k);

    //Since both problem 3 and 4 are the same, one will modify
    int list[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int size = sizeof(list) / sizeof(list[0]);
    int key = 8;

    //Problem 3
    std::cout << "\nProblem 3\n";
    binarySearchArr(list, size, key);

    //Problem 4
    std::cout << "\nProblem 4\n";
    std::cout << "searching for binary number " << key << " in the array\n";
    binaryRecursive(list, 0, size - 1, key);


    return 0;
}
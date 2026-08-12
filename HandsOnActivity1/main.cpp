#include <iostream>
#include "singly_ll.h"

int main(){


    // making the head of the first node of the linked list
    SingleList<int>* head = new SingleList<int>;

    SingleList<int>* second = new SingleList<int>;
    SingleList<int>* third = new SingleList<int>;


    // giving value to data
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 4;
    third->next = nullptr;

    // printing out every list
    std::cout << "Linked list traversal: ";
    listTraversal(head);

    //inserting new head
    std::cout << "Newly inserted head of Linked List: ";
    sllinsterHead(0, &head);
    listTraversal(head);

    std::cout << "Newly inserted after a node of Linked List: \n";
    //inserted after the  VVVV
    sllGeneralinsertion(3,head->next);
    listTraversal(head);

    std::cout << "Newly inserted after a node of Linked List: \n";
    //inserted after the  VVVV
    sllGeneralinsertion(4,head->next->next);
    listTraversal(head);

    //inserting at the end
    std::cout << "Newly Inserted at the end: \n";
    sllinsertEnd(10,&head);
    listTraversal(head);

    //deleting a node by finding the data
    std::cout << "Deleted a node: \n";
    sllDelete(10, &head);
    listTraversal(head);

    std::cout << "Deleted Everyting";
    sllDeleteList(&head);
    listTraversal(head);

    return 0;
}

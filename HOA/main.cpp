#include <codecvt>
#include <iostream>
#include "singly_LL.h"
#include "double_LL.h"

int main(){

    DoubleList<char>* head = new_Node('C');
    DoubleList<char>* second = new_Node('P');
    DoubleList<char>* third = new_Node('E');

    //LINKING THE NODES
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    std::cout <<"Initial Traversal\n";
    dllTraverse(head);

    std::cout << "\n";
    //insert something before the head
    dllInsertHead('G', &head);
    dllTraverse(head);

    std::cout << "\n";
    //insert something after the tail
    dllInsertTail('1', head);
    dllTraverse(head);

    std::cout<<"\nInserting at the head"<<std::endl;
    dllInsertHead('G',&head);
    dllTraverse(head);

    std::cout<<"\nInserting at the any node"<<std::endl;
    //insert 'X' after 'P'
    DoubleList<char>* current = head;
    while(current != nullptr && current->data != 'P'){
        current = current->next;
    }
    if(current != nullptr){
        dllInsertAny('X',current);
    }
    dllTraverse(head);

    //clearing the whole list to free memory
    std::cout << "\nDeleting entire list:\n";
    dllDeleteList(&head);
    dllTraverse(head);

    return 0;
}
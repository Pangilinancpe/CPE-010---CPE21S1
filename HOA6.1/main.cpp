#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include "nodes.h"
#include "searchingalgo.h"

const int max_size = 50;

int main() {
      /*//generate random values:
        int dataset[max_size];
        srand(time(0));
        for(int i=0; i<max_size; i++){
            dataset[i] = rand();
        }
        for(int i=0; i < max_size; i++){
            std::cout <<dataset[i] << " ";
        }
        std::cout<<std::endl;
        //create a user input to ask what value to find:
        int toFind;
        std::cout<< "what value you want to search? ";
        std::cin >> toFind;

        linearSearchArr(dataset, max_size, toFind);*/

        //linked list:
        Node<char>* name1 = new_node('B');
        Node<char>* name2 = new_node('I');
        Node<char>* name3 = new_node('E');
        Node<char>* name4 = new_node('N');

        name1->next = name2;
        name2->next = name3;
        name3->next = name4;

        std::cout<<"Binary Search for Linked List result: ";
        binarySearchLL(name1, 'N');

    /*int dataset[max_size];
   srand(time(0));

   for (int i = 0; i < max_size; i++) {
       dataset[i] = rand();
   }

   // Binary search REQUIRES a sorted array
   std::sort(dataset, dataset + max_size);

   std::cout << "Sorted Dataset: ";
   for (int i = 0; i < max_size; i++) {
       std::cout << dataset[i] << " ";
   }
   std::cout << std::endl;

   int toFind;
   std::cout << "What value do you want to search? ";
   std::cin >> toFind;

   binarySearchArr(dataset, max_size, toFind);*/

    return 0;

}



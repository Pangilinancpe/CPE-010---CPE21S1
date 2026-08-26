//
// Created by Bienvenido on 8/18/2026.
//

#ifndef HOA6_1_SEARCHINGALGO_H
#define HOA6_1_SEARCHINGALGO_H
#include <iostream>
/*
N -> Boundary of the list
Item -> Searching number
Data -> Linear array
Step 1: I := 0
Step 2: Repeat while I <= n
  If (item = data[i])
  Print "Searching is successful"
  Exit
Else
  Print "Searching is Unsuccessful"
Exit
*/

template <typename T>
void linearSearchArr(T data[], int arrSize, T dataFind){
  //Step 1: I := 0
  int i = 0;

  //Repeat while I <= n
  while( i < arrSize){
    if(dataFind == data[i]){
      std::cout<<"the search is success\n";
      return;
    }
    //increment  i to move to the next element
    i++;
  }

  std::cout<< "the element is not found \n";
  return;
}

// NODES ->starting node
// tem that we are searching

template <typename T>
void linearSearchLL(Node<T>* node, T dataFind){
  //repeat the loop unting the current node is not null
  while(node != nullptr){

    // if item = current node's data then display searching is succ
    if(dataFind == node->data){
      std::cout<<"the search is success\n";
      return;
    }

    //if not, move to the next node
    node = node->next;
  }

  //the searching reached nullptr, -> search is unsuccessful
  std::cout<< "the element is not found \n";
  return;
}

/*
getMiddle, must take the first and last node as its parameters.
1. Traverse the singly linked list using two pointers.
2. Move one pointer by one step ahead and the other pointer by two steps.
3. When the fast pointer reaches the end of the singly linked list, the slow pointer will reach the middle of the singly linked list.
4. Return slow pointer address.
*/
template <typename T>
Node<T>* getMiddle(Node<T>* start , Node<T>* last){
  //use two pointers: 1. slow moves one node at a time, fast moves two at a time
  Node<T>* slow = start;
  Node<T>* fast = start;

  //get middle:
  while(fast != last && fast->next != last){
    //move slow (one step)
    slow = slow->next;
    //move fast (two steps)
    fast = fast->next->next;
  }
  return slow;
}
/*
    1.  Start node is set to head of the list and the last node is set to NULL.
    2.  Middle element is calculated using the two pointers approach discussed above.
    3.  If the middle element is same as the key to be searched, we return it.
    4.  Else if middle element is greater than the key to be searched, we have to search is the
right side of the singly linked list. So, we set start pointer to the next of middle
element.
    5.  Else if middle element is less than the key to be searched, we have to search is the left
side of the singly linked list. So, we set last pointer to the middle element.
    6.  If the key is found or the entire linked list gets traversed, we break the loop.

*/

//do this
template <typename T>
Node<T>* binarySearchLL(Node<T> *start, T findData){
  Node<T>* last = nullptr;

  while (start != last) {
    Node<T>* slow = start;
    Node<T>* fast = start;
    while (fast != last && fast->next != last) {
      slow = slow->next;
      fast = fast->next->next;
    }
    Node<T>* mid = slow;

    if (mid->data == findData) {
      std::cout << "Found: " << mid->data << std::endl;
      return mid; // Return the node when found
    }
    else if (mid->data < findData) {
      start = mid->next;
    }
    else {
      last = mid;
    }
  }

  std::cout << findData << " not found in list." << std::endl;
  return nullptr;
}
//since the function for binary search is already here
//we can say that we can also use this for problem 3
//problem 3
template <typename T>
void binarySearchArr(T data[], int arrSize, T dataFind) {
  int low = 0;
  int up = arrSize - 1;

  while (low <= up) {
    int mid = (low + up) / 2;

    if (dataFind == data[mid]) {
      std::cout << "Search element is found!\n";
      return;
    }
    else if (dataFind < data[mid]) {
      up = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }

  std::cout << "Search element is not found\n";
}
// update on the header file (from problem 1 supplementary)
// Function to count comparisons needed to find key '18' (Problem 1)
template <typename T>
void countComparisonsArr(T data[], int arrSize, T dataFind) {
  int comparisons = 0;
  for (int i = 0; i < arrSize; i++) {
    comparisons++;
    if (data[i] == dataFind) {
      std::cout << "the search is success\n";
      std::cout << "Comparisons needed: " << comparisons << "\n";
      return;
    }
  }
  std::cout << "the element is not found\n";
  std::cout << "Comparisons needed: " << comparisons << "\n";
}

template <typename T>
void countComparisonsLL(Node<T>* node, T dataFind) {
  int comparisons = 0;
  while (node != nullptr) {
    comparisons++;
    if (node->data == dataFind) {
      std::cout << "the search is success\n";
      std::cout << "Comparisons needed: " << comparisons << "\n";
      return;
    }
    node = node->next;
  }
  std::cout << "the element is not found\n";
  std::cout << "Comparisons needed: " << comparisons << "\n";
}

// Function to count repeating instances of key 'k' (Problem 2)
template <typename T>
void countOccurrencesArr(T data[], int arrSize, T k) {
  int count = 0;
  for (int i = 0; i < arrSize; i++) {
    if (data[i] == k) {
      count++;
    }
  }
  std::cout << "Repeating instances of " << k << " in Array: " << count << "\n";
}

template <typename T>
void countOccurrencesLL(Node<T>* node, T k) {
  int count = 0;
  while (node != nullptr) {
    if (node->data == k) {
      count++;
    }
    node = node->next;
  }
  std::cout << "Repeating instances of " << k << " in Linked List: " << count << "\n";
}

//function for problem 4
template <typename T>
void binaryRecursive(T data[], int low, int up, T dataFind) {
  if (low > up) {
    std::cout << "search failure\n";
    return;
  }

  int mid = (low + up) / 2;

  if (data[mid] == dataFind) {
    std::cout << "search success\n";
    return;
  }
  else if (dataFind < data[mid]) {
    binaryRecursive(data, low, mid - 1, dataFind);
  }
  else {
    binaryRecursive(data, mid + 1, up, dataFind);
  }
}

#endif //HOA6_1_SEARCHINGALGO_H

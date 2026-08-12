#include <iostream>
#include <string>
#include "queueArr.h"

int main() {
    queueArr<std::string> q1(10);

    // Empty()
    std::cout << "\nIs q1 empty? " << (q1.Empty() ? "Yes" : "No") << std::endl;

    // Enqueue()
    q1.Enqueue("B");
    q1.Enqueue("I");
    q1.Enqueue("E");
    q1.Enqueue("N");
    q1.Enqueue("1");
    q1.Enqueue("7");

    // Size()
    std::cout << "\nCurrent size of q1: " << q1.Size() << std::endl;

    // display all
    std::cout << "\nQueue contents: ";
    display(q1);

    // Front()
    std::cout << "\nFront element: " << q1.Front() << std::endl;

    // Back()
    std::cout << "\nBack element: " << q1.Back() << std::endl;

    // Dequeue()
    q1.Dequeue();
    std::cout << "\nDequeue: " << q1.Front() << std::endl;

    // Copy Constructor
    queueArr<std::string> q2 = q1;
    std::cout << "\nq2 (Copied): ";
    display(q2);

    // Copy Assignment Operator
    queueArr<std::string> q3(10);
    q3 = q1;
    std::cout << "\nq3 (Assigned): ";
    display(q3);

    // Clear()
    q1.Clear();
    std::cout << "\nq1 cleared. Is q1 empty now? " << (q1.Empty() ? "Yes" : "No") << std::endl;

    return 0;
}
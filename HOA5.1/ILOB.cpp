#include <iostream>
#include "queuell.h"

int main() {
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    enqueue(&front, &back, 'B');
    enqueue(&front, &back, 'I');
    enqueue(&front, &back, 'E');
    enqueue(&front, &back, 'N');
    display(front);
    dequeue(&front, &back);
    display(front);

    std::cout << Front(&front);

    return 0;
}



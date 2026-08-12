#include <iostream>
#include "stackList.h"

int main() {

    std::cout << "--- PUSHING 'c' 'p' 'e' ONTO THE STACK --- \n";

    // push items onto the stack
    push('c');
    push('p');
    push('e');

    Top<char>();

    std::cout << "\n --- PRINTING ALL ELEMENTS --- \n";
    print<char>();

    std::cout << "\n--- POPPING ALL ELEMENTS --- \n";

    while (!isEmpty<char>()) {
        std::cout << "Popped: " << pop<char>() << std::endl;
    }

    std::cout << "\n--- TESTING UNDERFLOW ---\n";
    pop<char>();
    return 0;
}

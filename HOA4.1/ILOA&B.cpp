#include <iostream>

const size_t maxCap = 100;
int stack [maxCap];
int Top = -1, i, newData = 0;

void push();
void pop();
void top();
bool isEmpty();
bool isFull();
void Print();


int main() {
    int choice;

    std::cout << "Enter the number of the max element for the stack: ";
    std::cin >> i;
    while (true) {
        std::cout << "stack operation" << std::endl;
        std:: cout << " 1.PUSH\n 2.POP\n 3.TOP\n 4.isEMPTY\n 5.Print\n 6.END\n " << std::endl;
        std:: cin >> (choice);
        switch (choice) {
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: top();
                break;
            case 4: isEmpty();
                break;
            case 5: Print();
                break;
            case 6:
                return 0;
            default: std:: cout << "Wrong choice \n";
        }
    }
    return 0;
}

bool isEmpty() {
    if (Top == -1) return true;
    return false;
}

bool isFull() {
    if (Top == maxCap) return true;
    return false;
}

void push() {
    if (Top == i-1) {
        std::cout << "stack overflow" << std::endl;
        return;
    }
    std::cout << "New value to add into the stack" << std::endl;
    std::cin >> newData;
    stack[++Top] = newData;
}

void top() {
    if (isEmpty()) {
        std::cout << "stack underflow" << std::endl;
        return;
    }

    std::cout << "The element on the top of the stack is " << stack[Top] << std::endl;
}

void pop() {
    if (isEmpty()) {
        std::cout << "stack underflow" << std::endl;
        return;
    }
    std::cout << "popping " << stack[Top] << std::endl;
    Top--;
}

// Definition added
void Print() {
    if (isEmpty()) {
        return;
    }
    for (int j = 0; j <= Top; j++) {
        std::cout << stack[j] << " ";
    }
    std::cout << std::endl;
}


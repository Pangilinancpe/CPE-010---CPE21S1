#include <iostream>
#include <thread>

int globalValue = 0;
void add(int value) {
    globalValue += value;
}

int main() {
    std::thread T1(add, 15);
    std::thread T2(add, 25);
    std::thread T3(add, 60);
    std::cout << "Display: " << globalValue << std::endl;
    T1.join();
    std::cout << "Display after T1.join(): " << globalValue << std::endl;
    T2.join();
    std::cout << "Display after T2.join(): " << globalValue << std::endl;
    T3.join();
    std::cout << "Display after T3.join(): " << globalValue << std::endl;
    return 0;
}
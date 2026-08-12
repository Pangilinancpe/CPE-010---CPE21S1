#include <iostream>
#include <queue>

void display(std::queue<char> r);

int main() {

    std::queue<char> q;

    q.push('c');
    q.push('p');
    q.push('e');
    q.push('0');
    q.push('1');
    q.push('0');

    //diplay
    display(q);

    //empty()
    std::cout << "Is it empty? " << (q.empty() ? "Yes" : "No") << "\n";

    //size()
    std::cout << "Size: " << q.size() << "\n";

    //front
    std::cout << "Front: " << q.front() << "\n";

    //back
    std::cout << "Back: " << q.back() << "\n";

    //pop
    q.pop();
    std::cout << "Popped element.\n";

    //display
    std::cout << "After popping the element: ";
    display(q);

    //push another element
    q.push('B');
    std::cout << "Pushed into the queue.\n";

    display(q);

    //deleting all element
    while (!q.empty()) {
        q.pop();
    }
    std::cout << "all elements are deleted.\n";

}

void display(std::queue<char> r) {
    std::queue <char> c = r;

    while (!c.empty()) {
        std::cout << c.front() << " ";
        c.pop();
    }
    std::cout << "\n";
}

//
// Created by Bienvenido on 8/13/2026.
//

#ifndef PRELIM_CHECKER_H
#define PRELIM_CHECKER_H
inline bool isPalindrome(const std::string& input) {
    ArrayStack<char> stack;
    LinkedListQueue<char> queue;

    // Push into stack (LIFO) and enqueue into queue (FIFO)
    for (char ch : input) {
        stack.push(ch);
        queue.enqueue(ch);
    }

    // Compare characters popped from Stack and dequeued from Queue
    while (!stack.isEmpty() && !queue.isEmpty()) {
        if (stack.top() != queue.front()) {
            return false; // Mismatch found
        }
        stack.pop();
        queue.dequeue();
    }

    return true;
}
template <typename T>
class ArrayStack {
private:
    std::vector<T> data;

public:
    void push(T val) {
        data.push_back(val);
    }

    void pop() {
        if (!isEmpty()) {
            data.pop_back();
        }
    }

    T top() const {
        if (!isEmpty()) {
            return data.back();
        }
        throw std::runtime_error("Stack is empty");
    }

    bool isEmpty() const {
        return data.empty();
#endif //PRELIM_CHECKER_H

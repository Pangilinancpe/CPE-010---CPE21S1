#ifndef HOA5_1_QUEUEARR_H
#define HOA5_1_QUEUEARR_H

#include <iostream>

template <typename T>
class queueArr {
private:
    // create pointer array:
    T* q_array;
    size_t q_capacity;
    size_t q_size;
    int q_front;
    int q_back;

public:
    // prototypes to use for queueArr:
    queueArr(size_t capacity);
    bool Empty();
    bool Full();

    size_t Size();
    void Clear();

    T Front();
    T Back();

    void Enqueue(T newData);
    void Dequeue();

    ~queueArr();

    // tasks
    queueArr(const queueArr& other);
    queueArr& operator=(const queueArr& other);
};

// constructor
template <typename T>
queueArr<T>::queueArr(size_t capacity) {
    q_capacity = capacity;
    q_size = 0;
    q_front = 0;
    q_back = -1;
    q_array = new T[q_capacity];
    std::cout << "Queue created with capacity: " << q_capacity << std::endl;
}

// destructor
template <typename T>
queueArr<T>::~queueArr() {
    delete[] q_array;
    std::cout << "Queue destroyed." << std::endl;
}

// Empty
template <typename T>
bool queueArr<T>::Empty() {
    return q_size == 0;
}

// Full
template <typename T>
bool queueArr<T>::Full() {
    return q_size == q_capacity;
}

// Size
template <typename T>
size_t queueArr<T>::Size() {
    return q_size;
}

// clear
template <typename T>
void queueArr<T>::Clear() {
    q_size = 0;
    q_front = 0;
    q_back = -1;
}

// return the element in the front of the queue
template <typename T>
T queueArr<T>::Front() {
    if (Empty()) {
        std::cout << "Queue is empty.\n" << std::endl;
        return T{};
    }
    return q_array[q_front];
}

// back
template <typename T>
T queueArr<T>::Back() {
    if (Empty()) {
        std::cout << "Queue is empty.\n" << std::endl;
        return T{};
    }
    return q_array[q_back];
}

// enqueue
template <typename T>
void queueArr<T>::Enqueue(T newData) {
    if (Full()) {
        std::cout << "Queue is full." << std::endl;
        return;
    }

    q_back = (q_back + 1) % static_cast<int>(q_capacity);
    q_array[q_back] = newData;
    q_size++;
}

// dequeue
template <typename T>
void queueArr<T>::Dequeue() {
    if (Empty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    q_front = (q_front + 1) % static_cast<int>(q_capacity);
    q_size--;
}

// copy constructor
template <typename T>
queueArr<T>::queueArr(const queueArr& other) {
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;
    q_array = new T[q_capacity];
    for (size_t i = 0; i < q_capacity; ++i) {
        q_array[i] = other.q_array[i];
    }
}

// copy assignment operator
template <typename T>
queueArr<T>& queueArr<T>::operator=(const queueArr& other) {
    if (this != &other) {
        delete[] q_array;

        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;
        q_array = new T[q_capacity];
        for (size_t i = 0; i < q_capacity; ++i) {
            q_array[i] = other.q_array[i];
        }
    }
    return *this;
}

//adding new function to display all of the element
template <typename T>
void display(queueArr<T> q) {
    std::cout << "Queue elements: ";
    while (!q.Empty()) {
        std::cout << q.Front() << " ";
        q.Dequeue();
    }
    std::cout << std::endl;
}

#endif // HOA5_1_QUEUEARR_H
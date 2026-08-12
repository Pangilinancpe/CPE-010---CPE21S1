#ifndef HOA3_1_DOUBLE_LL_H_2_H
#define HOA3_1_DOUBLE_LL_H_2_H

#include <iostream>
#include <string>

template<typename T>
class DoubleList {
public:
    T data;
    DoubleList<T>* next = nullptr;
    DoubleList<T>* prev = nullptr;
};

template<typename T>
void circularInsertTail(T newData, DoubleList<T>** head) {
    DoubleList<T>* newNode = new DoubleList<T>;
    newNode->data = newData;

    if (*head == nullptr) {
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }

    DoubleList<T>* tail = (*head)->prev;

    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = *head;
    (*head)->prev = newNode;
}

template<typename T>
void printPlaylist(DoubleList<T>* start) {
    if (start == nullptr) {
        std::cout << "Playlist is empty!\n";
        return;
    }

    DoubleList<T>* current = start;
    do {
        std::cout << current->data << "->";
        current = current->next;
    } while (current != start);
    std::cout << "END\n";
}

template<typename T>
void playNextSong(DoubleList<T>** current) {
    if (*current == nullptr) {
        std::cout << "Playlist is empty!\n";
        return;
    }
    *current = (*current)->next;
    std::cout << "Now playing from the Playlist: " << (*current)->data << "\n";
    printPlaylist(*current);
}

template<typename T>
void playPreviousSong(DoubleList<T>** current) {
    if (*current == nullptr) {
        std::cout << "Playlist is empty!\n";
        return;
    }
    *current = (*current)->prev;
    std::cout << "Now playing from the Playlist: " << (*current)->data << "\n";
    printPlaylist(*current);
}

template<typename T>
void circularDeleteSong(T targetData, DoubleList<T>** head) {
    if (*head == nullptr) {
        std::cout << "Playlist is empty, cannot delete.\n";
        return;
    }

    DoubleList<T>* current = *head;
    DoubleList<T>* toDelete = nullptr;

    do {
        if (current->data == targetData) {
            toDelete = current;
            break;
        }
        current = current->next;
    } while (current != *head);

    if (toDelete == nullptr) {
        std::cout << "Song '" << targetData << "' not found in playlist.\n";
        return;
    }

    if (toDelete->next == toDelete) {
        delete toDelete;
        *head = nullptr;
        std::cout << "Removed '" << targetData << "'. Playlist is now empty.\n";
        return;
    }

    toDelete->prev->next = toDelete->next;
    toDelete->next->prev = toDelete->prev;

    if (toDelete == *head) {
        *head = toDelete->next;
    }

    delete toDelete;
    std::cout << "Successfully removed song: " << targetData << "\n";
}

#endif //HOA3_1_DOUBLE_LL_H_2_H
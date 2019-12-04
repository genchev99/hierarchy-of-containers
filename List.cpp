//
// Created by pr3dat0r on 4.12.19 г..
//

#include "List.h"

void List::insert(int value) {
    head = new Node(value, nullptr, head);
    if (head->getNext() != nullptr) {
        head->getNext()->setPrev(head);
    }
}

int List::pop() {
    int result = 0;

    if (head != nullptr) {
        result = head->getValue();
        head = head->getNext();
        delete(head->getPrev());
        head->setPrev(nullptr);
    } else {
        /* Todo rework to throw an exception */
        std::cerr << "The structure is empty!" << std::endl;
    }

    return result;
}

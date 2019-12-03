//
// Created by bg-tv on 3.12.19 г..
//

#include "Stack.h"

void Stack::insert(int value) {
    head = new Node(value, nullptr, head);
}

int Stack::pop() {
    int result = 0;

    if (head != nullptr) {
        result = head->getValue();
        /* Todo delete the old head */
        head = head->getNext();
    } else {
        /* Todo rework to throw an exception */
        std::cerr << "The structure is empty!" << std::endl;
    }

    return result;
}

Stack::Stack(): BaseContainer() {}

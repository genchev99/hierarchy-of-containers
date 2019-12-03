//
// Created by bg-tv on 3.12.19 г..
//

#include "Stack.h"

void Stack::insert(int value) {
    if (tail == nullptr) {
        tail = new Node(value);
    } else {
        tail->setNext(new Node(value, tail, nullptr));
        tail = tail->getNext();
    }
}

int Stack::pop() {
    int result = 0;

    if (tail != nullptr) {
        result = tail->getValue();
        /* Todo delete old head */
        tail = tail->getPrev();
    }

    return result;
}

Stack::Stack(): BaseContainer() {}

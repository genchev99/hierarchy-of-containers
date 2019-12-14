//
// Created by bg-tv on 3.12.19 г..
//

#include "Stack.h"

void Stack::insert(int value) {
    _head = new Node(value, nullptr, _head);

    if (_head->getNext() != nullptr) {
        _head->getNext()->setPrev(_head);
    }
}

int Stack::pop() {
    int result = 0;

    if (_head != nullptr) {
        result = _head->getValue();
        /* Todo delete the old _head */
        _head = _head->getNext();
        if (_head != nullptr) {
            delete _head->getPrev();
            _head->setPrev(nullptr);
        }
    } else {
        /* Todo rework to throw an exception */
        std::cerr << "The structure is empty!" << std::endl;
    }

    return result;
}

Stack::Stack(): BaseContainer() {}

//
// Created by pr3dat0r on 4.12.19 г..
//

#include "List.h"

void List::insert(int value) {
    _head = new Node(value, nullptr, _head);
    if (_head->getNext() != nullptr) {
        _head->getNext()->setPrev(_head);
    }
}

int List::pop() {
    int result = 0;

    if (_head != nullptr) {
        result = _head->getValue();
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

std::string List::stringify() {
    return "d " + this->stringifyValues();
}

char List::type() {
    return 'D';
}

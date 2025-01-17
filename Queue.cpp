//
// Created by bg-tv on 3.12.19 г..
//

#include "Queue.h"

void Queue::insert(int value) {
    if (_head == nullptr) {
        _head = new Node(value);
    } else {
        /* Navigates to the end of the queue and adds the element */
        Node* crr = _head;

        while (crr->getNext() != nullptr) {
            crr = crr->getNext();
        }

        crr->setNext(new Node(value, crr));
    }
}

int Queue::pop() {
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

Queue::Queue(): BaseContainer() {}

std::string Queue::stringify() {
    return "q " + this->stringifyValues();
}

void Queue::sort() {
    std::vector<int> helper;

    while (_head != nullptr) {
        helper.push_back(this->pop());
    }

    std::sort(helper.begin(), helper.end());

    for (auto item : helper) {
        this->insert(item);
    }
}

char Queue::type() {
    return 'Q';
}

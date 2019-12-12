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
        /* Todo delete old _head */
        _head = _head->getNext();
    } else {
        /* Todo rework to throw an exception */
        std::cerr << "The structure is empty!" << std::endl;
    }

    return result;
}

Queue::Queue(): BaseContainer() {}

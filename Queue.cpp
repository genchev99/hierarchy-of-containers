//
// Created by bg-tv on 3.12.19 г..
//

#include "Queue.h"

void Queue::insert(int value) {
    if (head == nullptr) {
        head = new Node(value);
        tail = head;
    } else {
        tail->setNext(new Node(value, tail, nullptr));
        tail = tail->getNext();
    }
}

int Queue::pop() {
    int result = 0;

    if (head != nullptr) {
        result = head->getValue();
        /* Todo delete old head */
        head = head->getNext();
    }

    return result;
}

Queue::Queue(): BaseContainer() {}

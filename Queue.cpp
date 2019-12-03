//
// Created by bg-tv on 3.12.19 г..
//

#include "Queue.h"

void Queue::insert(int value) {
    if (head == nullptr) {
        head = new Node(value);
    } else {
        /* Navigates to the end of the queue and adds the element */
        Node* crr = head;
        while (crr->getNext() != nullptr) {
            crr = crr->getNext();
        }

        crr->setNext(new Node(value));
    }
}

int Queue::pop() {
    int result = 0;

    if (head != nullptr) {
        result = head->getValue();
        /* Todo delete old head */
        head = head->getNext();
    } else {
        /* Todo rework to throw an exception */
        std::cerr << "The structure is empty!" << std::endl;
    }

    return result;
}

Queue::Queue(): BaseContainer() {}

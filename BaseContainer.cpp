//
// Created by bg-tv on 3.12.19 г..
//

#include "BaseContainer.h"

BaseContainer::BaseContainer(): head(nullptr), tail(nullptr) {}

void BaseContainer::insertEnd(int value) {
    if (head == nullptr) {
        head = new Node(value);
        tail = head;
    } else {
        tail->setNext(new Node(value, tail, nullptr));
        tail = tail->getNext();
    }
}

void BaseContainer::print() {
    headToTail();
}

void BaseContainer::headToTail() {
    Node* crr = head;

    while (crr != nullptr) {
        std::cout << crr->getValue() << ", ";
        crr = crr->getNext();
    }

    std::cout << std::endl;
}

void BaseContainer::tailToHead() {
    Node* crr = tail;

    while (crr != nullptr) {
        std::cout << crr->getValue() << ", ";
        crr = crr->getPrev();
    }

    std::cout << std::endl;
}

//
// Created by bg-tv on 3.12.19 г..
//

#include "BaseContainer.h"

BaseContainer::BaseContainer(): head(nullptr) {}

//void BaseContainer::insertEnd(int value) {
//    if (head == nullptr) {
//        head = new Node(value);
//        tail = head;
//    } else {
//        tail->setNext(new Node(value, tail, nullptr));
//        tail = tail->getNext();
//    }
//}

void BaseContainer::print() {
    Node* crr = head;

    while (crr != nullptr) {
        std::cout << crr->getValue() << ", ";
        crr = crr->getNext();
    }

    std::cout << std::endl;
}

bool BaseContainer::member(int const &x) {
    Node* crr = head;

    while (crr != nullptr) {
        if (crr->getValue() == x) {
            return true;
        }

        crr = crr->getNext();
    }

    return false;
}

size_t BaseContainer::getSize() {
    size_t counter = 0;
    Node* crr = head;

    while (crr != nullptr) {
        counter++;
        crr = crr->getNext();
    }

    return counter;
}

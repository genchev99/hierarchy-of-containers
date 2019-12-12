//
// Created by bg-tv on 3.12.19 г..
//

#include "BaseContainer.h"

BaseContainer::BaseContainer(): _head(nullptr) {}

void BaseContainer::print() {
    Node<int>* crr = _head;

    while (crr != nullptr) {
        std::cout << crr->getValue() << ", ";
        crr = crr->getNext();
    }

    std::cout << std::endl;
}

bool BaseContainer::member(int const &x) {
    Node<int>* crr = _head;

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
    Node<int>* crr = _head;

    while (crr != nullptr) {
        counter++;
        crr = crr->getNext();
    }

    return counter;
}

bool BaseContainer::match(Condition condition) {
    Node<int>* crr = _head;

    while (crr != nullptr) {
        if (condition(crr->getValue())) {
            return true;
        }

        crr = crr->getNext();
    }

    return false;
}


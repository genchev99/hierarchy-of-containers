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
        tail->setNext(new Node(value, nullptr, tail));
        tail = tail->getNext();
    }
}

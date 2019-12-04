//
// Created by bg-tv on 3.12.19 г..
//

#include "MasterContainer.h"

MasterContainer::MasterContainer(): _head(nullptr) {}

void MasterContainer::addContainer(BaseContainer *container) {
    /* Todo change it to add the new container at the end of the list (not so important) */
    _head = new MasterNode(container, nullptr, _head);
    if (_head->getNext() != nullptr) {
        _head->getNext()->setPrev(_head);
    }
}

void MasterContainer::print() {
    MasterNode* crr = _head;

    while (crr != nullptr) {
        crr->getContainer()->print();
        crr = crr->getNext();
    }
}


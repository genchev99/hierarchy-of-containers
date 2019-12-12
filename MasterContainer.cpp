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

    std::cout << "======================" << std::endl;
    while (crr != nullptr) {
        crr->getContainer()->print();
        crr = crr->getNext();
    }
    std::cout << "======================" << std::endl;
}

bool MasterContainer::contains(int x) {
    MasterNode* crr = _head;

    while (crr != nullptr) {
        if (crr->getContainer()->member(x)) {
            return true;
        }

        crr = crr->getNext();
    }

    return false;
}

void MasterContainer::addElementToLowestContainer(int x) {
    getLowestContainer()->getContainer()->insert(x);
}

MasterNode *MasterContainer::getLowestContainer() {
    if (_head == nullptr) {
        return nullptr;
    }

    MasterNode* crr = _head;
    MasterNode* res = _head;
    size_t lowestSize = _head->getContainer()->getSize();

    while (crr != nullptr) {
        if (crr->getContainer()->getSize() < lowestSize) {
            res = crr;
            lowestSize = crr->getContainer()->getSize();
        }

        crr = crr->getNext();
    }

    return res;
}

bool MasterContainer::matchAny(Condition condition) {
    MasterNode* crr = _head;

    while (crr != nullptr) {
        if (crr->getContainer()->match(condition)) {
            return true;
        }

        crr = crr->getNext();
    }

    return false;
}

void MasterContainer::filter(Condition condition) {
    MasterNode* crr = _head;

    while (crr != nullptr) {
        crr->getContainer()->filter(condition);

        crr = crr->getNext();
    }
}

void MasterContainer::printBackwards() {
    MasterNode* crr = _head;

    std::cout << "======================" << std::endl;
    while (crr != nullptr) {
        crr->getContainer()->printBackwards();
        crr = crr->getNext();
    }
    std::cout << "======================" << std::endl;
}


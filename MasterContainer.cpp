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

MasterContainer::~MasterContainer() {
    deleteAllContainers(_head);
}

void MasterContainer::deleteAllContainers(MasterNode *crr) {
    if (crr == nullptr) {
        return;
    }

    deleteAllContainers(crr->getNext());
    delete crr;
}

void MasterContainer::save(std::string path) {
    MasterNode* crr = _head;
    std::ofstream newFile(path, std::ios_base::app);

    if (newFile.is_open()) {
        while (crr != nullptr) {
            newFile << crr->getContainer()->stringify() << "\n";

            crr = crr->getNext();
        }
    } else {
        std::cerr << "[ Err ] Unable to handle the file";
    }

    newFile.close();
}

void MasterContainer::shuffle() {
    MasterNode* crr = _head;

    while (crr != nullptr) {
        crr->getContainer()->shuffle();

        crr = crr->getNext();
    }
}

void MasterContainer::sort() {
    MasterNode* crr = _head;

    while (crr != nullptr) {
        crr->getContainer()->sort();

        crr = crr->getNext();
    }
}

MasterContainer::AscendingIterator MasterContainer::begin() {
    return AscendingIterator(this, 0);
}

MasterContainer::AscendingIterator MasterContainer::end() {
    return AscendingIterator(this, -1);
}

MasterContainer::AscendingIterator MasterContainer::first(int elem) {
    for (AscendingIterator it = this->begin(); it != this->end(); ++it) {
        if (*it == elem) {
            return it;
        }
    }

    return this->end();
}


void MasterContainer::AscendingIterator::operator++() {
    ++baseIterators[current];
    next();
}

bool MasterContainer::AscendingIterator::operator!=(const MasterContainer::AscendingIterator &other) const {
    if (current == -1 || other.current == -1) { /* No invalid read */
        return current != other.current;
    }

    return current != other.current || baseIterators[current] != other.baseIterators[current];
}

int MasterContainer::AscendingIterator::operator*() {
    return *baseIterators[current];
}

MasterContainer::AscendingIterator::AscendingIterator(MasterContainer * owner, int crrInd = 0)
        : current(crrInd), owner(owner) {
    MasterNode* crr = owner->_head;

    while (crr != nullptr) {
        if (crrInd == -1) {
            baseIterators.push_back(crr->getContainer()->end());
            crr = crr->getNext();
        } else {
            baseIterators.push_back(crr->getContainer()->begin());
            crr = crr->getNext();
        }
    }

    if (crrInd != -1) {
        next();
    }
}

void MasterContainer::AscendingIterator::next() {
    int min = -1;

    for (int i = 0; i < baseIterators.size(); ++i) {
        if (baseIterators[i] != BaseContainer::AscendingIterator(nullptr, baseIterators[i].owner)) {
            if (min == -1) {
                min = i;
            }

            if (*baseIterators[min] > *baseIterators[i]) {
                min = i;
            }
        }
    }

    current = min;
}

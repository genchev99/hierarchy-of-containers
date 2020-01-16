//
// Created by bg-tv on 3.12.19 г..
//

#include <vector>
#include "BaseContainer.h"

BaseContainer::BaseContainer(): _head(nullptr) {}

void BaseContainer::print() {
    Node* crr = _head;

    while (crr != nullptr) {
        std::cout << crr->getValue() << ", ";
        crr = crr->getNext();
    }

    std::cout << std::endl;
}

bool BaseContainer::member(int const &x) {
    Node* crr = _head;

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
    Node* crr = _head;

    while (crr != nullptr) {
        counter++;
        crr = crr->getNext();
    }

    return counter;
}

bool BaseContainer::match(Condition condition) {
    Node* crr = _head;

    while (crr != nullptr) {
        if (condition(crr->getValue())) {
            return true;
        }

        crr = crr->getNext();
    }

    return false;
}

/* Todo call destructors */
void BaseContainer::filter(Condition condition) {
    Node* crr = _head;

    while (crr != nullptr) {
        if (condition(crr->getValue())) {
            if (crr == _head) {
                _head = _head->getNext();
                _head->setPrev(nullptr);
            } else {
                if (crr->getNext() != nullptr) {
                    crr->getNext()->setPrev(crr->getPrev());
                }

                if (crr->getPrev() != nullptr) {
                    crr->getPrev()->setNext(crr->getNext());
                }

                if (crr->getPrev() == nullptr && crr->getNext() == nullptr) {
                    _head = nullptr;
                }
            }
        }

        crr = crr->getNext();
    }
}

void BaseContainer::printBackwards() {
    Node* crr = _head;

    while (crr->getNext() != nullptr) {
        crr = crr->getNext();
    }
    /* At this point crr is pointing to the last element */

    while (crr != nullptr) {
        std::cout << crr->getValue() << ", ";
        crr = crr->getPrev();
    }

    std::cout << std::endl;
}

BaseContainer::~BaseContainer() {
    std::cout << "Base container destructor called!" << std::endl;
    deleteAllNodes(_head);
}

void BaseContainer::deleteAllNodes(Node* crr) {
    if (crr == nullptr) {
        return;
    }

    deleteAllNodes(crr->getNext());

    delete crr;
}

std::string BaseContainer::stringifyValues() {
    std::string res;
    Node* crr = _head;

    while (crr != nullptr) {
        res += std::to_string(crr->getValue());
        if (crr->getNext() != nullptr) {
            res += " ";
        }

        crr = crr->getNext();
    }

    return res;
}

void BaseContainer::shuffle() {
    std::vector<int> helper;

    while (_head != nullptr) {
        helper.push_back(this->pop());
    }

    std::random_shuffle(helper.begin(), helper.end());

    for (auto item : helper) {
        this->insert(item);
    }
}

bool comparatorFunc(int a, int b) {
    return (a > b);
}

void BaseContainer::sort() {
    std::vector<int> helper;

    while (_head != nullptr) {
        helper.push_back(this->pop());
    }

    std::sort(helper.begin(), helper.end(), comparatorFunc);

    for (auto item : helper) {
        this->insert(item);
    }
}



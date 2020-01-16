//
// Created by pr3dat0r on 4.12.19 г..
//

#include "MasterNode.h"

MasterNode::MasterNode(BaseContainer *baseContainer, MasterNode *prev, MasterNode *next): _container(baseContainer), _prev(prev), _next(next) {}

BaseContainer *MasterNode::getContainer() const {
    return _container;
}

void MasterNode::setContainer(BaseContainer *container) {
    _container = container;
}

MasterNode *MasterNode::getPrev() const {
    return _prev;
}

void MasterNode::setPrev(MasterNode *prev) {
    _prev = prev;
}

MasterNode *MasterNode::getNext() const {
    return _next;
}

void MasterNode::setNext(MasterNode *next) {
    _next = next;
}

MasterNode::~MasterNode() {
    delete(_container);
}

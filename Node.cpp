//
// Created by bg-tv on 3.12.19 г..
//

#include "Node.h"

Node::Node(int value, Node *prev, Node *next) :_value(value), _prev(prev), _next(next) {}

int Node::getValue() const {
    return _value;
}

void Node::setValue(int value) {
    Node::_value = value;
}

Node *Node::getNext() const {
    return _next;
}

void Node::setNext(Node *next) {
    Node::_next = next;
}

Node *Node::getPrev() const {
    return _prev;
}

void Node::setPrev(Node *before) {
    Node::_prev = before;
}

//
// Created by bg-tv on 3.12.19 г..
//

#include "Node.h"

Node::Node(int value, Node *next, Node *before): _value(value), _next(next), _prev(before) {}

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

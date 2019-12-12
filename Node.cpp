//
// Created by bg-tv on 3.12.19 г..
//

#include "Node.h"


template<typename T>
Node<T>::Node(T value, Node *prev, Node *next): _value(value), _prev(prev), _next(next) {}

template<typename T>
T Node<T>::getValue() const {
    return _value;
}

template<typename T>
void Node<T>::setValue(T value) {
    _value = value;
}

template<typename T>
Node<T> *Node<T>::getNext() const {
    return _next;
}

template<typename T>
void Node<T>::setNext(Node *next) {
    _next = next;
}

template<typename T>
Node<T> *Node<T>::getPrev() const {
    return _prev;
}

template<typename T>
void Node<T>::setPrev(Node *prev) {
    _prev = prev;
}


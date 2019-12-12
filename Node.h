//
// Created by bg-tv on 3.12.19 г..
//

#ifndef HIERARCHY_OF_CONTAINERS_NODE_H
#define HIERARCHY_OF_CONTAINERS_NODE_H

template <typename T>
class Node {
    T _value;
    Node* _next;
    Node* _prev;
public:
    explicit Node(T value = 0, Node* prev = nullptr, Node* next = nullptr);

    T getValue() const;
    void setValue(T value);

    Node *getNext() const;
    void setNext(Node *next);

    Node *getPrev() const;
    void setPrev(Node *prev);
};


#endif //HIERARCHY_OF_CONTAINERS_NODE_H

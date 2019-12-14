//
// Created by bg-tv on 3.12.19 г..
//

#ifndef HIERARCHY_OF_CONTAINERS_NODE_H
#define HIERARCHY_OF_CONTAINERS_NODE_H


class Node {
    int _value;
    Node* _next;
    Node* _prev;
public:
    explicit Node(int value = 0, Node* prev = nullptr, Node* next = nullptr);
    ~Node();

    int getValue() const;
    void setValue(int value);

    Node *getNext() const;
    void setNext(Node *next);

    Node *getPrev() const;
    void setPrev(Node *before);
};


#endif //HIERARCHY_OF_CONTAINERS_NODE_H

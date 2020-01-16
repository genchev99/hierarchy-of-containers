//
// Created by bg-tv on 3.12.19 г..
//

#ifndef HIERARCHY_OF_CONTAINERS_BASECONTAINER_H
#define HIERARCHY_OF_CONTAINERS_BASECONTAINER_H


/* Todo make it to use template instead of integers */
using Condition = bool (*)(int);

#include <iostream>
#include <string>
#include <algorithm>
#include "Node.h"

class BaseContainer {
protected:
    Node* _head;
public:
    BaseContainer();
    ~BaseContainer();

    virtual void insert(int value) = 0;
    virtual std::string stringify() = 0;
    virtual int pop() = 0;

    void deleteAllNodes(Node* crr);

    bool member(int const& x);
    bool match(Condition condition);

    void filter(Condition condition);
    void shuffle();
    void sort();

    std::string stringifyValues();

    size_t getSize();

    /* Printing methods */
    void print();
    void printBackwards();
};


#endif //HIERARCHY_OF_CONTAINERS_BASECONTAINER_H

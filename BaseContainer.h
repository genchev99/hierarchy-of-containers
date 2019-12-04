//
// Created by bg-tv on 3.12.19 г..
//

#ifndef HIERARCHY_OF_CONTAINERS_BASECONTAINER_H
#define HIERARCHY_OF_CONTAINERS_BASECONTAINER_H

#include <iostream>
#include "Node.h"

class BaseContainer {
protected:
    Node* head;
public:
    BaseContainer();
    virtual void insert(int value) = 0;
    virtual int pop() = 0;

    bool member(int const& x);

    /* Printing methods */
    void print();
};


#endif //HIERARCHY_OF_CONTAINERS_BASECONTAINER_H

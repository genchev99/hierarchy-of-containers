//
// Created by bg-tv on 3.12.19 г..
//

#ifndef HIERARCHY_OF_CONTAINERS_BASECONTAINER_H
#define HIERARCHY_OF_CONTAINERS_BASECONTAINER_H

#include <iostream>
#include "Node.h"

class BaseContainer {
    Node* head;
    Node* tail;
public:
    BaseContainer();
    void insertEnd(int value);

    /* Printing methods */
    void print();
    void headToTail();
    void tailToHead();
};


#endif //HIERARCHY_OF_CONTAINERS_BASECONTAINER_H

//
// Created by bg-tv on 3.12.19 г..
//

#ifndef HIERARCHY_OF_CONTAINERS_MASTERCONTAINER_H
#define HIERARCHY_OF_CONTAINERS_MASTERCONTAINER_H


#include "MasterNode.h"

class MasterContainer {
    MasterNode* _head;
public:
    MasterContainer();

    bool contains(int x);

    void addContainer(BaseContainer* container = nullptr);
    void print();
};


#endif //HIERARCHY_OF_CONTAINERS_MASTERCONTAINER_H

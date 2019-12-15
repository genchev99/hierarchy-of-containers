//
// Created by bg-tv on 3.12.19 г..
//

#ifndef HIERARCHY_OF_CONTAINERS_MASTERCONTAINER_H
#define HIERARCHY_OF_CONTAINERS_MASTERCONTAINER_H

/* Todo make it to use template instead of integers */
using Condition = bool (*)(int);

#include <fstream>
#include "MasterNode.h"

class MasterContainer {
    MasterNode* _head;
public:
    MasterContainer();
    ~MasterContainer();

    MasterNode* getLowestContainer();

    bool contains(int x);
    bool matchAny(Condition condition);

    void deleteAllContainers(MasterNode* crr);
    void addContainer(BaseContainer* container = nullptr);
    void addElementToLowestContainer(int x);
    void filter(Condition condition);
    void save(std::string path);
    /* Printing methods */
    void print();
    void printBackwards();
};


#endif //HIERARCHY_OF_CONTAINERS_MASTERCONTAINER_H

//
// Created by pr3dat0r on 4.12.19 г..
//

#ifndef HIERARCHY_OF_CONTAINERS_LIST_H
#define HIERARCHY_OF_CONTAINERS_LIST_H


#include "BaseContainer.h"

class List: public BaseContainer {
public:
    void insert(int value) override;
    int pop() override;
};


#endif //HIERARCHY_OF_CONTAINERS_LIST_H

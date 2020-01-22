//
// Created by bg-tv on 3.12.19 г..
//

#ifndef HIERARCHY_OF_CONTAINERS_STACK_H
#define HIERARCHY_OF_CONTAINERS_STACK_H


#include "BaseContainer.h"

/* The stack is gonna use only the tail  */

class Stack: public BaseContainer {
public:
    Stack();

    char type() override;

    std::string stringify() override;
    void insert(int value) override;
    int pop() override;
};


#endif //HIERARCHY_OF_CONTAINERS_STACK_H

//
// Created by bg-tv on 3.12.19 г..
//

#ifndef HIERARCHY_OF_CONTAINERS_QUEUE_H
#define HIERARCHY_OF_CONTAINERS_QUEUE_H

#include <iostream>
#include <vector>

#include "BaseContainer.h"

class Queue: public BaseContainer {
public:
    Queue();

    void sort();
    std::string stringify() override;
    void insert(int value) override;
    int pop() override;
};


#endif //HIERARCHY_OF_CONTAINERS_QUEUE_H

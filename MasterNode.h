//
// Created by pr3dat0r on 4.12.19 г..
//

#ifndef HIERARCHY_OF_CONTAINERS_MASTERNODE_H
#define HIERARCHY_OF_CONTAINERS_MASTERNODE_H


#include "BaseContainer.h"

class MasterNode {
    BaseContainer* _container;
    MasterNode* _prev;
    MasterNode* _next;
public:
    MasterNode(BaseContainer* baseContainer = nullptr, MasterNode* prev = nullptr, MasterNode* next = nullptr);
    ~MasterNode();

    BaseContainer *getContainer() const;
    void setContainer(BaseContainer *container);

    MasterNode *getPrev() const;
    void setPrev(MasterNode *prev);

    MasterNode *getNext() const;
    void setNext(MasterNode *next);
};


#endif //HIERARCHY_OF_CONTAINERS_MASTERNODE_H

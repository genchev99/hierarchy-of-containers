#include <iostream>
#include "BaseContainer.h"
#include "Queue.h"

int main() {

    BaseContainer* baseContainer = new Queue();
    baseContainer->insert(1);
    baseContainer->insert(2);
    baseContainer->insert(3);

    baseContainer->print();
    baseContainer->tailToHead();

    std::cout << baseContainer->pop() << std::endl;

    baseContainer-> print();

    return 0;
}
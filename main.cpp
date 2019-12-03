#include <iostream>
#include "BaseContainer.h"
#include "Queue.h"
#include "Stack.h"

int main() {

    BaseContainer* baseContainer = new Stack();
    baseContainer->insert(1);
    baseContainer->insert(2);
    baseContainer->insert(3);

    baseContainer->tailToHead();

    std::cout << baseContainer->pop() << std::endl;

    baseContainer-> tailToHead();

    return 0;
}
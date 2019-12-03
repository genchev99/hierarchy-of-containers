#include <iostream>
#include "BaseContainer.h"

int main() {

    BaseContainer baseContainer;
    baseContainer.insertEnd(1);
    baseContainer.insertEnd(2);
    baseContainer.insertEnd(3);

    baseContainer.print();
    baseContainer.tailToHead();

    return 0;
}
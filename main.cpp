#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "BaseContainer.h"
#include "Queue.h"
#include "Stack.h"
#include "MasterContainer.h"
#include "List.h"

std::vector<std::string> split(const std::string & s, char c) {
    std::vector<std::string> split;

    std::string word;
    for (char ch : s) {
        if ((ch == c) && (!word.empty())) {
            split.push_back(word);
            word.clear();
        } else {
            word += ch;
        }
    }

    if (!word.empty()) {
        split.push_back(word);
    }

    return split;
}

/* Track on the tasks
 * 1 - done
 * 2 - semi done
 * 3 - done
 * 4 - done
 * 5 - done
 * 6 - done
 * 7 - done - office PC
 * 8 - done
 * 9 -
 * 10 -
 * 11 -
 * */

int main() {
    MasterContainer* masterContainer = new MasterContainer();

    /* Reading the file line by line and splitting it into string vector */
    std::ifstream in("/home/pr3dat0r/FMI_Projects/sdp/hierarchy-of-containers/containers.txt");
//    std::ifstream in("/home/bg-tv/CLionProjects/hierarchy-of-containers/containers.txt");
    std::vector<std::vector<std::string>> rawContainers;

    if (in) {
        std::string line;
        std::vector <std::string> vec;
        while (getline(in, line)) {
            for (const std::string & str : split(line, ' ')) {
                vec.push_back(str);
            }

            rawContainers.push_back(vec);
            vec.clear();
        }

        in.close();
    } else {
        std::cerr << "There is a problem with the given file" << std::endl;
    }

    for (std::vector<std::string> rawContainer : rawContainers) {
        std::string containerType = rawContainer.at(0);
        BaseContainer* baseContainer = nullptr;

        if (containerType == "s") {
            baseContainer = new Stack();
        } else if (containerType == "q") {
            baseContainer = new Queue();
        } else {
            baseContainer = new List();
        }

        for (int i = 1; i < rawContainer.size(); ++i) {
            baseContainer->insert(std::stoi(rawContainer.at(i)));
        }

        masterContainer->addContainer(baseContainer);
    }
    masterContainer->addElementToLowestContainer(111);
    masterContainer->addElementToLowestContainer(222);
    masterContainer->addElementToLowestContainer(333);
    std::cout << "Contains 333 " << masterContainer->contains(333) << std::endl;
    std::cout << "Contains 111 " << masterContainer->matchAny([](const int x) -> bool { return x == 111; }) << std::endl;
    masterContainer->print();
//    masterContainer->printBackwards();
    masterContainer->filter([](const int x) -> bool { return x%2 == 0; });
//
    masterContainer->print();

    delete masterContainer;

    return 0;
}
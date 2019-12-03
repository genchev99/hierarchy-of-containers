cmake_minimum_required(VERSION 3.15)
project(hierarchy_of_containers)

set(CMAKE_CXX_STANDARD 14)

add_executable(hierarchy_of_containers main.cpp MasterContainer.cpp MasterContainer.h BaseContainer.cpp BaseContainer.h Node.cpp Node.h Queue.cpp Queue.h Stack.cpp Stack.h List.cpp List.h MasterNode.cpp MasterNode.h)
cmake_minimum_required(VERSION 3.27)
project(LinkedListDictionary)

set(CMAKE_CXX_STANDARD 17)

add_executable(LinkedListDictionary main.cpp
        NODE.cpp
        NODE.h
        NodeProcess.cpp
        NodeProcess.h)

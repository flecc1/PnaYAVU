#pragma once

#include "LinkedList.h"

template <class T>
class Interface
{
    // private:
    //     LinkedList<T> items;

public:
    Interface() {};
    ~Interface() = default;

    void mainMenu();
    void editList();
    void editComputingMachine(T &device);
    // void sortItems();
};

#include "../src/Interface.tpp"

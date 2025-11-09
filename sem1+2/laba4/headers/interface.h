
#ifndef INTERFACE_H
#define INTERFACE_H

#include "student.h"
#include "prepod.h"
#include "komis.h"
#include "prepod_komis.h"
#include "human.h"
#include "ochered.h"
#include <iostream>
using namespace std;

template<class T>
class Interface
{
Ochered<T> och;

public:
    Interface(){};
    Interface(const Interface &other)
    {
        humans = other.humans;
        students = other.students;
        prepods = other.prepods;
        komisias = other.komisias;
        prepod_komis = other.prepod_komis;
    }
    ~Interface() = default;
    void menu();
    void fun();
    void edit(T &object);
    void sor_by_age();
};

#endif
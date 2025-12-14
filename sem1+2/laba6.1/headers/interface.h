#ifndef INTERFACE_H
#define INTERFACE_H

#include "student.h"
#include "prepod.h"
#include "komis.h"
#include "prepod_komis.h"
#include "human.h"
#include "ochered.h"
#include "file_txt.h"
#include "file_bin.h"
#include "excep_vvoda.h"
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

template<class T>
class Interface
{
    Ochered<T> och;
    
public:
    Interface(){};
    Interface(const Interface &other)
    {
        och = other.och;
    }
    ~Interface() = default;
    
    void menu();
    void fun();
    void editobj(T &object);
    void sortByAge();
};


#include "../cpp/interface.tpp"

#endif
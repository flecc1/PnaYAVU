#ifndef INTERFACE_H
#define INTERFACE_H

#include "LibraryItem.h"
#include "Book.h"
#include "AudioMaterial.h"
#include "AudioBook.h"
#include "StandardBook.h"
#include "EducationalAudio.h"
#include "ResearchPaper.h"
#include "ochered.h"
#include "file_txt.h"
#include "file_bin.h"
#include "excep.h"
#include "excep_vvoda.h"
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
        och = other.och;
    }
    ~Interface() = default;
    void menu();
    void fun();
    void editobj(T &object);
    void sortByYear(); 
};

#include "../cpp/interface.tpp"

#endif


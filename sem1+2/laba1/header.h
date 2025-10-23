

#ifndef HEADER_H
#define HEADER_H

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_BLUE "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_RESET "\x1b[0m"

#include <iostream>
#include <iomanip>
using namespace std;

class Mas
{
    int *arr;
    int size;

public:
    Mas()
    {
        arr = nullptr;
        this->size = 0;
    }
    Mas(int n)
    {
        this->arr = new int[n];
        if (this->arr == nullptr)
        {
            this->size = 0;
            this->arr = nullptr;
        }
        else
            this->size = n;
    }
    ~Mas()
    {
        delete[] arr;
    }
    Mas(const Mas &obj)
    {
        size = obj.size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = obj.arr[i];
        }
    }
    void vvod_mas();
    void show_mas();
    Mas merge(const Mas &obj);
    void sort();
    Mas operator=(const Mas &other);
};

void menu();

#endif
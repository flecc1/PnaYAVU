#ifndef OCHERED_H
#define OCHERED_H
#include "node.h"
#include <iostream>
#include <iomanip>
using namespace std;


template<class T>
class Ochered
{
    Node<T>* head;
    Node<T>* tail;
    int size;
    
public:
    Ochered()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    ~Ochered()
    {
        free();
    }
    
    Ochered(const Ochered &other)
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
        Node<T> *curr = other.head;
        while (curr != nullptr)
        {
            pushback(curr->value);
            curr = curr->next;
        }
    }
    Ochered &operator=(const Ochered &other);
    bool is_empty();
    void free();
    void pushback(const T& value);
    void pushfront(const T& value);
    bool remove_by_index(int index);
    bool remove(const T &value);
    T& operator[](int index);
    int getSize();
    void sortByAge();
    Ochered<T> findAllWithParameters(T example);
    template<typename U>
    friend ostream &operator<<(ostream &out, Ochered<U> &list);

    template<typename U>
    friend istream &operator>>(istream &in, Ochered<U> &list);

};
#include "../cpp/ochered.tpp"
#endif
#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

template<class T> class Ochered;

template<class T>
class Node
{
    T value;
    Node* prev;
    Node* next;

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, Ochered<U>& list);
    
public:

    friend class Ochered<T>;

    Node()
    {
        value = T();
        prev = nullptr;
        next = nullptr;
    }
    
    Node(const T& value)
    {
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
    
    Node(const Node& other)
    {
        this->value = other.value;
        this->prev = other.prev;
        this->next = other.next;
    }
    
    ~Node() {}
    
    T getValue() const { return value; }
    Node* getNext() const { return next; }
    Node* getPrev() const { return prev; }
};


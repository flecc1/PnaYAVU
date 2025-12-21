#ifndef OCHERED_H
#define OCHERED_H
#include "node.h"
#include <iterator>
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
    // Класс итератора
    class Iterator
    {
    private:
        Node<T>* current;
        
    public:
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    typedef std::forward_iterator_tag iterator_category;
    typedef std::ptrdiff_t difference_type;

        Iterator(Node<T>* node);
        
        // Префиксный инкремент
        Iterator& operator++();
        
        // Постфиксный инкремент
        Iterator operator++(int);
        
        // Разыменование
        T& operator*();
        
        // Доступ к членам
        T* operator->();
        
        // Сравнение
        bool operator==(const Iterator& other) const;
        
        bool operator!=(const Iterator& other) const;
            
        // Префиксный декремент
        Iterator& operator--();
            
        // Постфиксный декремент
        Iterator operator--(int);
    };
    
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
    bool is_empty() const;
    void free();
    void pushback(const T& value);
    void pushfront(const T& value);
    bool remove_by_index(int index);
    bool remove(const T &value);
    T& operator[](int index);
    const T& operator[](int index) const;
    int getSize() const;
    void sortByAge();
    Ochered<T> findAllWithParameters(T example);
    
    // Методы для работы с итераторами
    Iterator begin();
    
    Iterator end();

    template<typename U>
    friend ostream &operator<<(ostream &out, Ochered<U> &list);
    
    template<typename U>
    friend ostream &operator<<(ostream &out, const Ochered<U> &list);

    template<typename U>
    friend istream &operator>>(istream &in, Ochered<U> &list);
};

#include "../cpp/iterator.tpp"
#include "../cpp/ochered.tpp"
#endif


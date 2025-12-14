#pragma once
#include <iostream>
#include <functional>

template <class T>
class LinkedList;

template <class T>
class ListNode
{
private:
    T data;
    ListNode<T> *next;
    ListNode<T> *prev;

public:
    friend class LinkedList<T>;
    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const LinkedList<U> &list);
    ListNode() : next(nullptr), prev(nullptr) {}
    ListNode(T &v) : data(v), next(nullptr), prev(nullptr) {}
};

template <class T>
class LinkedList
{

private:
    ListNode<T> *head;
    ListNode<T> *tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    LinkedList(const LinkedList &other)
    {
        if (this != &other)
        {
            ListNode<T> *current = other.head;
            this->head = nullptr;
            this->tail = nullptr;
            while (current)
            {
                this->addToBack(current->data);
                current = current->next;
            }
        }
    }

    ~LinkedList()
    {
        clear();
    }

    void add(int index, T &value);
    void addToFront(T &value);
    void addToBack(T &value);

    void remove(int index);

    void clear();
    void print();

    bool contains(T &value);
    bool isEmpty();

    int getSize();
    T &get(int index);
    T &getFront();
    T &getBack();

    T * findFirstWithParameters(int predCount, std::function<bool(T &)> preds[]);
    T * findFirstWithParameters(T example);

    LinkedList<T> findAllWithParameters(int predCount, std::function<bool(T &)> preds[]);
    LinkedList<T> findAllWithParameters(T example);

    LinkedList<T> operator=(LinkedList<T> &other);
    T &operator[](int index);

    template <class U>
    friend std::ostream &operator<<(std::ostream &os, const LinkedList<U> &v);
    // friend std::istream &operator>>(std::istream &is, LinkedList &v);
};

#include "../src/LinkedList.tpp"
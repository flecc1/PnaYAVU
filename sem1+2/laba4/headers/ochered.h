#ifndef OCHERED_H
#define OCHERED_H

#include <iostream>
#include <iomanip>
using namespace std;

template<class T>
class Node
{
    T value;
    Node* prev;
    Node* next;
    
public:
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
//убрать гетеры сетеры из шаблонов
    T& getValue(); 
    const T& getValue() const;
    Node* getPrev() const; 
    Node* getNext() const;
    void setPrev(Node* newPrev); 
    void setNext(Node* newNext);
};
    template<class T>
    T& Node<T>::getValue() 
    { 
        return value; 
    }

    template<class T>
    const T& Node<T>::getValue() const
    { 
        return value; 
    }

    template<class T>
    Node<T>* Node<T>::getPrev() const
    { 
        return prev; 
    }

    template<class T>
    Node<T>* Node<T>::getNext() const
    { 
        return next; 
    }

    template<class T>
    void Node<T>::setPrev(Node<T>* newPrev)
    { 
        prev = newPrev; 
    }

    template<class T>
    void Node<T>::setNext(Node<T>* newNext)
    { 
        next = newNext; 
    }

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
            pushback(curr->getValue());
            curr = curr->getNext();
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
    
    friend ostream &operator<<(ostream &out, Ochered<T> &list);
    friend istream &operator>>(istream &in, Ochered<T> &list);
};

template<class T>
Ochered<T> &Ochered<T>::operator=(const Ochered &other)
{
    if (this != &other)
    {
        free();
        head = nullptr;
        tail = nullptr;
        size = 0;
        Node<T> *other_curr = other.head;
        while (other_curr != nullptr)
        {
            pushback(other_curr->getValue());
            other_curr = other_curr->getNext();
        }
    }
    return *this;
}

template<class T>
bool Ochered<T>::is_empty()
{
    return head == nullptr;
}

template<class T>
void Ochered<T>::free()
{
    Node<T> *curr = head;
    while (curr != nullptr)
    {
        Node<T> *next = curr->getNext();
        delete curr;
        curr = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<class T>
void Ochered<T>::pushback(const T& value)
{
    Node<T> *newNode = new Node<T>(value);
    if (head == nullptr)
        head = tail = newNode;
    else
    {
        newNode->setPrev(tail);
        tail->setNext(newNode);
        tail = newNode;
    }
    size++;
}

template<class T>
void Ochered<T>::pushfront(const T& value)
{
    Node<T> *newNode = new Node<T>(value);
    if (head == nullptr)
        head = tail = newNode;
    else
    {
        newNode->setNext(head);
        head->setPrev(newNode);
        head = newNode;
    }
    size++;
}

template<class T>
bool Ochered<T>::remove_by_index(int index)
{
    if (index < 0 || index >= size)
    {
        return false;
    }
    
    Node<T> *toDel = nullptr;
    
    if (index == 0)
    {
        toDel = head;
        head = head->getNext();
        if (head == nullptr)
            tail = nullptr;
        else
            head->setPrev(nullptr);
    }
    else if (index == (size - 1))
    {
        toDel = tail;
        tail = tail->getPrev();
        if (tail == nullptr)
            head = nullptr;
        else
            tail->setNext(nullptr);
    }
    else
    {
        Node<T> *curr = head;
        for (int i = 0; i < index; i++)
            curr = curr->getNext();
        toDel = curr;
        toDel->getPrev()->setNext(toDel->getNext());
        toDel->getNext()->setPrev(toDel->getPrev());
    }
    
    delete toDel;
    size--;
    return true;
}

template<class T>
bool Ochered<T>::remove(const T &value)
{
    if (head == nullptr)
        return false;
    
    Node<T> *curr = head;
    int index = 0;
    
    while (curr != nullptr)
    {
        if (curr->getValue() == value)
        {
            Node<T> *toDel = curr;
            
            if (curr == head)
            {
                head = head->getNext();
                if (head == nullptr)
                    tail = nullptr;
                else
                    head->setPrev(nullptr);
            }
            else if (curr == tail)
            {
                tail = tail->getPrev();
                if (tail == nullptr)
                    head = nullptr;
                else
                    tail->setNext(nullptr);
            }
            else
            {
                curr->getPrev()->setNext(curr->getNext());
                curr->getNext()->setPrev(curr->getPrev());
            }
            
            delete toDel;
            size--;
            return true;
        }
        
        curr = curr->getNext();
        index++;
    }
    return false;
}

template<class T>
T& Ochered<T>::operator[](int index)
{
    Node<T> *curr = head;
    for (int i = 0; i < index; i++)
        curr = curr->getNext();
    return curr->getValue();
}

template<class T>
int Ochered<T>::getSize()
{
    return size;
}

template<class T>
void Ochered<T>::sortByAge()
{
    if (head == nullptr || head->getNext() == nullptr)
    {
        return;
    }
    
    bool swapped;
    do
    {
        swapped = false;
        Node<T>* current = head;
        
        while (current->getNext() != nullptr)
        {
            if (current->getValue().get_age() > current->getNext()->getValue().get_age())
            {
                T temp = current->getValue();
                current->getValue() = current->getNext()->getValue();
                current->getNext()->getValue() = temp;
                swapped = true;
            }
            current = current->getNext();
        }
    } while (swapped);
}


template<class T>
ostream &operator<<(ostream &out, Ochered<T> &list)
{
    Node<T> *curr = list.head;
    for (int i = 0; i < list.size; i++)
    {
        out << curr->getValue() << endl; 
        curr = curr->getNext();
    }
    return out;
}

template<class T>
istream &operator>>(istream &in, Ochered<T> &list)
{
    int count;
    cout << "Введите количество элементов: ";
    in >> count;
    
    for (int i = 0; i < count; i++)
    {
        T value;
        cout << "Введите элемент " << i + 1 << ": ";
        in >> value;
        list.pushback(value);
    }
    return in;
}

#endif
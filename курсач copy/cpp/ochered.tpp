#include "../headers/ochered.h"

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
            pushback(other_curr->value);
            other_curr = other_curr->next;
        }
    }
    return *this;
}

template<class T>
bool Ochered<T>::is_empty() const
{
    return head == nullptr;
}

template<class T>
void Ochered<T>::free()
{
    Node<T> *curr = head;
    while (curr != nullptr)
    {
        Node<T> *next = curr->next;
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
        newNode->prev = tail;
        tail->next = newNode;
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
        newNode->next = head;
        head->prev = newNode;
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
        head = head->next;
        if (head == nullptr)
            tail = nullptr;
        else
            head->prev = nullptr;
    }
    else if (index == (size - 1))
    {
        toDel = tail;
        tail = tail->prev;
        if (tail == nullptr)
            head = nullptr;
        else
            tail->next = nullptr;
    }
    else
    {
        Node<T> *curr = head;
        for (int i = 0; i < index; i++)
            curr = curr->next;
        toDel = curr;
        toDel->prev->next = toDel->next;
        toDel->next->prev = toDel->prev;
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
        if (curr->value == value)
        {
            Node<T> *toDel = curr;
            
            if (curr == head)
            {
                head = head->next;
                if (head == nullptr)
                    tail = nullptr;
                else
                    head->prev = nullptr;
            }
            else if (curr == tail)
            {
                tail = tail->prev;
                if (tail == nullptr)
                    head = nullptr;
                else
                    tail->next = nullptr;
            }
            else
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
            }
            
            delete toDel;
            size--;
            return true;
        }
        
        curr = curr->next;
        index++;
    }
    return false;
}

template<class T>
T& Ochered<T>::operator[](int index)
{
    Node<T> *curr = head;
    for (int i = 0; i < index; i++)
        curr = curr->next;
    return curr->value;
}

template<class T>
const T& Ochered<T>::operator[](int index) const
{
    const Node<T> *curr = head;
    for (int i = 0; i < index; i++)
        curr = curr->next;
    return curr->value;
}

template<class T>
int Ochered<T>::getSize() const
{
    return size;
}

template<class T>
Ochered<T> Ochered<T>::findAllWithParameters(T example)
{
    Ochered<T> result;
    Node<T> *current = this->head;
    while (current)
    {
        if (current->value == example)
            result.pushback(current->value);
        current = current->next;
    }
    return result;
}

template<class T>
void Ochered<T>::sortByYear()
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }
    
    bool swapped;
    do
    {
        swapped = false;
        Node<T>* current = head;
        
        while (current->next != nullptr)
        {
            if (current->value.getYear() > current->next->value.getYear())
            {
                T temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

template <typename T>
ostream &operator<<(ostream &os, Ochered<T> &list)
{
    for (int i = 0; i < list.getSize(); i++)
    {
        os << list[i];
        if (i < list.getSize() - 1) 
        {
            os << endl;
        }
    }
    return os;
}

template <typename T>
istream &operator>>(istream &is, Ochered<T> &list)
{
    T value;
    if (is >> value)
        list.pushback(value);
    return is;
}


#include "../headers/LinkedList.h"
#include <functional>

template <class T>
void LinkedList<T>::add(int index, T &value)
{

    if (index > size || index < 0)
        return;

    if (index == 0)
        this->addToFront(value);

    else if (index == size)
        this->addToBack(value);
    else
    {

        ListNode<T> *node = new ListNode<T>();
        node->data = value;
        ListNode<T> *current = this->head;
        for (int i = 0; i < index; i++)
            current = current->next;

        node->prev = current->prev;
        node->next = current;
        current->prev->next = node;
        current->prev = node;
        size++;
    }
}

template <class T>
void LinkedList<T>::addToFront(T &value)
{
    ListNode<T> *node = new ListNode<T>(value);
    if (!head)
    {
        head = node;
        tail = node;
        node->prev = nullptr;
        node->next = nullptr;
    }
    else
    {
        head->prev = node;
        node->next = head;
        head = node;
    }
    size++;
}

template <class T>
void LinkedList<T>::addToBack(T &value)
{
    ListNode<T> *node = new ListNode<T>(value);
    if (!head)
    {
        head = node;
        tail = node;
        node->prev = nullptr;
        node->next = nullptr;
    }
    else
    {
        tail->next = node;
        node->prev = tail;
        node->next = nullptr;
        tail = node;
    }
    size++;
}

template <class T>
void LinkedList<T>::remove(int index)
{
    if (index > size || index < 0 || head == nullptr)
        return;

    ListNode<T> *current = head;
    for (int i = 0; i < index; i++)
        current = current->next;
    if (current->prev)
        current->prev->next = current->next;
    else
        head = current->next;
    if (current->next)
        current->next->prev = current->prev;

    delete current;
    this->size--;
}

template <class T>
void LinkedList<T>::clear()
{
    ListNode<T> *current = this->head;
    while (current)
    {
        ListNode<T> *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class T>
void LinkedList<T>::print()
{

    ListNode<T> *current = this->head;
    std::cout << "[";
    while (current)
    {
        std::cout << current->data;
        if (current->next)
            std::cout << ", ";
        current = current->next;
    }
    std::cout << "]";
}
template <class T>
bool LinkedList<T>::contains(T &value)
{
    ListNode<T> *current = this->head;
    while (current)
    {
        if (current->data == value)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <class T>
bool LinkedList<T>::isEmpty()
{
    return size == 0;
}

template <class T>
int LinkedList<T>::getSize()
{
    return size;
}

template <class T>
T &LinkedList<T>::get(int index)
{
    // if(index > = size || index <0)
    ListNode<T> *current = this->head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->data;
}

template <class T>
T &LinkedList<T>::getFront()
{
    return this->head->data;
}

template <class T>
T &LinkedList<T>::getBack()
{
    return this->tail->data;
}

template <class T>
T *LinkedList<T>::findFirstWithParameters(int predCount, std::function<bool(T &)> preds[])
{
    ListNode<T> *current = this->head;
    while (current)
    {
        bool matched = false;
        for (int i = 0; i < predCount; i++)
        {
            if (preds[i] == nullptr)
                continue;

            if (preds[i](current->data))
                // preds[i](current->data) - передаю current->data в лямбду, у std::fuction преегуржен оператор ()
                matched = true;
            else
            {
                matched = false;
                break;
            }
        }

        if (matched)
            return (&current->data);

        current = current->next;
    }
    return nullptr;
}

template <class T>
T *LinkedList<T>::findFirstWithParameters(T example)
{
    ListNode<T> *current = this->head;
    while (current)
    {
        if (current->data == example)
            return (&current->data);

        current = current->next;
    }
    return nullptr;
}

template <class T>
LinkedList<T> LinkedList<T>::findAllWithParameters(int predCount, std::function<bool(T &)> preds[])
{

    LinkedList<T> result;
    ListNode<T> *current = this->head;
    while (current)
    {
        bool matched = false;
        for (int i = 0; i < predCount; i++)
        {
            if (preds[i] == nullptr)
                continue;

            if (preds[i](current->data))
                // preds[i](current->data) - передаю current->data в лямбду, у std::fuction преегуржен оператор ()
                matched = true;
            else
            {
                matched = false;
                break;
            }
        }

        if (matched)
            result.addToBack(current->data);

        current = current->next;
    }
    return result;
}

template <class T>
LinkedList<T> LinkedList<T>::findAllWithParameters(T example)
{
    LinkedList<T> result;
    ListNode<T> *current = this->head;
    while (current)
    {
        if (current->data == example)
            result.addToBack(current->data);
        current = current->next;
    }
    return result;
}

template <class T>
LinkedList<T> LinkedList<T>::operator=(LinkedList<T> &other)
{

    if (this != &other)
    {
        this->clear();
        ListNode<T> *current = other.head;
        while (current)
        {
            this->addToBack(current->data);
            current = current->next;
        }
    }
    return *this;
}
template <class T>
T &LinkedList<T>::operator[](int index)
{
    ListNode<T> *current = this->head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->data;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T> &v)
{
    ListNode<T> *current = v.head;
    while (current)
    {
        os << current->data << std::endl;
        current = current->next;
    }
    return os;
}

// friend std::istream &operator>>(std::istream &is, LinkedList &v);
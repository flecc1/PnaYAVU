// Реализация методов класса Iterator
// Этот файл подключается в конце ochered.h после определения класса Ochered

// Iterator методы
template<class T>
Ochered<T>::Iterator::Iterator(Node<T>* node) : current(node) {}

template<class T>
typename Ochered<T>::Iterator& Ochered<T>::Iterator::operator++()
{
    if (current != nullptr)
        current = current->next;
    return *this;
}

template<class T>
typename Ochered<T>::Iterator Ochered<T>::Iterator::operator++(int)
{
    Iterator temp = *this;
    ++(*this);
    return temp;
}

template<class T>
T& Ochered<T>::Iterator::operator*()
{
    return current->value;
}

template<class T>
T* Ochered<T>::Iterator::operator->()
{
    return &(current->value);
}

template<class T>
bool Ochered<T>::Iterator::operator==(const Iterator& other) const
{
    return current == other.current;
}

template<class T>
bool Ochered<T>::Iterator::operator!=(const Iterator& other) const
{
    return current != other.current;
}

// Методы begin() и end() для Ochered
template<class T>
typename Ochered<T>::Iterator Ochered<T>::begin()
{
    return Iterator(head);
}

template<class T>
typename Ochered<T>::Iterator Ochered<T>::end()
{
    return Iterator(nullptr);
}

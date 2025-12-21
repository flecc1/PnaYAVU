// Унифицированный algorithms.h — содержит две глобальные функции:
// 1) findWithAllParameters(begin, end, example) — возвращает Ochered с элементами, равными example
// 2) sortByYear(begin, end) — сортирует диапазон по возрастанию getYear()

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iterator>
#include <utility>
#include <type_traits>
#include <utility>

template<typename T> class Ochered;

template<typename Iterator>
Ochered<typename std::iterator_traits<Iterator>::value_type>
findWithAllParameters(Iterator first, Iterator last, const typename std::iterator_traits<Iterator>::value_type &example)
{
    using T = typename std::iterator_traits<Iterator>::value_type;
    Ochered<T> result;
    for (; first != last; ++first)
    {
        if (*first == example)
            result.pushback(*first);
    }
    return result;
}

// Сортировка диапазона по возрастанию year (через getYear())
template<typename Iterator>
void sortByYear(Iterator first, Iterator last)
{
    if (first == last) return;
    bool swapped;
    do {
        swapped = false;
        Iterator it = first;
        Iterator next_it = it; ++next_it;
        for (; next_it != last; ++it, ++next_it) {
            auto &a = *it;
            auto &b = *next_it;
            if (a.getYear() > b.getYear()) {
                using std::swap;
                swap(a, b);
                swapped = true;
            }
        }
    } while (swapped);
}

#endif // ALGORITHMS_H

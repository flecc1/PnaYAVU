
#ifndef LABA7_ALGORITHMS_H
#define LABA7_ALGORITHMS_H

#include <iterator>

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

#endif 

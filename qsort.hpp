#ifndef QSORT_HPP
#define QSORT_HPP

#include <algorithm>
#include <functional>
#include <iterator>
#include <iostream>

namespace qs {
    template <typename ForwardIt, typename Compare>
    ForwardIt partition(ForwardIt first, ForwardIt last, Compare comp) {
        /* Lomuto partition */
        auto i = first;
        if (first != last) {
            auto x = *i; // pivot element
            for(auto j = first; ++j != last;) {
                if (*j <= x) {
                    ++i;
                    std::iter_swap(i, j);
                }
            }
            std::iter_swap(i, first);
        }
        return i;
    }

    template <typename ForwardIt, typename Compare = std::less<typename std::iterator_traits<ForwardIt>::value_type>>
    void qsort(ForwardIt first, ForwardIt last, Compare comp = Compare{}) {
        if (first != last) {
            auto q = qs::partition(first, last, comp);
            qsort(first, q, comp);
            qsort(++q, last, comp);
        }
    }
}

#endif

#pragma once

#include "../iterator_traits/iterator_traits.hpp"

namespace my_stl
{
template<typename Iterator>
class reverse_iterator {
public:
    using iterator_type = Iterator;
    using difference_type = typename iterator_traits<Iterator>::difference_type;
    using pointer = typename iterator_traits<Iterator>::pointer;
    using reference = typename iterator_traits<Iterator>::reference;
    using value_type = typename iterator_traits<Iterator>::value_type;

    reverse_iterator<Iterator>(iterator_type iterator) : m_iterator(iterator) {}
    
    reverse_iterator<Iterator>(const reverse_iterator<Iterator>& right): m_iterator(right.m_iterator) {}

    Iterator base() const {
        return m_iterator;
    }

    reference operator*() const {
        return *m_iterator;
    }

    reverse_iterator<Iterator> operator+(difference_type off) const {
        return reverse_iterator<Iterator>(m_iterator - off);
    }

    reverse_iterator<Iterator>& operator++() {
        m_iterator--;
        return *this;
    }

    reverse_iterator<Iterator> operator++(int) {
        reverse_iterator<Iterator> it = *this;
        ++(*this);
        return it;
    }

    reverse_iterator<Iterator>& operator+=(difference_type off) {
        m_iterator = m_iterator - off;
        return *this;
    }

    reverse_iterator<Iterator> operator-(difference_type off) const {
        return reverse_iterator<Iterator>(m_iterator + off);
    }

    reverse_iterator<Iterator>& operator--() {
        m_iterator++;
        return *this;
    }

    reverse_iterator<Iterator> operator--(int) {
        reverse_iterator<Iterator> it = *this;
        --(*this);
        return it;
    }

    reverse_iterator<Iterator>& operator-=(difference_type off) {
        m_iterator = m_iterator + off;
        return *this;
    }

    reference operator[](difference_type off) const {
        return *(m_iterator + off);
    }

    pointer operator->() const {
        return &(*m_iterator);
    }

    bool operator!=(const reverse_iterator<Iterator>& right) {
        return m_iterator != right.m_iterator;
    }
private:
    iterator_type m_iterator;
};
}

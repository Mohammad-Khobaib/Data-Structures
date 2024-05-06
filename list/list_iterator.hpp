#pragma once

#include "../utility/is_const.hpp"
#include "../utility/reference_selector.hpp"

namespace my_stl
{
template<typename List>
class list_iterator {
public:
    using value_type = typename List::value_type;
    using node = typename List::node;
    using pointer = typename List::pointer;
    using reference = typename reference_selector<List, is_const<List>::value>::reference;
    using difference_type = typename List::difference_type;
    using const_reference = typename List::const_reference;

    node* m_node;

    list_iterator<List>(node* m_node) : m_node(m_node) {}

    list_iterator<List>(const list_iterator<List>& right) : m_node(right.m_node) {}

    list_iterator<List>& operator++() {
        m_node = m_node -> next;
        return *this;
    }

    list_iterator<List> operator++(int) {
        list_iterator<List> copy = *this;
        ++(*this);
        return copy;
    }

    list_iterator<List>& operator--() {
        m_node = m_node -> prev;
        return *this;
    }

    list_iterator<List> operator--(int) {
        list_iterator<List> copy = *this;
        --(*this);
        return copy;
    }

    bool operator!=(const list_iterator<List>& right) const {
        return m_node != right.m_node;
    }

    reference operator*() const {
        return m_node -> data;
    }
};
}

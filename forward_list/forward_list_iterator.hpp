#pragma once

#include "../utility/reference_selector.hpp"
#include "../utility/is_const.hpp"

namespace my_stl
{
template<typename ForwardList>
class forward_list_iterator {
public:
    using value_type = typename ForwardList::value_type;
    using node = typename ForwardList::node;
    using pointer = value_type*;
    using reference = typename reference_selector<ForwardList, is_const<ForwardList>::value>::reference;

    // Constructor taking a pointer to a node
    forward_list_iterator<ForwardList>(node* m_node) : 
        m_node(m_node)
    {}

    // Inequality comparison operator
    bool operator!=(const forward_list_iterator<ForwardList>& right) const {
        return m_node != right.m_node;
    }

    // Equality comparison operator
    bool operator==(const forward_list_iterator<ForwardList>& right) const {
        return m_node == right.m_node;
    }

    // Prefix increment operator
    forward_list_iterator<ForwardList>& operator++() {
        m_node = m_node -> next;
        return *this;
    }

    // Postfix increment operator
    forward_list_iterator<ForwardList> operator++(int) {
        forward_list_iterator<ForwardList> it = *this;
        ++(*this);
        return it;
    }

    // Arrow operator
    pointer operator->() const {
        return &(m_node -> data);
    }

    // Dereference operator
    reference operator*() const {
        return m_node -> data;
    }
public:
    node* m_node; // Pointer to the current node
};
} // namespace my_stl

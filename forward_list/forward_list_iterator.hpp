#pragma once

namespace my_stl
{
template<typename forward_list>
class forward_list_iterator {
public:
    using value_type = typename forward_list::value_type;
    using node = typename forward_list::node;
    node* m_node;
    forward_list_iterator<forward_list>(node* m_node) : m_node(m_node) {}
    bool operator!=(const forward_list_iterator<forward_list>& right) {
        return m_node != right.m_node;
    }
    forward_list_iterator<forward_list>& operator++() {
        m_node = m_node -> next;
        return *this;
    }

    value_type& operator*() {
        return m_node -> data;
    }
};
}

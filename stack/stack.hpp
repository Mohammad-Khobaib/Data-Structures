#pragma once

#include "../forward_list/forward_list.hpp"

namespace my_stl
{
template<typename T>
class stack {
public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using size_type = unsigned int;
private:
    forward_list<T> m_forward_list;
    size_type m_size;
public:
    stack() : m_forward_list(), m_size(0) {}
    
    void push(const_reference val) {
        m_forward_list.push_front(val);
        m_size++;
    }

    void pop() {
        if (!m_forward_list.empty()) {
            m_forward_list.pop_front();
            m_size--;
        }
    }

    const_reference top() {
        return m_forward_list.front();
    }

    size_type size() const {
        return m_size;
    }

    bool empty() const {
        return m_forward_list.empty();
    }
};
}

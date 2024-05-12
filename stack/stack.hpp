#pragma once

#include "../forward_list/forward_list.hpp"
#include "../utility/move.hpp"

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
    // Default constructor
    stack<value_type>() : 
        m_forward_list(),
        m_size(0)
    {}
    
    // Copy constructor
    stack<value_type>(const stack<value_type>& right) :
        m_forward_list(right.m_forward_list),
        m_size(right.m_size)
    {}

    // Move constructor
    stack<value_type>(stack<value_type>&& right) :
        m_forward_list(move(right.m_forward_list)),
        m_size(right.m_size)
    {
        right.m_size = 0;
    }

    // Inserts a new element at the top of the stack.
    void push(const_reference val) {
        m_forward_list.push_front(val);
        m_size++;
    }

    // Removes the top element from the stack.
    void pop() {
        if (!m_forward_list.empty()) {
            m_forward_list.pop_front();
            m_size--;
        }
    }

    // Returns a reference to the top element of the stack
    reference top() {
        return m_forward_list.front();
    }

    // Returns a const reference to the top element of the stack
    const_reference top() const {
        return m_forward_list.front();
    }

    // Returns the number of elements in the stack.
    size_type size() const {
        return m_size;
    }

    // Returns the number of elements in the stack.
    bool empty() const {
        return m_forward_list.empty();
    }

    // Compares if the current stack is not equal to the given stack.
    bool operator!=(const stack<value_type>& right) const {
        return m_forward_list != right.m_forward_list;
    }

    // Compares if the current stack is equal to the given stack.
    bool operator==(const stack<value_type>& right) const {
        return m_forward_list == right.m_forward_list;
    }
};
} // namespace my_stl

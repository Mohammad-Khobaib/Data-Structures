#pragma once

#include "../list/list.hpp"

namespace my_stl
{
template<typename T>
class queue {
public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using size_type = unsigned int;

    void push(const_reference val) {
        m_list.push_back(val);
    }

    void pop() {
        if (!m_list.empty())
            m_list.pop_front();
    }

    const_reference front() const {
        return m_list.front();
    }

    reference front() {
        return m_list.front();
    }

    const_reference back() const {
        return m_list.back();
    }

    reference back() {
        return m_list.back();
    }

    size_type size() const {
        return m_list.size();
    }
    
    bool empty() const {
        return m_list.empty();
    }
private:
    list<T> m_list;
};
}

#pragma once

#include "../list/list.hpp"

template<typename T>
class stack {
private:
    list<T> m_list;
public:
    void push(const T& element) {
        m_list.push_back(element);
    }
    void pop() {
        if (!m_list.empty())
            m_list.pop_back();
    }
    const T& top() {
        if (!m_list.empty())
            return m_list.back();
        throw T();
    }
    unsigned int size() const {
        return m_list.size();
    }
    bool empty() const {
        return m_list.empty();
    }
};

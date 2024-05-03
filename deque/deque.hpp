#pragma once

#include <initializer_list>

#include "deque_iterator.hpp"
#include "../iterators/reverse_iterator/reverse_iterator.hpp"
#include "../exceptions/out_of_range/out_of_range.hpp"

namespace my_stl
{
template<typename T>
class deque {
public:
    using size_type = unsigned int;
    using value_type = T;
    using iterator = deque_iterator<deque<value_type>>;
    using const_iterator = const iterator;
    using pointer = value_type*;
    using reference = value_type&;
    using const_pointer = const value_type*;
    using const_reference = const T&;
    using difference_type = long int;
    using const_reverse_iterator = reverse_iterator<const_iterator>;
    using reverse_iterator = reverse_iterator<iterator>;
private:
    value_type* m_data;
    size_type m_size;
    size_type m_capacity;
    size_type m_front_idx;
    size_type m_back_idx;

    void expand_capacity() {
        if (m_size == m_capacity) {
            if (m_size == 0)
                re_allocate(1);
            else
                re_allocate(m_size * 2);
        }
    }

    void re_allocate(size_type new_capacity) {
        value_type* new_data = new value_type[new_capacity]{value_type()};
        
        for (size_type i = 0; i < m_back_idx; i++) {
            new_data[i] = (value_type&&) m_data[i];
        }

        for (size_type i = m_front_idx + 1; i < m_capacity; i++) {
            new_data[i + m_capacity] = (value_type&&) m_data[i];
        }

        delete[] m_data;
        m_data = new_data;
        m_front_idx = m_front_idx + m_capacity;
        m_capacity = new_capacity;
    }

public:
    deque() : 
        m_data(nullptr),
        m_size(0),
        m_capacity(0),
        m_front_idx(0),
        m_back_idx(0)
    {}

    deque(size_type count) : 
        m_data(new value_type[count]{value_type()}),
        m_size(0), 
        m_capacity(count), 
        m_front_idx(count - 1),
        m_back_idx(0)
    {}

    deque(const std::initializer_list<value_type>& values)  : 
        m_data(new value_type[values.size()]),
        m_size(values.size()),
        m_capacity(values.size()),
        m_front_idx(-1),
        m_back_idx(0)
    {
        size_type i = 0;
        for (const value_type& it : values) {
            m_data[i] = it;
            i++;
        }
    }

    ~deque() {
        delete m_data;
    }

    void push_back(const_reference val) {
        expand_capacity();
        m_data[m_back_idx] = val;
        m_back_idx++;
        m_size++;
    }

    void push_back(value_type&& val) {
        expand_capacity();
        m_data[m_back_idx] = (value_type&&) val;
        m_back_idx++;
        m_size++;
    }

    void push_front(const_reference val) {
        expand_capacity();
        m_data[m_front_idx] = val;
        m_front_idx--;
        m_size++;
    }

    void push_front(value_type&& val) {
        expand_capacity();
        m_data[m_front_idx] = (value_type&&) val;
        m_front_idx--;
        m_size++;
    }

    void pop_front() {
        m_front_idx = m_front_idx + 1;
        m_data[m_front_idx] = value_type();
        m_size--;
    }

    void pop_back() {
        m_back_idx = m_back_idx - 1;
        m_data[m_back_idx] = value_type();
        m_size--;
    }

    void emplace_back(value_type&& val) {
        expand_capacity();
        m_data[m_back_idx] = (value_type&&) val;
        m_back_idx++;
        m_size++;
    }
    
    void emplace_front(value_type&& val) {
        expand_capacity();
        m_data[m_front_idx] = (value_type&&) val;
        m_front_idx--;
        m_size++;
    }

    reference at(size_type off) {
        if (off >= m_size) {
            throw out_of_range("Error: Deque index out of range. Please ensure the index is within the valid range.");
        }
        return m_data[(m_front_idx + 1 + off) % m_capacity];
    }

    const_reference at(size_type off) const {
        if (off >= m_size) {
            throw out_of_range("Error: Deque index out of range. Please ensure the index is within the valid range.");
        }
        return m_data[(m_front_idx + 1 + off) % m_capacity];
    }

    reference back() {
        return m_data[(m_front_idx + m_size) % m_capacity];
    }

    const_reference back() const {
        return m_data[m_back_idx - 1];
    }

    iterator begin() {
        return iterator(0, m_front_idx, m_capacity, m_data);
    }

    const_iterator begin() const {
        return iterator(0, m_front_idx, m_capacity, m_data);
    }

    const_iterator cbegin() const {
        return iterator(m_front_idx, m_capacity, 0, m_data);
    }

    const_iterator cend() const {
        return iterator(m_front_idx, m_capacity, m_size, m_data);
    }

    const_reverse_iterator crbegin() const {
        return const_reverse_iterator(iterator(m_size - 1, m_front_idx, m_capacity, m_data));
    }

    const_reverse_iterator crend() const {
        return const_reverse_iterator(iterator(-1, m_front_idx, m_capacity, m_data));
    }

    bool empty() const {
        return m_size == 0;
    }

    iterator end() {
        return iterator(m_size, m_front_idx, m_capacity, m_data);
    }

    const_iterator end() const {
        return iterator(m_size, m_front_idx, m_capacity, m_data);
    }

    reference front() {
        return m_data[m_front_idx + 1];
    }

    const_reference front() const {
        return m_data[m_front_idx + 1];
    }

    size_type max_size() const {
        return m_capacity;
    }

    reference operator[](size_type off) {
        return m_data[(m_front_idx + 1 + off) % m_capacity];
    }

    const_reference operator[](size_type off) const {
        return m_data[(m_front_idx + 1 + off) % m_capacity];
    }

    reverse_iterator rbegin() {
        return reverse_iterator(iterator(m_size - 1, m_front_idx, m_capacity, m_data));
    }

    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(iterator(m_size - 1, m_front_idx, m_capacity, m_data));
    }

    reverse_iterator rend() {
        return reverse_iterator(iterator(-1, m_front_idx, m_capacity, m_data));
    }

    const_reverse_iterator rend() const {
        return const_reverse_iterator(iterator(-1, m_front_idx, m_capacity, m_data));
    }

    void shrink_to_fit() {
        if (m_capacity > m_size) 
            re_allocate(m_size);
    }

    size_type size() const {
        return m_size;
    }

    void clear() {
        for (size_type i = 0; i < m_size; i++) {
            m_data[(m_front_idx + 1 + i) % m_capacity] = value_type();
        }
        m_front_idx = m_size - 1;
        m_back_idx = 0;
        m_size = 0;
    }

    iterator emplace(const_iterator position, value_type&& val) {
        iterator it = begin();
        size_type off = 0;
        while (it != position) {
            ++off;
            ++it;
        }
        value_type temp = (value_type&&) *(end() - 1);
        for (iterator it = end() - 1; it != position; --it) {
            *it = (value_type&&) *(it - 1);
        }
        *it = val;
        expand_capacity();
        m_data[m_back_idx] = (value_type&&) temp;
        m_back_idx++;
        m_size++;
        return begin() + off;
    }
    
    iterator erase(iterator position) {
        iterator copt_it = position;
        if (m_back_idx > 0) {
            while (position != end()) {
                *position = (value_type&&) *(position + 1);
                ++position;
            }
            m_back_idx--;
            m_data[m_back_idx] = value_type();
        } else {
            while (position != begin())
            {
                *position = *(position - 1);
                --position;
            }
            m_front_idx++;
            m_data[m_front_idx] = value_type();
        }
        m_size--;
        return copt_it;
    }

};
}

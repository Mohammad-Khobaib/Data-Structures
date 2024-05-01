#pragma once

#include <initializer_list>

#include "../iterators/reverse_iterator/reverse_iterator.hpp"
#include "../exceptions/out_of_range/out_of_range.hpp"

namespace my_stl
{
template<typename T>
class vector {
public:
    using iterator = T*;
    using pointer = T*;
    using reference = T&;
    using value_type = T;
    using size_type = unsigned int;
    using difference_type = long int;
    using const_reference = const T&;
    using const_pointer = const T*;
    using const_iterator = const T*;
    using const_reverse_iterator = reverse_iterator<const_iterator>;
    using reverse_iterator = reverse_iterator<iterator>;
private:
    value_type* m_data;
    size_type m_size;
    size_type m_capacity;

    void expand_capacity() {
        if (m_size == m_capacity) {
            if (m_size == 0)
                re_allocate(1);
            else
                re_allocate(m_size * 2);
        }
    }

    void re_allocate(size_type new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_type i = 0; i < m_size; i++) {
            new_data[i] = (T&&) m_data[i];
        }
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }
public:
    vector<value_type>() : m_data(nullptr), m_size(0), m_capacity(0) {}
    
    explicit vector<value_type>(size_type count) : m_data(new value_type[count]{value_type()}), m_size(count), m_capacity(count) {}
    
    vector<value_type>(std::initializer_list<value_type>& values) : m_data(new value_type[values.size()]), m_size(values.size()), m_capacity(values.size()) {
        for (size_type i = 0; i < values.size(); i++) {
            m_data[i] = values[i];
        }
    }
    
    explicit vector<value_type>(size_type count, const_reference value): m_data(new value_type[count]), m_size(count), m_capacity(count) {
        for (size_type i = 0; i < m_size; i++) {
            m_data[i] = value;
        }
    }

    vector<value_type>(const vector<value_type>& right): m_data(nullptr), m_size(right.m_size), m_capacity(right.m_size) {
        m_data = new value_type[right.m_size];
        for (size_type i = 0; i < right.m_size; i++) {
            m_data[i] = right[i];
        }
    }

    vector<value_type>(vector<value_type>&& right): m_data(right.m_data), m_size(right.m_size), m_capacity(right.m_capacity) {
        right.m_data = nullptr;
        right.m_size = 0;
        right.m_capacity = 0;
    }

    ~vector<value_type>() {
        delete[] m_data;
        m_size = 0;
        m_capacity = 0;
    }

    reference at(size_type position) {
        if (position < 0 || position >= m_size) {
            throw out_of_range("Error: Array index out of range. Please ensure the index is within the valid range.");
        }
        return m_data[position];
    }

    const_reference at(size_type position) const {
        if (position < 0 || position >= m_size) {
            throw out_of_range("Error: Array index out of range. Please ensure the index is within the valid range.");
        }
        return m_data[position];
    }

    reference back() {
        return m_data[m_size - 1];
    }

    const_reference back() const {
        return m_data[m_size - 1];
    }

    const_iterator begin() const {
        return &m_data[0];
    }

    iterator begin() {
        return &m_data[0];
    }

    size_type capacity() const {
        return m_capacity;
    }

    const_iterator cbegin() const {
        return &m_data[0];
    }

    const_iterator cend() const {
        return &m_data[m_size];
    }

    void clear() {
        for (size_type i = 0; i < m_size; i++) {
            m_data[i] = value_type();
        }
        m_size = 0;
    }

    const_reverse_iterator crbegin() const {
        return reverse_iterator(&m_data[m_size - 1]);
    }

    const_reverse_iterator crend() const {
        return reverse_iterator(&m_data[-1]);
    }

    const_pointer data() const {
        return &m_data[0];
    }

    pointer data() {
        return &m_data[0];
    }
    
    template<typename...  Args>
    iterator emplace(const_iterator position, Args&&... args) {
        if (m_size == 0) {
            re_allocate(1);
            m_data[0] = value_type(args...);
            m_size++;
            return begin();
        }
        value_type temp = (value_type&&) m_data[m_size - 1];
        iterator it = end() - 2;
        while (it >= position) {
            *(it + 1) = (value_type&&) *it;
            --it;
        }
        *(it + 1) = value_type(args...);
        if (m_size == m_capacity) {
            re_allocate(m_size + 1);
        }
        m_data[m_size] = (value_type&&) temp;
        m_size++;
        return it;
    }

    template<typename... Args>
    void emplace_back(Args&&... args) {
        expand_capacity();
        m_data[m_size] = value_type(args...);
        m_size++;
    }

    bool empty() const {
        return m_size == 0;
    }

    iterator end() {
        return &m_data[m_size];
    }

    const_iterator end() const {
        return &m_data[m_size];
    }

    iterator erase(const_iterator position) {
        iterator it = begin();
        while (it <= position) {
            ++it;
        }
        iterator copy_it = it;
        while (it < end()) {
            *(it - 1) = (value_type&&) *it;
            ++it;
        }
        m_size--;
        return copy_it;
    }

    iterator erase(const_iterator first, const_iterator last) {
        iterator first_iter = begin();
        while (first_iter < first) {
            ++first_iter;
        }
        iterator last_iter = first_iter;
        while (last_iter < last) {
            ++last_iter;
        }
        iterator copy_first_iter = first_iter;
        while (last_iter < end()) {
            *first_iter = (value_type&&) *last_iter;
            ++last_iter;
            ++first_iter;
        }

        m_size = m_size - (last_iter - first_iter);
        return copy_first_iter;
    }

    reference front() {
        return m_data[0];
    }

    const_reference front() const {
        return m_data[0];
    }

    size_type max_size() const {
        return m_capacity;
    }

    reference operator[](size_type position) {
        return m_data[position];
    }

    const_reference operator[](size_type position) const {
        return m_data[position];
    }

    reverse_iterator rbegin() {
        return reverse_iterator(&m_data[m_size]);
    }

    const_reverse_iterator rbegin() const {
        return reverse_iterator(&m_data[m_size]);
    }

    reverse_iterator rend() {
        return reverse_iterator(&m_data[-1]);
    }

    const_reverse_iterator rend() const {
        return reverse_iterator(&m_data[-1]);
    }

    void reserve(size_type count) {
        if (count > m_capacity) {
            re_allocate(count);
        }
    }

    void resize(size_type new_size) {
        if (m_size == new_size)
            return;
        if (new_size < m_size) {
            for (size_type i = new_size; i < m_size; i++) {
                m_data[i] = value_type();
            }
        } else {
            if (new_size > m_capacity) 
                re_allocate(new_size);
        }
        m_size = new_size;
    }

    size_type size() const {
        return m_size;
    }

    void push_back(const_reference value) {
        expand_capacity();
        m_data[m_size] = value;
        m_size++;
    }

    void push_back(T&& value) {
        expand_capacity();
        m_data[m_size] = (T&&) value;
        m_size++;
    }

    void pop_back() {
        m_size--;
        m_data[m_size] = value_type();
    }

    void shrink_to_fit() {
        if (m_capacity > m_size)
            re_allocate(m_size);
    }

    vector<value_type>& operator=(const vector<value_type>& right) {
        clear();
        re_allocate(right.m_size);
        for (size_type i = 0; i < right.m_size; i++) {
            m_data[i] = right[i];
        }
        m_size = right.m_size;
    }
};
}

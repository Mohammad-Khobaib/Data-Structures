#pragma once

#include <iostream>

#include "../exceptions/out_of_range/out_of_range.hpp"
#include "../iterators/reverse_iterator/reverse_iterator.hpp"
#include "../utility/numeric_limits.hpp"

namespace my_stl
{
class string {
public:
    using size_type = unsigned int;
    using pointer = char*;
    using const_pointer = const char*;
    using reference = char&;
    using const_reference = const char&;
    using iterator = char*;
    using const_iterator = const char*;
    using const_reverse_iterator = reverse_iterator<const_iterator>;
    using reverse_iterator = reverse_iterator<iterator>;
    
    string(): m_data(new char[16]), m_size(0), m_capacity(15) {
        m_data[0] = '\0';
    }

    string(const char* data) : m_data(nullptr), m_size(strlen(data)), m_capacity(0) {
        if (m_size <= 15) {
            m_data = new char[16];
            m_capacity = 15;
        }
        else {
            m_data = new char[m_size + 1];
            m_capacity = m_size;
        }
        memcpy(m_data, data, m_size);
        m_data[m_size] = '\0';
    }

    string(const string& right) : m_data(nullptr), m_size(right.m_size), m_capacity(right.m_capacity) {
        m_data = new char[m_size + 1];
        memcpy(m_data, right.m_data, m_size + 1);
    }

    ~string() {
        delete[] m_data;
    }

    const_reference at(size_type off) const {
        if (off >= m_size) {
            throw out_of_range("Error: string index out of range. Please ensure the index is within the valid range.");
        }
        return m_data[off];
    }

    reference at(size_type off) {
        if (off >= m_size) {
            throw out_of_range("Error: string index out of range. Please ensure the index is within the valid range.");
        }
        return m_data[off];
    }

    const_pointer data() const {
        return &m_data[0];
    }

    pointer data() {
        return &m_data[0];
    }

    const_iterator begin() const {
        return &m_data[0];
    }

    iterator begin() {
        return &m_data[0];
    }

    const_iterator cbegin() const {
        return &m_data[0];
    }

    const_iterator cend() const {
        return &m_data[m_size];
    }

    const_iterator end() const {
        return &m_data[m_size];
    }

    iterator end() {
        return &m_data[m_size];
    }

    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(&m_data[m_size - 1]);
    }

    reverse_iterator rbegin() {
        return reverse_iterator(&m_data[m_size - 1]);
    }

    const_reverse_iterator rend() const {
        return const_reverse_iterator(&m_data[-1]);
    }

    reverse_iterator rend() {
        return reverse_iterator(&m_data[-1]);
    }

    const_reverse_iterator crbegin() const {
        return const_reverse_iterator(&m_data[m_size - 1]);
    }

    const_reverse_iterator crend() const {
        return const_reverse_iterator(&m_data[-1]);
    }

    void clear() {
        m_size = 0;
        m_data[0] = '\0';
    }

    size_type size() const {
        return m_size;
    }

    size_type capacity() const {
        return m_capacity;
    }

    string& append(const_pointer ptr) {
        size_type size = strlen(ptr);
        expand_capacity(size);
        memcpy(m_data + m_size, ptr, size);
        m_size = m_size + size;
        m_data[m_size] = '\0';
        return *this;
    }

    string& append(const_pointer ptr, size_type count) {
        expand_capacity(count);
        memcpy(m_data + m_size, ptr, count);
        m_size = m_size + count;
        m_data[m_size] = '\0';
        return *this;
    }

    string& append(const string& str, size_type off, size_type count) {
        append(str.m_data + off, count);
        return *this;
    }

    string& append(const string& str) {
        append(str.m_data);
        return *this;
    }

    string& append(size_type count, char value) {
        expand_capacity(count);
        for (size_type i = 0; i < count; i++) {
            m_data[m_size + i] = value;
        }
        m_size = m_size + count;
        m_data[m_size] = '\0';
        return *this;
    }

    const_pointer c_str() const {
        return m_data;
    }

    bool empty() const {
        return m_size == 0;
    }

    iterator erase(iterator position) {
        iterator it = position;
        while (*it != '\0') {
            *it = *(it + 1);
            it++;
        }
        m_size--;
        return position;
    }

    iterator erase(iterator first, iterator last) {
        iterator copy_first = first;
        while (*last != '\0') {
            *first= *last;
            first++;
            last++;
        }
        *first = '\0';
        return copy_first;
    }

    string& erase(size_type off, size_type count) {
        erase(&m_data[off], &m_data[off + count]);
        return *this;
    }

    size_type find(char value, size_type off = 0) {
        size_type i = off;
        while (m_data[i] != '\0') {
            if (m_data[i] == value)
                return i;
            i++;
        }
        return UINT_MAX;
    }

    const_reference front() const {
        return m_data[0];
    }

    reference front() {
        return m_data[0];
    }

    void reserve(size_type count) {
        if (count > m_capacity) {
            expand_capacity(count - (m_capacity - m_size));
        }
    }

    void shrink_to_fit() {
        if (m_capacity > m_size && m_capacity != 15)
            expand_capacity(m_size);
    }
private:
    char* m_data;
    size_type m_size;
    size_type m_capacity;

    void expand_capacity(size_type size) {
        if (size > (m_capacity - m_size)) {
            if (size <= m_size)
                re_allocate(m_size * 2);
            else
                re_allocate(m_size + size);
        }
    }

    void re_allocate(size_type new_capacity) {
        char* new_data = new char[new_capacity + 1];
        for (size_type i = 0; i <= m_size; i++) {
            new_data[i] = m_data[i];
        }
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }

    void memcpy(char* dest, const char* src, size_type n) {
        if ((dest - src) < n) {
            for (int i = n - 1; i >= 0; i--) {
                dest[i] = src[i];
            }
        } else {
            for (size_type i = 0; i < n; i++) {
                dest[i] = src[i];
            }
        }
    }

    size_type strlen(const char* str) {
        size_type length = 0;
        while (*str != '\0') {
            length++;
            str++;
        }
        return length;
    }
};

std::ostream& operator<<(std::ostream& stream, const string& str) {
    stream << str.data();
    return stream;
}
}

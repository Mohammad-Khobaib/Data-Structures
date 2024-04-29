#pragma once

#include "../iterators/reverse_iterator/reverse_iterator.hpp"
#include "../exceptions/out_of_range/out_of_range.hpp"

namespace my_stl {
typedef unsigned int size_type;

template<typename T, size_type N>
class array {
private:
    T m_data[N];

public:
    using const_iterator = const T*;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using const_reverse_iterator = reverse_iterator<const_iterator>;
    using difference_type = long int;
    using iterator = T*;
    using value_type = T;
    using size_type = unsigned int;
    using reverse_iterator = reverse_iterator<iterator>;
    
    template<typename... Args>
    array<T, N>(Args&&... args) : m_data{(Args&&) args...} {}

    array<T, N>(const array<T, N>& right) {
        for (size_type i = 0; i < N; i++) {
            m_data[i] = right.m_data[i];
        }
    }

    reference at(size_type off) {
        if (off < 0 || off >= N) {
            throw out_of_range("Error: Array index out of range. Please ensure the index is within the valid range.");
        }
        return m_data[off];
    }

    constexpr const_reference at(size_type off) const {
        if (off < 0 || off >= N) {
            throw out_of_range("Error: Array index out of range. Please ensure the index is within the valid range.");
        }
        return m_data[off];
    }

    reference back() {
        return m_data[N -1];
    }

    constexpr const_reference back() const {
        return m_data[N - 1];
    }

    iterator begin() {
        return &m_data[0];
    }

    const_iterator begin() const {
        return &m_data[0];
    }

    const_iterator cbegin() const {
        return &m_data[0];
    }

    const_iterator cend() const {
        return &m_data[N];
    }
    
    const_reverse_iterator crbegin() const {
        return const_reverse_iterator(&m_data[N - 1]);
    }

    const_reverse_iterator crend() const {
        return const_reverse_iterator(&m_data[-1]);
    }

    pointer data() {
        return &m_data[0];
    }

    const_pointer data() const {
        return &m_data[0];
    }

    constexpr bool empty() const {
        return N == 0;
    }

    iterator end() {
        return &m_data[N];
    }

    const_iterator end() const {
        return &m_data[N];
    }

    void fill(const_reference val) {
        for (size_type i = 0; i < N; i++) {
            m_data[i] = val;
        }
    }

    reference front() {
        return m_data[0];
    }

    constexpr const_reference front() const {
        return m_data[0];
    }

    constexpr size_type max_size() const {
        return N;
    }

    reference operator[](size_type off) {
        return m_data[off];
    }

    constexpr const_reference operator[](size_type off) const {
        return m_data[off];
    }
    
    array<T, N> operator=(const array<T, N>& right) {
        for (size_type i = 0; i < N; i++) {
            m_data[i] != right.m_data[i];
        }
        return *this;
    }
    
    reverse_iterator rbegin() {
        return reverse_iterator(&m_data[N - 1]);
    }

    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(&m_data[N - 1]);
    }

    reverse_iterator rend() {
        return reverse_iterator(&m_data[-1]);
    }

    const_reverse_iterator rend() const {
        return const_reverse_iterator(&m_data[-1]);
    }

    constexpr size_type size() const {
        return N;
    }

    void swap(array<T, N>& right) {
        for (size_type i = 0; i < N; i++) {
            value_type temp = m_data[i];
            m_data[i] = right.m_data[i];
            right.m_data[i] = temp;
        }
    }
};
}

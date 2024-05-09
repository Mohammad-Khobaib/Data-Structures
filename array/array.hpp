#pragma once

#include<initializer_list>

#include "../iterators/reverse_iterator/reverse_iterator.hpp"
#include "../exceptions/out_of_range/out_of_range.hpp"
#include "../utility/move.hpp"
#include "../utility/typedefs.hpp"
#include "../utility/move.hpp"
#include "../utility/lexicographical_compare.hpp"

namespace my_stl {
template<typename T, size_type N>
class array {
public:
    using value_type = T;
    using const_iterator = const value_type*;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using reference = value_type&;
    using const_reference = const value_type&;
    using const_reverse_iterator = reverse_iterator<const_iterator>;
    using difference_type = long int;
    using iterator = value_type*;
    using size_type = unsigned int;
    using reverse_iterator = reverse_iterator<iterator>;

    // Default constructor
    constexpr array<T, N>() {
        fill(value_type());
    }

    // Constructor taking an std::initializer_list
    constexpr array<T, N>(const std::initializer_list<T>& values) {
        size_type i = 0;
        for (const_reference value: values) {
            if (i < N) {
                m_data[i] = value;
                i++;
            }
        }
        while (i < N) {
            m_data[i] = value_type();
            i++;
        }
    }

    // Copy constructor
    array<T, N>(const array<T, N>& right) {
        for (size_type i = 0; i < N; i++) {
            m_data[i] = right.m_data[i];
        }
    }

    // Move constructor
    array<T, N>(array<T, N>&& right) {
        for (size_type i = 0; i < N; i++) {
            m_data[i] = move(right.m_data[i]);
            right.m_data[i] = value_type{};
        }
    }

    // Returns a reference to the element at the specified index, performing bounds checking.
    reference at(size_type off) {
        if (off < 0 || off >= N) {
            throw out_of_range("Error: Array index out of range. Please ensure the index is within the valid range.");
        }
        return m_data[off];
    }

    // Returns a const_reference to the element at the specified index, performing bounds checking.
    constexpr const_reference at(size_type off) const {
        if (off < 0 || off >= N) {
            throw out_of_range("Error: Array index out of range. Please ensure the index is within the valid range.");
        }
        return m_data[off];
    }

    // Returns a reference to the last element
    reference back() {
        return m_data[N -1];
    }

    // Returns a const_reference to the last element
    constexpr const_reference back() const {
        return m_data[N - 1];
    }

    // Returns an iterator pointing to the first element of the array.
    iterator begin() {
        return &m_data[0];
    }

    // Returns a const_iterator pointing to the first element of the array.
    const_iterator begin() const {
        return &m_data[0];
    }

    // Returns a const_iterator pointing to the first element of the array.
    const_iterator cbegin() const {
        return &m_data[0];
    }

    // Returns a const_reverse_iterator pointing to the last element of the array.
    const_reverse_iterator crbegin() const {
        return const_reverse_iterator(&m_data[N - 1]);
    }

    // Returns a const_iterator pointing to the element following the last element of the array.
    const_iterator cend() const {
        return &m_data[N];
    }
    
    // Returns a const_reverse_iterator pointing to the element preceding the first element of the array.
    const_reverse_iterator crend() const {
        return const_reverse_iterator(&m_data[-1]);
    }

    // Returns a pointer pointing to the first element of the array.
    pointer data() {
        return &m_data[0];
    }

    // Returns a const_pointer pointing to the first element of the array.
    const_pointer data() const {
        return &m_data[0];
    }
   
    // Returns an iterator pointing to one past the last element of the array.
    iterator end() {
        return &m_data[N];
    }

    // Returns a const_iterator pointing to one past the last element of the array.
    const_iterator end() const {
        return &m_data[N];
    }

    // Checks if the array is empty.
    constexpr bool empty() const {
        return N == 0;
    }

    // Returns a reference to the first element of the array.
    reference front() {
        return m_data[0];
    }

    // Returns a const reference to the first element of the array.
    constexpr const_reference front() const {
        return m_data[0];
    }

    // Returns the maximum possible size of the array.
    constexpr size_type max_size() const {
        return N;
    }

    // Returns a reverse iterator to the last element of the array.
    reverse_iterator rbegin() {
        return reverse_iterator(&m_data[N - 1]);
    }

    // Returns a const reverse iterator to the last element of the array.
    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(&m_data[N - 1]);
    }

    // Returns a reverse iterator to the theoretical element preceding the first element of the array.
    reverse_iterator rend() {
        return reverse_iterator(&m_data[-1]);
    }

    // Returns a const reverse iterator to the theoretical element preceding the first element of the array.
    const_reverse_iterator rend() const {
        return const_reverse_iterator(&m_data[-1]);
    }

    // Returns the number of elements in the array can hold.
    constexpr size_type size() const {
        return N;
    }

    // Assigns the given value to all elements in the array.
    void fill(const_reference val) {
        for (size_type i = 0; i < N; i++) {
            m_data[i] = val;
        }
    }

    // Swaps the contents of this array with another array of the same type and size.
    void swap(array<T, N>& right) {
        for (size_type i = 0; i < N; i++) {
            value_type temp = move(m_data[i]);
            m_data[i] = move(right.m_data[i]);
            right.m_data[i] = move(temp);
        }
    }

    // Returns a reference to a element in a given offset
    reference operator[](size_type off) {
        return m_data[off];
    }

    // Returns a const_reference to a element in a given offset
    constexpr const_reference operator[](size_type off) const {
        return m_data[off];
    }

    // Overloaded assignment operator
    array<T, N>& operator=(const array<T, N>& right) {
        for (size_type i = 0; i < N; i++) {
            m_data[i] = right.m_data[i];
        }
        return *this;
    }

    // Overloaded move assignment operator
    array<T, N>& operator=(array<T, N>&& right) {
        for (size_type i = 0; i < N; i++) {
            m_data[i] = move(right.m_data[i]);
            right.m_data[i] = value_type();
        }
        return *this;
    }

    // Overloaded equal operator to check array elements are equal
    bool operator==(const array<T, N>& right) {
        for (size_type i = 0; i < N; i++) {
            if (m_data[i] != right.m_data[i]) {
                return false;
            }
        }
        return true;
    }

    // Overloaded not equal operator to check array elements are equal
    bool operator!=(const array<T, N>& right) {
        return !(*this == right);
    }

    // Compares the elements of this array with another array lexicographically.
    bool operator<(const array<T, N>& right) {
        return lexicographical_compare(cbegin(), cend(), right.cbegin(), right.cend());
    }

    // Compares the elements of this array with another array lexicographically.
    bool operator>(const array<T, N>& right) {
        return lexicographical_compare(right.cbegin(), right.cend(), cbegin(), cend());
    }

    // Compares the elements of this array with another array lexicographically.
    bool operator<=(const array<T, N>& right) {
        return lexicographical_compare(cbegin(), cend(), right.cbegin(), right.cend()) || *this == right;
    }

    // Compares the elements of this array with another array lexicographically.
    bool operator>=(const array<T, N>& right) {
        return lexicographical_compare(right.cbegin(), right.cend(), cbegin(), cend()) || *this == right;
    }
private:
    value_type m_data[N];
};
} // namespace my_stl

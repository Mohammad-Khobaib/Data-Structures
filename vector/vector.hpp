#pragma once

#include <initializer_list>

#include "../iterators/reverse_iterator/reverse_iterator.hpp"
#include "../exceptions/out_of_range/out_of_range.hpp"
#include "../utility/move.hpp"
#include "../utility/lexicographical_compare.hpp"

namespace my_stl
{
template<typename T>
class vector {
public:
    using value_type = T;
    using iterator = value_type*;
    using pointer = value_type*;
    using reference = value_type&;
    using size_type = unsigned int;
    using difference_type = long int;
    using const_reference = const value_type&;
    using const_pointer = const value_type*;
    using const_iterator = const value_type*;
    using const_reverse_iterator = reverse_iterator<const_iterator>;
    using reverse_iterator = reverse_iterator<iterator>;
public:
    // Default constructor
    vector<value_type>() : 
        m_data(nullptr),
        m_size(0), 
        m_capacity(0) 
    {}

    // Constructoe taking an std::initializer_list
    vector<value_type>(const std::initializer_list<value_type>& values) : 
        m_data(new value_type[values.size()]),
        m_size(values.size()),
        m_capacity(values.size()) 
    {
        size_type i = 0;
        for (const_reference value: values) {
            m_data[i] = value;
            i++;
        }
    }
    
    // Constructor with size argument
    explicit vector<value_type>(size_type count) : 
        m_data(new value_type[count]{value_type()}), 
        m_size(count),
        m_capacity(count) 
    {}
    
    // Constructor with size and value arguments
    explicit vector<value_type>(size_type count, const_reference value): 
        m_data(new value_type[count]),
        m_size(count),
        m_capacity(count) 
    {
        for (size_type i = 0; i < m_size; i++) {
            m_data[i] = value;
        }
    }

    // Copy constructor
    vector<value_type>(const vector<value_type>& right): 
        m_data(new value_type[right.m_size]),
        m_size(right.m_size),
        m_capacity(right.m_size)
    {
        for (size_type i = 0; i < right.m_size; i++) {
            m_data[i] = right[i];
        }
    }

    // Move constructor
    vector<value_type>(vector<value_type>&& right): 
        m_data(right.m_data),
        m_size(right.m_size),
        m_capacity(right.m_capacity)
    {
        right.m_data = nullptr;
        right.m_size = 0;
        right.m_capacity = 0;
    }

    // Destructor
    ~vector<value_type>() {
        delete[] m_data;
        m_size = 0;
        m_capacity = 0;
    }

    // Return a reference to the element at the specified position.
    reference at(size_type off) {
        if (off < 0 || off >= m_size) {
            throw out_of_range("Error: vector index out of range. Please ensure the index is within the valid range.");
        }
        return m_data[off];
    }

    // Return a const reference to the element at the specified position
    const_reference at(size_type off) const {
        if (off < 0 || off >= m_size) {
            throw out_of_range("Error: vector index out of range. Please ensure the index is within the valid range.");
        }
        return m_data[off];
    }

    // Returns a reference to the last element of the vector
    reference back() {
        return m_data[m_size - 1];
    }

    // Returns a const reference to the last element of the vector
    const_reference back() const {
        return m_data[m_size - 1];
    }

    // Returns an iterator pointing to the first element of the vector
    const_iterator begin() const {
        return &m_data[0];
    }

    // Returns a const iterator pointing to the first element of the vector
    iterator begin() {
        return &m_data[0];
    }

    // Returns a const iterator pointing to the first element of the vector
    const_iterator cbegin() const {
        return &m_data[0];
    }

    // Returns a reverse iterator pointing to the last element of the vector
    reverse_iterator rbegin() {
        return reverse_iterator(&m_data[m_size - 1]);
    }

    // Returns a const reverse iterator pointing to the last element of the vector
    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(&m_data[m_size - 1]);
    }

    // Returns a const reverse iterator pointing to the last element of the vector
    const_reverse_iterator crbegin() const {
        return const_reverse_iterator(&m_data[m_size - 1]);
    }

    // Returns an iterator pointing to the past-the-end element of the vector
    iterator end() {
        return &m_data[m_size];
    }

    // Returns a const iterator pointing to the past-the-end element of the vector
    const_iterator end() const {
        return &m_data[m_size];
    }

    // Returns a const iterator pointing to the past-the-end element of the vector
    const_iterator cend() const {
        return &m_data[m_size];
    }

    // Returns a reverse iterator pointing to the element before the first element of the vector
    reverse_iterator rend() {
        return reverse_iterator(&m_data[-1]);
    }

    // Returns a const reverse iterator pointing to the element before the first element of the vector
    const_reverse_iterator rend() const {
        return const_reverse_iterator(&m_data[-1]);
    }

    // Returns a const reverse iterator pointing to the element before the first element of the vector
    const_reverse_iterator crend() const {
        return const_reverse_iterator(&m_data[-1]);
    }

    // Returns a const pointer to the first element of the vector
    const_pointer data() const {
        return &m_data[0];
    }

    // Returns a pointer to the first element of the vector
    pointer data() {
        return &m_data[0];
    }

    // Returns a reference to the first element of the vector
    reference front() {
        return m_data[0];
    }

    // Returns a const reference to the first element of the vector
    const_reference front() const {
        return m_data[0];
    }

    // Returns the number of elements currently stored in the vector.
    size_type size() const {
        return m_size;
    }

    // Returns the maximum number of elements that the vector can hold without resizing.
    size_type capacity() const {
        return m_capacity;
    }

    // Checks whether the vector is empty
    bool empty() const {
        return m_size == 0;
    }

    // Clears all elements from the vector, making it empty.
    void clear() {
        for (size_type i = 0; i < m_size; i++) {
            m_data[i] = value_type();
        }
        m_size = 0;
    }
    
    // Reserves memory to accommodate at least a specified number of elements without reallocation.
    void reserve(size_type count) {
        if (count > m_capacity) {
            re_allocate(count);
        }
    }

    // Changes the size of the vector to the specified new size, optionally resizing the capacity.
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

    // Reduces the capacity of the vector to match its size.
    void shrink_to_fit() {
        if (m_capacity > m_size)
            re_allocate(m_size);
    }

    // Adds a copy of the specified value to the end of the vector.
    void push_back(const_reference val) {
        expand_capacity();
        m_data[m_size] = val;
        m_size++;
    }

    // Moves the specified value to the end of the vector.
    void push_back(value_type&& value) {
        expand_capacity();
        m_data[m_size] = move(value);
        m_size++;
    }

    // Removes the last element from the vector.
    void pop_back() {
        m_size--;
        m_data[m_size] = value_type();
    }

    // Constructs an element in-place at the end of the vector.
    template<typename... Args>
    void emplace_back(Args&&... args) {
        expand_capacity();
        m_data[m_size] = value_type(args...);
        m_size++;
    }

    // Constructs an element in-place at the specified position in the vector.
    template<typename...  Args>
    iterator emplace(const_iterator position, Args&&... args) {
        if (m_size == 0) {
            re_allocate(1);
            m_data[0] = value_type(args...);
            m_size++;
            return begin();
        }
        size_type off = position - begin();
        value_type temp = move(m_data[m_size - 1]);
        iterator it = end() - 1;
        while (it > position) {
            *it = *(it - 1);
            --it;
        }
        *it = value_type(args...);
        if (m_size == m_capacity) {
            re_allocate(m_size + 1);
        }
        m_data[m_size] = move(temp);
        m_size++;
        return &m_data[off];
    }

    // Erases an element from the vector.
    iterator erase(const_iterator position) {
        iterator it = begin();
        while (it <= position) {
            ++it;
        }
        iterator copy_it = --it;
        while (it < end()) {
            *(it - 1) = move(*it);
            ++it;
        }
        m_size--;
        return copy_it;
    }

    // Erases a range of element from vector.
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

    // Returns a reference to the element at the specified position in the vector.
    reference operator[](size_type position) {
        return m_data[position];
    }

    // Returns a const reference to the element at the specified position in the vector.
    const_reference operator[](size_type position) const {
        return m_data[position];
    }

    // Assigns the contents of another vector to this vector.
    vector<value_type>& operator=(const vector<value_type>& right) {
        delete[] m_data;
        re_allocate(right.m_size);
        for (size_type i = 0; i < right.m_size; i++) {
            m_data[i] = right[i];
        }
        m_size = right.m_size;
        m_capacity = right.m_capacity;
        return *this;
    }

    // Assigns the contents of another vector to this vector using move semantics.
    vector<value_type>& operator=(vector<value_type>&& right) {
        delete[] m_data;

        m_data = right.m_data;
        m_size = right.m_size;
        m_capacity = right.m_capacity;

        right.m_data = nullptr;
        right.m_size = 0;
        right.m_capacity = 0;
        return *this;
    }

    // Checks if this vector equal to another vector. 
    bool operator==(const vector<value_type>& right) {
        if (m_size != right.m_size) {
            return false;
        }
        for (size_type i = 0; i < m_size; i++) {
            if (m_data[i] != right[i]) {
                return false;
            }
        }
        return true;
    }

    // Checks if this vector is not equal to another vector. 
    bool operator!=(const vector<value_type>& right) {
        return !(*this == right);
    }

    // Checks if this vector is less than to another vector. 
    bool operator<(const vector<value_type>& right) {
        return lexicographical_compare(cbegin(), cend(), right.cbegin(), right.cend());
    }

    // Checks if this vector is less than or equal to another vector. 
    bool operator<=(const vector<value_type>& right) {
        return lexicographical_compare(cbegin(), cend(), right.cbegin(), right.cend()) || *this == right;
    }

    // Checks if this vector is greater than to another vector. 
    bool operator>(const vector<value_type>& right) {
        return lexicographical_compare(right.cbegin(), right.cend(), cbegin(), cend());
    }

    // Checks if this vector is greater than or equal to another vector. 
    bool operator>=(const vector<value_type>& right) {
        return lexicographical_compare(right.cbegin(), right.cend(), cbegin(), cend()) || *this == right;
    }
    
private:
    value_type* m_data;
    size_type m_size;
    size_type m_capacity;

    // Expands the capacity of the vector if the number of elements equals the current capacity.
    void expand_capacity() {
        if (m_size == m_capacity) {
            if (m_size == 0)
                re_allocate(1);
            else
                re_allocate(m_size * 2);
        }
    }

    // Reallocates memory for the vector with a new capacity, copying existing elements to the new memory block.
    void re_allocate(size_type new_capacity) {
        value_type* new_data = new value_type[new_capacity]{value_type()};
        for (size_type i = 0; i < m_size; i++) {
            new_data[i] = move(m_data[i]);
        }
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }
};
} // namespace my_stl

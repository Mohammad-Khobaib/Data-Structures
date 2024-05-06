# List Class Documentation

Welcome to the List Class Documentation!

## Overview

The `list` class template represents a doubly linked list in C++. It provides dynamic size, efficient insertion and deletion operations, and bidirectional iterators for traversal.

## Features

- **Dynamic Size**: Elements can be added or removed dynamically.
- **Efficient Insertion/Deletion**: Operations like `push_back`, `push_front`, `pop_back`, and `pop_front` are efficient.
- **Bidirectional Iterators**: Supports bidirectional iterators for traversal.
- **Initializer List Constructor**: Can be initialized using an initializer list.

## Constructors

- **Default Constructor**:
  - Initializes an empty list.
  - `list<value_type>()`
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **Initializer List Constructor**:
  - Initializes the list with elements from an initializer list.
  - `list<value_type>(const std::initializer_list<value_type>& values)`
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(N)
  - **Auxiliary Space Complexity**: O(N)

## Modifiers

- **push_back()**:
  - Adds an element to the end of the list.
  - `void push_back(const_reference val)`
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **push_front()**:
  - Adds an element to the front of the list.
  - `void push_front(const_reference val)`
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **pop_back()**:
  - Removes the last element from the list.
  - `void pop_back()`
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **pop_front()**:
  - Removes the first element from the list.
  - `void pop_front()`
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **emplace_back()**:
  - Constructs an element in-place at the end of the list.
  - `void emplace_back(value_type&& val)`
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **emplace_front()**:
  - Constructs an element in-place at the front of the list.
  - `void emplace_front(value_type&& val)`
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **clear()**:
  - Removes all elements from the list.
  - `void clear()`
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **emplace()**:
  - Constructs an element in-place at the specified position.
  - `iterator emplace(iterator position, value_type&& val)`
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **erase()**:
  - Removes the element at the specified position.
  - `iterator erase(iterator& position)`
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **insert()**:
  - Inserts an element at the specified position.
  - `iterator insert(iterator position, const_reference val)`
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **merge()**:
  - Merges another list into this list.
  - `void merge(const list<value_type>& right)`
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **remove()**:
  - Removes all elements equal to the specified value.
  - `void remove(const_reference val)`
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **remove_if()**:
  - Removes all elements for which the predicate returns true.
  - `template<typename Predicate> void remove_if(Predicate compare)`
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **resize()**:
  - Changes the size of the list to the specified size.
  - `void resize(size_type new_size, const_reference val = value_type())`
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **sort()**:
  - Sorts the elements of the list.
  - `void sort()`
  - **Time Complexity**: O(N log N)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **reverse()**:
  - Reverses the order of the elements in the list.
  - `void reverse()`
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **splice()**:
  - Transfers elements from another list into this list.
  - `void splice(const_iterator position, list<value_type>& source)`
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **swap()**:
  - Swaps the contents of this list with another list.
  - `void swap(list<value_type>& right)`
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **size()**:
  - Returns the number of elements in the list.
  - `size_type size() const`
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **empty()**:
  - Checks if the list is empty.
  - `bool empty() const`
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **begin()** and **end()**:
  - Returns iterators to the beginning and end of the list.
  - `iterator begin()`, `iterator end()`
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **cbegin()** and **cend()**:
  - Returns constant iterators to the beginning and end of the list.
  - `const_iterator cbegin() const`, `const_iterator cend() const`
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **rbegin()** and **rend()**:
  - Returns reverse iterators to the reverse beginning and end of the list.
  - `reverse_iterator rbegin()`, `reverse_iterator rend()`
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **crbegin()** and **crend()**:
  - Returns constant reverse iterators to the reverse beginning and end of the list.
  - `const_reverse_iterator crbegin() const`, `const_reverse_iterator crend() const`
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

## Usage

```cpp
#include <iostream>
#include "list.hpp"

int main() {
    // Creating an empty list of integers
    my_stl::list<int> my_list;

    // Pushing elements to the list
    my_list.push_back(10);
    my_list.push_back(20);
    my_list.push_back(30);

    // Printing list elements
    std::cout << "List elements: ";
    for (auto& elem : my_list) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Checking list size
    std::cout << "List size: " << my_list.size() << std::endl;

    // Accessing elements
    std::cout << "First element: " << my_list.front() << std::endl;
    std::cout << "Last element: " << my_list.back() << std::endl;

    // Removing elements
    my_list.pop_front(); // Remove first element
    my_list.pop_back();  // Remove last element

    // Printing modified list
    std::cout << "Modified list: ";
    for (auto& elem : my_list) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}

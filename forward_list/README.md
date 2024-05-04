# Forward List Class Documentation

Welcome to the Forward List Class Documentation!

## Overview

The `forward_list` class template implements a singly linked list, allowing constant time insertion and removal of elements from the front of the list. It supports forward traversal only.

## Features

- **Efficient Insertion and Deletion**: Elements can be efficiently added or removed from the front of the list.
- **Iterators**: Provides iterators for forward traversal of the list.
- **Initializer List Support**: Allows initialization of the list with values from an initializer list.

## Methods

### Constructors

- **Default Constructor**:
  - Initializes an empty forward list.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **Initializer List Constructor**:
  - Initializes the forward list with values from an initializer list.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(N)

### Element Access

- **front()**:
  - Returns a reference to the first element in the list.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

### Modifiers

- **push_front(const T& val)**:
  - Inserts an element at the beginning of the list with the given value.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **push_front(T&& val)**:
  - Inserts an element at the beginning of the list by moving the given value.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **pop_front()**:
  - Removes the first element from the list.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **clear()**:
  - Removes all elements from the list.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **assign(iterator it1, iterator it2)**:
  - Replaces the elements of the list with elements from the range [it1, it2).
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **assign(size_type count, const T& val)**:
  - Replaces the elements of the list with count copies of the given value.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **assign(const std::initializer_list<T>& values)**:
  - Replaces the elements of the list with elements from the initializer list.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **emplace_after(const_iterator position, T&& val)**:
  - Inserts a new element after the specified position by moving the given value.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **emplace_front(T&& val)**:
  - Inserts a new element at the beginning of the list by moving the given value.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **erase_after(const_iterator position)**:
  - Removes the element after the specified position.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **erase_after(const_iterator first, const_iterator last)**:
  - Removes the elements in the range [first, last) from the list.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **insert_after(const_iterator position, const T& val)**:
  - Inserts a new element after the specified position with the given value.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **insert_after(const_iterator position, size_type count, const T& val)**:
  - Inserts count copies of the given value after the specified position.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **insert_after(const_iterator position, const std::initializer_list<T>& values)**:
  - Inserts elements from the initializer list after the specified position.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **remove(const T& val)**:
  - Removes all elements with the given value from the list.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **remove_if(Predicate predicate)**:
  - Removes all elements for which the predicate returns true.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **merge(forward_list& right)**:
  - Merges the elements of the right list into this list.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **merge(forward_list& right, Predicate compare)**:
  - Merges the elements of the right list into this list using the provided comparison function.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **resize(size_type new_size, const T& val = T())**:
  - Changes the size of the list to new_size.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **reverse()**:
  - Reverses the order of the elements in the list.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

### Iterators

- **begin()**:
  - Returns an iterator to the beginning of the list.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **end()**:
  - Returns an iterator to the end of the list.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **cbegin()**:
  - Returns a const iterator to the beginning of the list.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **cend()**:
  - Returns a const iterator to the end of the list.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **before_begin()**:
  - Returns an iterator to the element before the beginning of the list.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **cbefore_begin()**:
  - Returns a const iterator to the element before the beginning of the list.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **reverse_begin()**:
  - Returns a reverse iterator to the reverse beginning of the list.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **reverse_end()**:
  - Returns a reverse iterator to the reverse end of the list.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

## Usage

```cpp
#include "forward_list.hpp"

int main() {
    // Creating an empty forward list of integers
    my_stl::forward_list<int> myList;

    // Adding elements to the front of the list
    myList.push_front(1);
    myList.push_front

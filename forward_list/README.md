# forward_list Class Documentation

Welcome to the forward_list Class Documentation!

## Overview

The `forward_list` class provides a singly linked list implementation in C++, offering efficient insertion and deletion operations at the front of the list. It is similar to `std::forward_list` in the C++ Standard Library.

## Features

- **Singly Linked List**: The `forward_list` class represents a singly linked list where each element points to the next element in the sequence.
- **Efficient Operations**: Operations such as `push_front`, `pop_front`, and `remove` are efficient as they only need to manipulate the head pointer.
- **Iterator Support**: The class provides iterator support, allowing traversal and manipulation of list elements.
- **Initializer List Assignment**: Supports assigning elements from an initializer list using the `assign` method.

## Methods
### Constructors

- **Default Constructor**:
  - Initializes an empty forward list.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **Initializer List Constructor**:
  - Initializes the forward list with values from an initializer list.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **Copy Constructor**:
  - Initializes the forward list with the contents of another forward list.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **Move Constructor**:
  - Initializes the forward list by moving the contents of another forward list.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

### Modifiers

- **push_front(const_reference val)**:
  - Inserts an element at the beginning of the list with the given value.
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

- **assign(iterator first, iterator last)**:
  - Assigns elements from a range defined by iterators.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **assign(size_type count, const_reference val)**:
  - Assigns a specified number of elements with a given value.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **assign(const std::initializer_list<value_type>& values)**:
  - Assigns elements from an initializer list.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **emplace_after(const_iterator position, value_type&& new_value)**:
  - Inserts a new element after the specified position using move semantics.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **emplace_front(value_type&& new_value)**:
  - Inserts a new element at the front of the list using move semantics.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **erase_after(const_iterator position)**:
  - Removes the element following the specified position.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **erase_after(const_iterator first, const_iterator last)**:
  - Removes the elements in the range [first, last) from the list.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **insert_after(const_iterator position, const_reference val)**:
  - Inserts a new element after the specified position with the given value.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **insert_after(const_iterator position, size_type count, const_reference val)**:
  - Inserts 'count' copies of 'val' after the specified position.
  - **Time Complexity**: O(count)
  - **Space Complexity**: O(1)

- **insert_after(const_iterator position, const std::initializer_list<value_type>& values)**:
  - Inserts elements from the initializer list 'values' after the specified position.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **remove(const_reference val)**:
  - Removes all nodes with the given value from the list.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **remove_if(Predicate predicate)**:
  - Removes elements from the list that satisfy the given predicate.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **reverse()**:
  - Reverses the order of elements in the list.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **merge(forward_list<value_type>& right)**:
  - Merges the current forward_list with another forward_list.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **merge(forward_list<value_type>& right, Predicate compare)**:
  - Merges the current forward_list with another forward_list using a custom comparator.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **sort()**:
  - Sorts the elements of the forward_list in ascending order.
  - **Time Complexity**: O(N log N)
  - **Space Complexity**: O(log N)

- **unique()**:
  - Removes consecutive duplicate elements from the list.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **splice_after(const_iterator position, forward_list<value_type>& source)**:
  - Moves elements from another forward_list and inserts them after the specified position.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **resize(size_type new_size, const_reference val = value_type())**:
  - Resizes the list to contain the specified number of elements.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

### Iterators

- **begin()**:
  - Returns an iterator to the beginning of the list.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **cbegin()**:
  - Returns a const iterator to the beginning of the list.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **end()**:
  - Returns an iterator to one past the end of the list.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **cend()**:
  - Returns a const iterator to one past the end of the list.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **before_begin()**:
  - Returns an iterator to before the beginning of the list.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **cbefore_begin()**:
  - Returns a const iterator to before the beginning of the list.
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
    myList.push_front(2);
    myList.push_front(3);

    // Removing the first element from the list
    myList.pop_front();

    // Removing all occurrences of a specified value from the list
    myList.remove(2);

    // Iterating through the list and printing its elements
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Checking if the list is empty
    if (!myList.empty()) {
        std::cout << "The list is not empty." << std::endl;
    }

    return 0;
}

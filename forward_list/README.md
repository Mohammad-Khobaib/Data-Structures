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

- **Default Constructor**: Initializes an empty forward list.
- **Variadic Constructor**: Initializes the forward list with the provided arguments.

### Element Manipulation

- **push_front**: Inserts an element at the beginning of the forward list.
- **pop_front**: Removes the first element from the forward list.
- **remove**: Removes all occurrences of a specified value from the forward list.

### Assignment

- **assign(iterator, iterator)**: Assigns elements from a range defined by iterators.
- **assign(unsigned int, const T&)**: Assigns a specified number of elements with a given value.
- **assign(const initializer_list<T>&)**: Assigns elements from an initializer list.

### Accessors

- **front**: Returns a reference to the first element in the forward list.

### Iterators

- **begin**: Returns an iterator to the beginning of the forward list.
- **end**: Returns an iterator to one past the end of the forward list.

### Utility

- **empty**: Checks if the forward list is empty.

## Usage

```cpp
#include "forward_list.hpp"

int main() {
    // Creating a forward list of integers
    forward_list<int> myList {1, 2, 3, 4, 5};

    // Removing an element from the list
    myList.remove(3);

    // Printing the elements of the list
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

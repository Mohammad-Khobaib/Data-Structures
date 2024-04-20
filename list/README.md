# List Class Documentation

Welcome to the List Class Documentation!

## Overview

The `list` class template represents a doubly linked list in C++. It offers a versatile way to store and manage a sequence of elements of a specified type, with efficient insertion, deletion, and traversal capabilities.

## Features

- **Doubly Linked Structure**: Utilizes a doubly linked structure for efficient insertion and deletion operations at both ends and in the middle of the list.
- **Dynamic Sizing**: The list dynamically adjusts its size as elements are added or removed.
- **Iterator Support**: Provides support for iterators to traverse the elements of the list efficiently.
- **Type Safety**: Ensures type safety by using template parameters to specify the type of elements stored in the list.

## Methods

### Constructors

- **Default Constructor**: Initializes an empty list.
- **Variadic Constructor**: Initializes the list with the provided arguments.

### Element Manipulation

- **push_back()**: Adds an element to the end of the list.
- **push_front()**: Adds an element to the beginning of the list.
- **pop_back()**: Removes the last element from the list.
- **pop_front()**: Removes the first element from the list.
- **insert()**: Inserts multiple elements at a specified position in the list.

### Size and Empty Check

- **size()**: Returns the number of elements in the list.
- **empty()**: Checks if the list is empty.

### Accessors

- **front()**: Returns a reference to the first element in the list.
- **back()**: Returns a reference to the last element in the list.

### Iterators

- **begin()**: Returns an iterator to the beginning of the list.
- **end()**: Returns an iterator to one past the end of the list.

### Clearing the List

- **clear()**: Removes all elements from the list.

## Usage

```cpp
#include "list.hpp"

int main() {
    // Creating a list of integers
    list<int> myList;

    // Adding elements to the list
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    // Accessing elements of the list
    std::cout << "List elements:";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    // Checking list size and emptiness
    std::cout << "List size: " << myList.size() << std::endl;
    std::cout << "Is the list empty? " << (myList.empty() ? "Yes" : "No") << std::endl;

    return 0;
}

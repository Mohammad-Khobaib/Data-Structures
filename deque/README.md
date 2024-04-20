# Deque Class Documentation

Welcome to the Deque Class Documentation!

## Overview

The `deque` class template represents a double-ended queue in C++. It provides a dynamic array-like container with the ability to efficiently add and remove elements from both ends.

## Features

- **Dynamic Storage**: The deque dynamically allocates memory to store elements.
- **Efficient Insertion and Removal**: Elements can be added or removed from both the front and back of the deque with constant time complexity.
- **Iterator Support**: The deque supports iterators for traversing its elements.

## Methods

### Constructors

- **Default Constructor**: Initializes an empty deque.
- **Variadic Constructor**: Initializes the deque with the provided arguments.

### Element Manipulation

- **push_back(const T& element)**: Adds an element to the back of the deque.
- **push_front(const T& element)**: Adds an element to the front of the deque.
- **pop_back()**: Removes the element from the back of the deque.
- **pop_front()**: Removes the element from the front of the deque.

### Size and Capacity

- **size()**: Returns the number of elements in the deque.
- **capacity()**: Returns the current capacity of the deque.

### Accessors

- **operator[](unsigned int index)**: Returns a reference to the element at the specified index.

### Iterators

- **begin()**: Returns an iterator to the beginning of the deque.
- **end()**: Returns an iterator to one past the end of the deque.

### Utility

- **empty()**: Checks if the deque is empty.
- **clear()**: Removes all elements from the deque.

## Usage

```cpp
#include "deque.hpp"

int main() {
    // Creating a deque of integers
    deque<int> myDeque;

    // Adding elements to the deque
    myDeque.push_back(10);
    myDeque.push_front(5);
    myDeque.push_back(20);

    // Accessing and printing elements
    std::cout << "Deque elements:";
    for (auto it = myDeque.begin(); it != myDeque.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    // Checking size and capacity
    std::cout << "Deque size: " << myDeque.size() << std::endl;
    std::cout << "Deque capacity: " << myDeque.capacity() << std::endl;

    return 0;
}

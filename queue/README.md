# Queue Class Documentation

Welcome to the Queue Class Documentation!

## Overview

The `queue` class template represents a FIFO (First In First Out) data structure in C++. It internally uses a linked list to store elements.

## Features

- **FIFO Behavior**: Elements are inserted at the back and removed from the front of the queue.
- **Type Safety**: The type of elements stored in the queue is specified using a template parameter, ensuring type safety.
- **Efficient Operations**: Queue operations like push and pop have O(1) time complexity in most cases.

## Methods

### Modifiers

- **push(const_reference val)**:
  - Inserts an element at the back of the queue.

- **pop()**:
  - Removes the element at the front of the queue.

## Accessors

- **front()**:
  - Returns a reference to the element at the front of the queue.

- **back()**:
  - Returns a reference to the element at the back of the queue.

## Capacity

- **size()**:
  - Returns the number of elements in the queue.

- **empty()**:
  - Checks whether the queue is empty.

## Usage

```cpp
#include <iostream>
#include "queue.hpp"

int main() {
    my_stl::queue<int> q;

    // Insert elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);

    // Remove an element from the queue
    q.pop();

    // Access the front and back elements
    int front_elem = q.front();
    int back_elem = q.back();

    // Print the size of the queue
    std::cout << "Queue size: " << q.size() << std::endl;

    return 0;
}

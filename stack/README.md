# Stack Class Documentation

Welcome to the Stack Class Documentation!

## Overview

The `stack` class template represents a basic stack data structure in C++. It provides a way to store elements in a last-in, first-out (LIFO) manner, where elements are added and removed from the top of the stack.

## Features

- **Simple Interface**: The stack class provides a simple interface for pushing, popping, and accessing elements.
- **Efficiency**: Operations like push, pop, and access to the top element are efficient with constant time complexity.
- **Customizable Element Type**: The element type of the stack is customizable using a template parameter.

## Methods

### Constructors

- **Default Constructor**:
  - Initializes an empty stack.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

### Element Manipulation

- **push(const T& val)**:
  - Pushes the given element onto the top of the stack.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **pop()**:
  - Removes the top element from the stack.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

### Element Access

- **top()**:
  - Returns a reference to the top element of the stack without removing it.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

### Size and Status

- **size()**:
  - Returns the number of elements in the stack.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **empty()**:
  - Checks if the stack is empty.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

## Usage

```cpp
#include "stack.hpp"

int main() {
    // Creating a stack of integers
    my_stl::stack<int> my_stack;

    // Pushing elements onto the stack
    my_stack.push(10);
    my_stack.push(20);
    my_stack.push(30);

    // Popping an element from the stack
    my_stack.pop();

    // Accessing the top element
    int top_element = my_stack.top();

    // Checking the size of the stack
    if (!my_stack.empty()) {
        int stack_size = my_stack.size();
    }

    return 0;
}
```

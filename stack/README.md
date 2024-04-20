# Stack Class Documentation

Welcome to the Stack Class Documentation!

## Overview

The `stack` class template represents a last-in, first-out (LIFO) data structure in C++. It provides operations for pushing elements onto the stack, popping elements from the top of the stack, accessing the top element without removal, and checking the size and emptiness of the stack.

## Features

- **Push Operation**: Adds an element to the top of the stack.
- **Pop Operation**: Removes the top element from the stack.
- **Top Operation**: Returns a reference to the top element without removal.
- **Size and Empty Check**: Provides methods to check the size and emptiness of the stack.

## Methods

### Constructors

- **Default Constructor**: Initializes an empty stack.

### Element Manipulation

- **push(const T& element)**: Adds an element to the top of the stack.
- **pop()**: Removes the top element from the stack.
- **top()**: Returns a reference to the top element without removal.

### Size and Empty Check

- **size() const**: Returns the number of elements in the stack.
- **empty() const**: Checks if the stack is empty.

## Usage

```cpp
#include "stack.hpp"

int main() {
    // Creating a stack of integers
    stack<int> myStack;

    // Adding elements to the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Accessing and printing top element
    std::cout << "Top element: " << myStack.top() << std::endl;

    // Popping elements from the stack
    myStack.pop();
    myStack.pop();

    // Checking stack size and emptiness
    std::cout << "Stack size: " << myStack.size() << std::endl;
    std::cout << "Is the stack empty? " << (myStack.empty() ? "Yes" : "No") << std::endl;

    return 0;
}

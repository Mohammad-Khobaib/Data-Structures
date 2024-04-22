# initializer_list Class Documentation

Welcome to the initializer_list Class Documentation!

## Overview

The `initializer_list` class provides a lightweight implementation that mimics some functionalities of the standard library's `std::initializer_list`. It offers a simple way to create and manage a list of elements.

## Features

- **Lightweight**: The `initializer_list` class is designed to be lightweight and simple, providing basic functionalities for managing a list of elements.
- **Initialization**: The class allows initializing the list with a variadic number of arguments, similar to `std::initializer_list`.
- **Size Method**: You can retrieve the size of the initializer list using the `size()` method.
- **Iterator Support**: It provides `begin()` and `end()` methods to obtain iterators to the beginning and end of the list, enabling traversal.

## Methods

### Constructors

- **Default Constructor**: Initializes an empty initializer list.
- **Variadic Constructor**: Initializes the initializer list with the provided arguments.

### Size

- **size()**: Returns the size of the initializer list.

### Iterators

- **begin()**: Returns an iterator to the beginning of the initializer list.
- **end()**: Returns an iterator to one past the end of the initializer list.

## Usage

```cpp
#include "initializer_list.hpp"

int main() {
    // Creating an initializer list of integers
    initializer_list<int> myList {1, 2, 3, 4, 5};

    // Printing the elements of the initializer list
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Checking the size of the initializer list
    std::cout << "Initializer list size: " << myList.size() << std::endl;

    return 0;
}

# vector Class Documentation

Welcome to the Vector Class Documentation!

## Overview

The `vector` class template provides a dynamic array implementation in C++, allowing efficient insertion, deletion, and access of elements. It is similar to `std::vector` in the C++ Standard Library.

## Features

- **Dynamic Array**: The `vector` class represents a dynamic array where elements can be efficiently added or removed at the end of the array.
- **Random Access**: Elements of the vector can be efficiently accessed using the subscript operator (`[]`) or iterators.
- **Iterator Support**: The class provides iterator support, allowing traversal and manipulation of vector elements.
- **Efficient Resizing**: The vector automatically adjusts its capacity to accommodate new elements, ensuring efficient memory usage.
- **Move Semantics**: Supports move semantics, allowing efficient transfer of resources between vectors.

## Methods

### Constructors

- **Default Constructor**: Initializes an empty vector.
- **Initializer List Constructor**: Initializes the vector with the elements from the provided initializer list.
- **Size Constructor**: Initializes the vector with a specified size, optionally initializing elements with a default value.
- **Copy Constructor**: Initializes the vector with a copy of another vector.
- **Move Constructor**: Initializes the vector by moving resources from another vector.

### Element Access

- **Operator[]**: Allows accessing elements of the vector using the subscript operator.
- **at()**: Returns a reference to the element at the specified position, with bounds checking.
- **front()**: Returns a reference to the first element in the vector.
- **back()**: Returns a reference to the last element in the vector.
- **data()**: Returns a pointer to the underlying array.
- **begin()** and **end()**: Return iterators to the beginning and end of the vector.
- **cbegin()** and **cend()**: Return constant iterators to the beginning and end of the vector.
- **rbegin()** and **rend()**: Return reverse iterators to the reverse beginning and reverse end of the vector.
- **crbegin()** and **crend()**: Return constant reverse iterators to the reverse beginning and reverse end of the vector.

### Capacity

- **size()**: Returns the number of elements in the vector.
- **capacity()**: Returns the current capacity of the vector.
- **empty()**: Checks whether the vector is empty.
- **reserve()**: Reserves memory to accommodate a specified number of elements without reallocation.
- **resize()**: Changes the size of the vector to the specified new size.

### Modifiers

- **clear()**: Clears all elements from the vector, making it empty.
- **push_back()**: Adds a copy of the specified value to the end of the vector.
- **emplace_back()**: Constructs an element in-place at the end of the vector.
- **pop_back()**: Removes the last element from the vector.
- **emplace()**: Constructs an element in-place at the specified position in the vector.
- **erase()**: Erases elements from the vector.
- **swap()**: Exchanges the contents of the vector with another vector.
- **assign()**: Assigns new contents to the vector.

### Comparison Operators

- **operator==()**: Checks if this vector is equal to another vector.
- **operator!=()**: Checks if this vector is not equal to another vector.
- **operator<()**: Checks if this vector is less than another vector.
- **operator<=()**: Checks if this vector is less than or equal to another vector.
- **operator>()**: Checks if this vector is greater than another vector.
- **operator>=()**: Checks if this vector is greater than or equal to another vector.

## Usage

```cpp
#include<iostream>

#include "vector.hpp"

int main() {
    // Creating a vector of integers
    my_stl::vector<int> vec {1, 2, 3, 4, 5};

    // Accessing elements using subscript operator
    std::cout << "Element at index 2: " << vec[2] << std::endl;

    // Adding elements to the vector
    vec.push_back(6);
    vec.emplace_back(7);

    // Iterating over the vector
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Checking if the vector is empty
    if (!vec.empty()) {
        std::cout << "Vector is not empty." << std::endl;
    }

    return 0;
}

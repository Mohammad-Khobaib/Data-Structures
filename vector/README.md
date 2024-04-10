# Vector Class Documentation

Welcome to the Vector Class Documentation!

## Overview

The `vector` class template represents a dynamic array in C++. It provides a flexible way to store and manipulate a sequence of elements of a specified type, with the ability to dynamically resize as needed.

## Features

- **Dynamic Resizing**: The vector can grow or shrink dynamically as elements are added or removed.
- **Efficient Access**: Elements of the vector can be efficiently accessed using the subscript operator (`[]`) or iterators.
- **Type Safety**: The type of elements stored in the vector is specified using a template parameter, ensuring type safety.
- **Memory Management**: The vector manages memory allocation and deallocation internally, allowing for seamless usage.

## Methods

### Constructors

- **Default Constructor**: Initializes an empty vector.
- **Variadic Constructor**: Initializes the vector with the provided arguments.

### Element Manipulation

- **push_back()**: Adds an element to the end of the vector.
- **emplace_back()**: Constructs an element in-place at the end of the vector.
- **operator[]**: Allows accessing elements of the vector using the subscript operator.
- **begin()**: Returns an iterator to the beginning of the vector.
- **end()**: Returns an iterator to one past the end of the vector.

### Size and Capacity

- **size()**: Returns the number of elements in the vector.
- **capacity()**: Returns the current capacity of the vector.

## Usage

```cpp
#include "vector.hpp"

int main() {
    // Creating a vector of integers
    vector<int> vec;

    // Adding elements to the vector
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    // Accessing elements of the vector
    std::cout << "Vector elements:";
    for (auto& elem : vec) {
        std::cout << " " << elem;
    }
    std::cout << std::endl;

    // Checking vector size and capacity
    std::cout << "Vector size: " << vec.size() << std::endl;
    std::cout << "Vector capacity: " << vec.capacity() << std::endl;

    return 0;
}

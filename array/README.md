# array Class Documentation

Welcome to the array Class Documentation!

## Overview

The `array` class provides a fixed-size array implementation in C++, allowing efficient access to elements and performing bounds checking. It is similar to `std::array` in the C++ Standard Library.

## Features

- **Fixed-Size Array**: The `array` class represents a fixed-size array where the size is known at compile time.
- **Efficient Access**: Provides efficient access to elements using iterators or index-based access.
- **Bounds Checking**: Performs bounds checking to ensure safe access to array elements.
- **Iterator Support**: The class provides iterator support, allowing traversal of array elements.
- **Initializer List Support**: Supports initialization of elements from an initializer list.

## Methods

### Constructors

- **Default Constructor**:
  - Initializes an empty array with default-initialized elements.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **Initializer List Constructor**:
  - Initializes the array with values from an initializer list.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **Copy Constructor**:
  - Initializes the array with the contents of another array.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **Move Constructor**:
  - Initializes the array by moving the contents of another array.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

### Element Access

- **at(size_type off)**:
  - Returns a reference to the element at the specified index, performing bounds checking.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **operator[](size_type off)**:
  - Returns a reference to the element at the specified index without bounds checking.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **front()**:
  - Returns a reference to the first element of the array.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **back()**:
  - Returns a reference to the last element of the array.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **data()**:
  - Returns a pointer to the first element of the array.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

### Iterators

- **begin()**:
  - Returns an iterator to the beginning of the array.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  
- **cbegin()**:
  - Returns an const iterator to the beginning of the array.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **end()**:
  - Returns an iterator to one past the end of the array.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **cend()**:
  - Returns an const iterator to one past the end of the array.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **rbegin()**:
  - Returns a reverse iterator to the last element of the array.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  
- **crbegin()**:
  - Returns a const reverse iterator to the last element of the array.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **rend()**:
  - Returns a reverse iterator to one before the beginning of the array.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  
- **crend()**:
  - Returns a const reverse iterator to one before the beginning of the array.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

### Capacity

- **size()**:
  - Returns the number of elements in the array.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **max_size()**:
  - Returns the maximum possible size of the array.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **empty()**:
  - Checks if the array is empty.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

### Modifiers

- **fill(const_reference val)**:
  - Assigns the given value to all elements in the array.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **swap(array<T, N>& right)**:
  - Swaps the contents of this array with another array of the same type and size.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

### Operators
- **operator=(const array<T, N>& right)**:
  - Assigns the contents of another array to this array.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **operator=(array<T, N>&& right)**:
  - Moves the contents of another array to this array.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **operator==(const array<T, N>& right)**:
  - Compares the elements of this array with another array for equality.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **operator!=(const array<T, N>& right)**:
  - Checks if this array is not equal to another array.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **operator<(const array<T, N>& right)**:
  - Compares the elements of this array with another array lexicographically.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **operator>(const array<T, N>& right)**:
  - Checks if this array is greater than another array lexicographically.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **operator<=(const array<T, N>& right)**:
  - Checks if this array is less than or equal to another array lexicographically.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **operator>=(const array<T, N>& right)**:
  - Checks if this array is greater than or equal to another array lexicographically.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

## Usage

```cpp
#include <iostream>

#include "array.hpp"

int main() {
    // Creating an array of integers
    my_stl::array<int, 5> arr = {1, 2, 3, 4, 5};

    // Accessing elements using iterators
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Accessing elements using index-based access
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

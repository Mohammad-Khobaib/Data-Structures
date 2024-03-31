# Array Class Documentation

Welcome to the Array Class Documentation!

## Overview

The `array` class template represents a fixed-size array in C++. It provides a simple and efficient way to store and access elements of a specified type with a fixed size.

## Features

- **Fixed Size**: The size of the array is determined at compile time and cannot be changed at runtime.
- **Type Safety**: The type of elements stored in the array is specified using a template parameter, ensuring type safety.
- **Efficient Access**: Elements of the array can be efficiently accessed using the subscript operator (`[]`) or iterators.
- **Initialization**: The array can be initialized using a default constructor or by providing a variadic number of arguments.

## Methods

### Constructors

- **Default Constructor**: Initializes all elements to their default values.
- **Variadic Constructor**: Initializes the array with the provided arguments.

### Element Access

- **Operator[]**: Allows accessing elements of the array using the subscript operator.
- **begin()**: Returns an iterator to the beginning of the array.
- **end()**: Returns an iterator to one past the end of the array.

### Size

- **size()**: Returns the size of the array.

### Comparison

- **Operator==**: Compares two arrays for equality, returning true if all corresponding elements are equal.

## Usage

```cpp
#include "array.hpp"

int main() {
    // Creating an array of integers with size 5
    array<int, 5> arr;

    // Initializing array elements
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    // Printing array elements
    for (auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Checking array size
    std::cout << "Array size: " << arr.size() << std::endl;

    return 0;
}

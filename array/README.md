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

- **Default Constructor**:
  - Initializes all elements to their default values.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)
  
- **Variadic Constructor**:
  - Initializes the array with the provided arguments.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(N)
  - **Auxiliary Space Complexity**: O(N)

### Element Access

- **Operator[]**:
  - Allows accessing elements of the array using the subscript operator.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **at()**:
  - Returns a reference to the element at the specified position, with bounds checking. Throws `std::out_of_range` if `off` is out of range.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **front()**:
  - Returns a reference to the first element in the array.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)
  
- **back()**:
  - Returns a reference to the last element in the array.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **data()**:
  - Returns a pointer to the underlying array.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **begin()** and **end()**:
  - Return iterators to the beginning and end of the array.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **cbegin()** and **cend()**:
  - Return constant iterators to the beginning and end of the array.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **rbegin()** and **rend()**:
  - Return reverse iterators to the reverse beginning and reverse end of the array.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **crbegin()** and **crend()**:
  - Return constant reverse iterators to the reverse beginning and reverse end of the array.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

### Size

- **size()**:
  - Returns the size of the array.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **max_size()**:
  - Returns the maximum possible number of elements the array can hold.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

### Modifiers

- **fill()**:
  - Assigns the given value to all elements in the array.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **swap()**:
  - Exchanges the contents of the array with those of another array.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

### Assignment

- **operator=()**:
  - Assigns the contents of another array to this array.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

### Utility

- **empty()**:
  - Checks whether the array is empty.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

## Usage

```cpp
#include "array.hpp"

int main() {
    // Creating an array of integers with size 5
    my_stl::array<int, 5> arr;

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

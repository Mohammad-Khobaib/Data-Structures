# Vector Class Documentation

Welcome to the Vector Class Documentation!

## Overview

The `vector` class template represents a dynamic array in C++. It provides a versatile way to store and manipulate elements of a specified type with dynamic memory allocation.

## Features

- **Dynamic Size**: The size of the vector can grow or shrink dynamically during runtime.
- **Efficient Access**: Elements of the vector can be efficiently accessed using the subscript operator (`[]`) or iterators.
- **Memory Management**: The vector dynamically manages memory for its elements, ensuring efficient memory usage.

## Methods

### Constructors

- **Default Constructor**:
  - Initializes an empty vector.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **Size Constructor**:
  - Initializes the vector with a specified number of elements, all initialized to their default values.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(N)

- **Value Constructor**:
  - Initializes the vector with a specified number of elements, all initialized to a specified value.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(N)

- **Copy Constructor**:
  - Initializes the vector with the contents of another vector.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(N)

- **Move Constructor**:
  - Initializes the vector by moving the contents of another vector.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

### Element Access

- **Operator[]**:
  - Allows accessing elements of the vector using the subscript operator.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **at()**:
  - Returns a reference to the element at the specified position, with bounds checking.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **front()** and **back()**:
  - Return references to the first and last elements of the vector.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **data()**:
  - Returns a pointer to the underlying array.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **begin()**, **end()**, **cbegin()**, **cend()**, **rbegin()**, **rend()**, **crbegin()**, **crend()**:
  - Return iterators for traversing the vector.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

### Size and Capacity

- **size()**:
  - Returns the number of elements in the vector.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **capacity()**:
  - Returns the current capacity of the vector.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **max_size()**:
  - Returns the maximum possible size of the vector.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

### Modifiers

- **clear()**:
  - Removes all elements from the vector.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **emplace()**:
  - Inserts a new element at the specified position.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **emplace_back()**:
  - Inserts a new element at the end of the vector.
  - **Time Complexity**: O(1) amortized
  - **Space Complexity**: O(1) amortized

- **push_back()**:
  - Appends a new element to the end of the vector.
  - **Time Complexity**: O(1) amortized
  - **Space Complexity**: O(1) amortized

- **pop_back()**:
  - Removes the last element from the vector.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **erase()**:
  - Removes the element at the specified position or a range of elements.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **resize()**:
  - Changes the size of the vector.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **reserve()**:
  - Requests that the vector capacity be at least enough to contain a specified number of elements.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **shrink_to_fit()**:
  - Reduces the capacity of the vector to fit its size.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

- **swap()**:
  - Exchanges the contents of two vectors.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

### Miscellaneous

- **empty()**:
  - Checks whether the vector is empty.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **operator=()**:
  - Assigns the contents of another vector to this vector.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)

## Usage

```cpp
#include "vector.hpp"

int main() {
    // Create a vector of integers
    my_stl::vector<int> vec;

    // Add elements to the vector
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    // Iterate over the vector and print elements
    for (auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}

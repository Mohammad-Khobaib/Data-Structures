# Deque Class

Welcome to the Deque Class Documentation!

## Overview

The `deque` class template represents a double-ended queue (deque) in C++. It provides a dynamic array-like container that allows efficient insertion and deletion of elements at both the beginning and the end.

## Features

- **Dynamic Size**: The size of the deque can dynamically expand or shrink as elements are added or removed.
- **Efficient Insertion and Deletion**: Elements can be efficiently inserted or deleted from both the front and the back of the deque.
- **Random Access**: Elements can be accessed randomly using the subscript operator (`[]`) or iterators.
- **Iterators Support**: The deque supports bidirectional iterators for efficient traversal.

## Methods

### Constructors

- **Default Constructor**:
  - Initializes an empty deque.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)
  
- **Count Constructor**:
  - Initializes the deque with a specified count of default-initialized elements.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(N)
  - **Auxiliary Space Complexity**: O(N)

- **Initializer List Constructor**:
  - Initializes the deque with elements from an initializer list.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(N)
  - **Auxiliary Space Complexity**: O(N)

### Element Access

- **Operator[]**:
  - Allows accessing elements of the deque using the subscript operator.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **at()**:
  - Returns a reference to the element at the specified position, with bounds checking. Throws `out_of_range` if the index is out of range.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **front()**:
  - Returns a reference to the first element in the deque.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)
  
- **back()**:
  - Returns a reference to the last element in the deque.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

### Iterators

- **begin()** and **end()**:
  - Return iterators to the beginning and end of the deque.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **rbegin()** and **rend()**:
  - Return reverse iterators to the reverse beginning and reverse end of the deque.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

### Capacity

- **size()**:
  - Returns the number of elements in the deque.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **max_size()**:
  - Returns the maximum number of elements the deque can hold.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **empty()**:
  - Checks whether the deque is empty.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

### Modifiers

- **push_back()** and **push_front()**:
  - Add an element to the back or front of the deque.
  - **Time Complexity**: O(1) amortized
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **pop_back()** and **pop_front()**:
  - Remove an element from the back or front of the deque.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **emplace_back()** and **emplace_front()**:
  - Construct and add an element to the back or front of the deque.
  - **Time Complexity**: O(1) amortized
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **emplace()**:
  - Construct and insert an element at the specified position in the deque.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **erase()**:
  - Remove the element at the specified position in the deque.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **clear()**:
  - Remove all elements from the deque.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

- **shrink_to_fit()**:
  - Reduces the capacity of the deque to fit its size.
  - **Time Complexity**: O(N)
  - **Space Complexity**: O(1)
  - **Auxiliary Space Complexity**: O(1)

## Usage

```cpp
#include "deque.hpp"

int main() {
    // Creating a deque of integers
    my_stl::deque<int> dq;

    // Inserting elements
    dq.push_back(1);
    dq.push_front(2);
    dq.emplace_back(3);

    // Accessing elements
    std::cout << "Front element: " << dq.front() << std::endl;
    std::cout << "Back element: " << dq.back() << std::endl;

    // Iterating through the deque
    for (auto it = dq.begin(); it != dq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}

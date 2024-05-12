# red_black_tree Class Documentation

Welcome to the Red-Black Tree Class Documentation!

## Overview

The `red_black_tree` class template implements a Red-Black Tree data structure in C++. Red-Black Trees are a type of self-balancing binary search tree that ensure logarithmic time complexity for insertion, deletion, and search operations.

## Features

- **Balanced Tree**: Red-Black Trees maintain balance during insertion and deletion operations, ensuring optimal performance.
- **Iterator Support**: Provides support for iterators allowing traversal of the tree in various orders.
- **Efficient Operations**: Insertion, deletion, and search operations have logarithmic time complexity.
- **Type Safety**: Templated class ensures type safety for elements stored in the tree.

## Methods

### Constructors

- **Default Constructor**:
  - Initializes an empty Red-Black Tree.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **Initializer List Constructor**:
  - Initializes the Red-Black Tree with elements from an initializer list.
  - **Time Complexity**: O(N log N)
  - **Space Complexity**: O(N)

### Modifiers

- **insert_node()**:
  - Inserts a new node with the given data into the Red-Black Tree.
  - **Time Complexity**: O(log N)
  - **Space Complexity**: O(1)

- **delete_node()**:
  - Deletes the node containing the given data from the Red-Black Tree.
  - **Time Complexity**: O(log N)
  - **Space Complexity**: O(1)

### Element Access

- **search_node()**:
  - Searches for a node containing the given data in the Red-Black Tree.
  - **Time Complexity**: O(log N)
  - **Space Complexity**: O(1)

### Iterators

- **begin()**:
  - Returns an iterator pointing to the first element in the Red-Black Tree.
  - **Time Complexity**: O(log N)
  - **Space Complexity**: O(log N)

- **end()**:
  - Returns an iterator pointing to the position just beyond the last element in the Red-Black Tree.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **cbegin()**:
  - Returns a constant iterator pointing to the first element in the Red-Black Tree.
  - **Time Complexity**: O(log N)
  - **Space Complexity**: O(log N)

- **cend()**:
  - Returns a constant iterator pointing to the position just beyond the last element in the Red-Black Tree.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **rbegin()**:
  - Returns a reverse iterator pointing to the last element in the Red-Black Tree.
  - **Time Complexity**: O(log N)
  - **Space Complexity**: O(log N)

- **rend()**:
  - Returns a reverse iterator pointing to the position just before the first element in the Red-Black Tree.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

- **crbegin()**:
  - Returns a constant reverse iterator pointing to the last element in the Red-Black Tree.
  - **Time Complexity**: O(log N)
  - **Space Complexity**: O(log N)

- **crend()**:
  - Returns a constant reverse iterator pointing to the position just before the first element in the Red-Black Tree.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

### Size

- **size()**:
  - Returns the number of nodes in the Red-Black Tree.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

### Utility

- **get_root()**:
  - Returns a pointer to the root node of the Red-Black Tree.
  - **Time Complexity**: O(1)
  - **Space Complexity**: O(1)

## Usage

```cpp
#include "red_black_tree.hpp"

int main() {
    // Creating a Red-Black Tree of integers
    my_stl::red_black_tree<int> tree;

    // Inserting elements into the tree
    tree.insert_node(10);
    tree.insert_node(20);
    tree.insert_node(5);

    // Searching for an element in the tree
    int found_element = tree.search_node(20);

    // Deleting an element from the tree
    tree.delete_node(10);

    // Iterating over the elements of the tree
    for (auto it = tree.begin(); it != tree.end(); ++it) {
        // Process each element
    }

    return 0;
}

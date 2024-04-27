# Map Class Documentation

Welcome to the Map Class Documentation!

## Overview

The `map` class template provides an associative container that maps keys to values using a red-black tree as its underlying data structure. It offers efficient insertion, deletion, and retrieval operations.

## Features

- **Balanced Binary Search Tree**: Utilizes a red-black tree to ensure balanced and efficient operations.
- **Insertion**: Supports insertion of key-value pairs.
- **Deletion**: Supports removal of key-value pairs.
- **Retrieval**: Provides a convenient way to access values associated with keys.

## Methods

### Constructors

- **Default Constructor**: Initializes an empty map.

### Element Manipulation

- **insert()**: Inserts a key-value pair into the map.
- **erase()**: Removes a key-value pair from the map.
- **operator[]**: Allows accessing values associated with keys using the subscript operator.

## Usage

```cpp
#include "map.hpp"
#include <cassert>

int main() {
    // Creating a map of integers to strings
    map<int, std::string> myMap;

    // Inserting key-value pairs
    myMap.insert(1, "One");
    myMap.insert(2, "Two");
    myMap.insert(3, "Three");

    // Accessing values
    assert(myMap[1] == "One");
    assert(myMap[2] == "Two");
    assert(myMap[3] == "Three");

    // Removing a key-value pair
    myMap.erase(2);

    // Verifying deletion
    assert(myMap[2] == "");

    return 0;
}
```

## Dependencies

- This implementation requires a red-black tree implementation (`red_black_tree.hpp`) and a `map_node` class (`map_node.hpp`).

# Red-Black Tree Class Documentation

Welcome to the Red-Black Tree Class Documentation!

## Overview

The `red_black_tree` class template represents a red-black tree, a self-balancing binary search tree. It provides efficient insertion, deletion, and searching of elements while maintaining the tree's balance.

## Features

- **Self-Balancing**: The red-black tree automatically balances itself during insertion and deletion operations to ensure a logarithmic time complexity for searching, insertion, and deletion.
- **Efficient Operations**: Supports insertion, deletion, and searching operations with logarithmic time complexity, providing efficient access to elements.
- **Type Safety**: The type of elements stored in the tree is specified using a template parameter, ensuring type safety.
- **Memory Management**: Manages memory allocation and deallocation internally, providing seamless usage.

## Methods

### Constructors

- **Default Constructor**: Initializes an empty red-black tree.
- **Destructor**: Destroys the red-black tree and deallocates memory.

### Element Manipulation

- **insert_node()**: Inserts a new node with the given data into the red-black tree.
- **delete_node()**: Deletes a node with the given data from the red-black tree.
- **search_node()**: Searches for a node with the given data in the red-black tree.

### Utility Functions

- **get_root()**: Returns a pointer to the root node of the red-black tree.

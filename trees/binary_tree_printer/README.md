# Binary Tree Printer

A utility class for printing binary trees in a visually appealing manner.

## Overview

The `binary_tree_printer` class provides methods to print a binary tree in a tree-like structure. It generates ASCII art representations of binary trees, making it easier to visualize their structure.

## Features

- Generates tree-like ASCII art representations of binary trees.
- Customizable characters for branches and node connections.
- Supports printing binary trees with any data type for nodes.

## Usage

1. Include the `binary_tree_printer.hpp` header file in your project.
2. Create an instance of the `binary_tree_printer` class.
3. Use the `print_tree` method to print a binary tree to the console.
4. Alternatively, use the `get_tree_string` method to get the tree representation as a vector of strings.

Example:

```cpp
#include "binary_tree_printer.hpp"

int main() {
    // Create a binary tree
    node<int>* root = new node<int>(1);
    root->left = new node<int>(2);
    root->right = new node<int>(3);
    root->left->left = new node<int>(4);
    root->left->right = new node<int>(5);

    // Create a binary tree printer
    binary_tree_printer<node<int>> printer;

    // Print the binary tree
    printer.print_tree(root);

    return 0;
}

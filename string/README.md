# String Class Documentation

Welcome to the String Class Documentation!

## Overview

The `string` class provides a simple implementation of a dynamic string in C++, allowing for manipulation and management of character sequences.

## Features

- **Dynamic Size**: The size of the string can change dynamically as characters are added or removed.
- **Efficient Memory Management**: Memory is dynamically allocated and deallocated as needed, ensuring efficient use of resources.
- **Character Access**: Characters within the string can be accessed and modified using array-like indexing or the `at` method.
- **Concatenation**: Strings can be concatenated using the `+` operator or the `+=` operator.

## Methods

### Constructors

- **Default Constructor**: Creates an empty string.
- **Constructor with C-style String**: Creates a string initialized with a null-terminated character array.
- **Copy Constructor**: Creates a new string as a copy of an existing string.

### Element Access

- **Operator[]**: Allows access to individual characters within the string using array-like indexing.
- **at()**: Returns a reference to the character at the specified position, with bounds checking.

### Size and Capacity

- **size()**: Returns the length of the string.
- **data()**: Returns a pointer to the underlying character array.

### Modification

- **push_back()**: Appends a null-terminated character array to the end of the string.

### Concatenation

- **Operator+**: Concatenates two strings and returns a new string containing the result.
- **Operator+=**: Appends the contents of another string to the end of this string.

### Assignment

- **Operator=**: Assigns the value of another string to this string.

### Output

- **Operator<<**: Overloaded to allow printing the string to an output stream.

## Usage

```cpp
#include "string.hpp"
#include <iostream>

int main() {
    string str1("Hello");
    string str2(", world!");

    string concatenated = str1 + str2;
    std::cout << concatenated << std::endl;

    str1 += " ";
    str1 += "How are you?";
    std::cout << str1 << std::endl;

    return 0;
}

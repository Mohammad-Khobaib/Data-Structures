# Queue Class Documentation

Welcome to the Queue Class Documentation!

## Overview

The `queue` class template represents a FIFO (First-In-First-Out) data structure in C++, implemented using a linked list. It provides operations for adding elements to the back of the queue (`push`), removing elements from the front of the queue (`pop`), accessing the front and back elements (`front`, `back`), checking the size of the queue (`size`), and checking if the queue is empty (`empty`).

## Features

- **FIFO Behavior**: Elements are added to the back of the queue and removed from the front in the order they were added.
- **Dynamic Size**: The size of the queue can grow or shrink dynamically as elements are added or removed.
- **Efficient Access**: Front and back elements can be accessed efficiently.
- **Exception Handling**: The `top` function throws an exception if called on an empty queue.

## Methods

### Element Manipulation

- **`push(const T& element)`:** Adds an element to the back of the queue.
- **`pop()`:** Removes the front element from the queue.
- **`front() const`:** Returns a reference to the front element of the queue.
- **`back() const`:** Returns a reference to the back element of the queue.

### Size and Empty Check

- **`size() const`:** Returns the number of elements in the queue.
- **`empty() const`:** Checks if the queue is empty.

### Top Element

- **`top() const`:** Returns a reference to the top element of the queue, throwing an exception if the queue is empty.

## Usage

```cpp
#include "queue.hpp"

int main() {
    // Create a queue of integers
    queue<int> myQueue;

    // Add elements to the queue
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    // Print the front and back elements
    std::cout << "Front element: " << myQueue.front() << std::endl;
    std::cout << "Back element: " << myQueue.back() << std::endl;

    // Remove an element from the front of the queue
    myQueue.pop();

    // Print the front element after popping
    std::cout << "Front element after pop: " << myQueue.front() << std::endl;

    // Check the size of the queue
    std::cout << "Queue size: " << myQueue.size() << std::endl;

    // Check if the queue is empty
    std::cout << "Is the queue empty? " << (myQueue.empty() ? "Yes" : "No") << std::endl;

    return 0;
}

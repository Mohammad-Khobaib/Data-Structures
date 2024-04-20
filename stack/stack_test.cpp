#include <iostream>
#include <cassert>

#include "stack.hpp"

// Test pushing elements onto the stack
void test_push() {
    stack<int> my_stack;
    my_stack.push(10);
    my_stack.push(20);
    my_stack.push(30);

    // Check top element after pushing
    assert(my_stack.top() == 30);
    // Check size after pushing
    assert(my_stack.size() == 3);
}

// Test popping elements from the stack
void test_pop() {
    stack<int> my_stack;
    my_stack.push(10);
    my_stack.push(20);
    my_stack.push(30);
    my_stack.pop();

    // Check top element after popping
    assert(my_stack.top() == 20);
    // Check size after popping
    assert(my_stack.size() == 2);
}

// Test top element retrieval without popping
void test_top() {
    stack<int> my_stack;
    my_stack.push(10);
    my_stack.push(20);

    // Check top element
    assert(my_stack.top() == 20);
}

// Test size of the stack
void test_size() {
    stack<int> my_stack;
    assert(my_stack.size() == 0); // Check size of empty stack
    my_stack.push(10);
    my_stack.push(20);
    assert(my_stack.size() == 2); // Check size after pushing elements
    my_stack.pop();
    assert(my_stack.size() == 1); // Check size after popping element
}

// Test if stack is empty
void test_empty() {
    stack<int> my_stack;
    assert(my_stack.empty()); // Check if stack is initially empty
    my_stack.push(10);
    assert(!my_stack.empty()); // Check if stack is not empty after pushing element
    my_stack.pop();
    assert(my_stack.empty()); // Check if stack is empty after popping element
}

int main() {
    test_push();
    test_pop();
    test_top();
    test_size();
    test_empty();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}

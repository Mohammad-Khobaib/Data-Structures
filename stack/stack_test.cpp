#include <iostream>
#include <cassert>

#include "stack.hpp"

// Test pushing elements onto the stack
void test_push() {
    my_stl::stack<int> my_stack;
    my_stack.push(10);
    my_stack.push(20);
    my_stack.push(30);

    // Check top element after pushing
    assert(my_stack.top() == 30 && "Failed to push elements onto the stack correctly");
    // Check size after pushing
    assert(my_stack.size() == 3 && "Incorrect size after pushing elements onto the stack");
}

// Test popping elements from the stack
void test_pop() {
    my_stl::stack<int> my_stack;
    my_stack.push(10);
    my_stack.push(20);
    my_stack.push(30);
    my_stack.pop();

    // Check top element after popping
    assert(my_stack.top() == 20 && "Failed to pop elements from the stack correctly");
    // Check size after popping
    assert(my_stack.size() == 2 && "Incorrect size after popping elements from the stack");
}

// Test top element retrieval without popping
void test_top() {
    my_stl::stack<int> my_stack;
    my_stack.push(10);
    my_stack.push(20);

    // Check top element
    assert(my_stack.top() == 20 && "Failed to retrieve top element correctly without popping");
}

// Test size of the stack
void test_size() {
    my_stl::stack<int> my_stack;
    assert(my_stack.size() == 0 && "Incorrect size of an empty stack");
    my_stack.push(10);
    my_stack.push(20);
    assert(my_stack.size() == 2 && "Incorrect size after pushing elements onto the stack");
    my_stack.pop();
    assert(my_stack.size() == 1 && "Incorrect size after popping an element from the stack");
}

// Test if stack is empty
void test_empty() {
    my_stl::stack<int> my_stack;
    assert(my_stack.empty() && "Stack should be empty initially");
    my_stack.push(10);
    assert(!my_stack.empty() && "Stack should not be empty after pushing an element");
    my_stack.pop();
    assert(my_stack.empty() && "Stack should be empty after popping an element");
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

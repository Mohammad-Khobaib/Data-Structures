#include <iostream>
#include <cassert>

#include "stack.hpp"
#include "../utility/move.hpp"

void test_default_constructor() {
    // Create a stack using the default constructor
    my_stl::stack<int> my_stack;

    // Check if the stack is empty
    assert(my_stack.empty());

    // Check if the size of the stack is 0
    assert(my_stack.size() == 0);
}

void test_copy_constructor() {
    // Create a stack with some elements
    my_stl::stack<int> original_stack;
    original_stack.push(1);
    original_stack.push(2);
    original_stack.push(3);

    // Create a copy of the original stack using the copy constructor
    my_stl::stack<int> copied_stack(original_stack);

    // Check if the size of the copied stack matches the original stack
    assert(copied_stack.size() == original_stack.size());

    // Check if the elements in the copied stack match the elements in the original stack
    while (!original_stack.empty()) {
        assert(original_stack.top() == copied_stack.top()); // Check top element
        original_stack.pop();
        copied_stack.pop();
    }
}

void test_move_constructor() {
    // Create a stack with some elements
    my_stl::stack<int> original_stack;
    original_stack.push(1);
    original_stack.push(2);
    original_stack.push(3);

    // Move construct a new stack from the original stack
    my_stl::stack<int> moved_stack(move(original_stack));

    // Check if the size of the moved stack matches the original stack
    assert(moved_stack.size() == 3);

    // Check if the original stack is now empty
    assert(original_stack.empty());

    // Check if the elements in the moved stack match the elements in the original stack
    assert(moved_stack.top() == 3);
    moved_stack.pop();
    assert(moved_stack.top() == 2);
    moved_stack.pop();
    assert(moved_stack.top() == 1);
    moved_stack.pop();
}

void test_push() {
    // Create a stack
    my_stl::stack<int> my_stack;

    // Push some elements onto the stack
    my_stack.push(1);
    my_stack.push(2);
    my_stack.push(3);

    // Check if the size of the stack has increased accordingly
    assert(my_stack.size() == 3);

    // Check if the top element of the stack is as expected
    assert(my_stack.top() == 3);
}

void test_pop() {
    // Create a stack with some elements
    my_stl::stack<int> my_stack;
    my_stack.push(1);
    my_stack.push(2);
    my_stack.push(3);

    // Pop an element from the stack
    my_stack.pop();

    // Check if the size of the stack has decreased accordingly
    assert(my_stack.size() == 2);

    // Check if the top element of the stack is as expected
    assert(my_stack.top() == 2);
}

void test_top() {
    // Create a stack with some elements
    my_stl::stack<int> my_stack;
    my_stack.push(1);
    my_stack.push(2);
    my_stack.push(3);

    // Check the top element of the stack using the non-const version of top()
    assert(my_stack.top() == 3);

    // Check the top element of the stack using the const version of top()
    const my_stl::stack<int>& const_stack = my_stack;
    assert(const_stack.top() == 3);
}

void test_size() {
    // Create a stack
    my_stl::stack<int> my_stack;

    // Push some elements onto the stack
    my_stack.push(1);
    my_stack.push(2);
    my_stack.push(3);

    // Check the size of the stack
    assert(my_stack.size() == 3);
}

void test_empty() {
    // Create an empty stack
    my_stl::stack<int> my_stack;

    // Check if the stack is empty
    assert(my_stack.empty() == true);

    // Push an element onto the stack
    my_stack.push(1);

    // Check if the stack is empty after pushing an element
    assert(my_stack.empty() == false);
}

void test_not_equal_operator() {
    // Create two stacks
    my_stl::stack<int> stack1;
    my_stl::stack<int> stack2;

    // Push different elements onto each stack
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    stack2.push(4);
    stack2.push(5);

    // Check if the stacks are not equal
    assert(stack1 != stack2);
}

void test_equal_operator() {
    // Create two stacks
    my_stl::stack<int> stack1;
    my_stl::stack<int> stack2;

    // Push the same elements onto each stack
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    stack2.push(1);
    stack2.push(2);
    stack2.push(3);

    // Check if the stacks are equal
    assert(stack1 == stack2);
}

void test_stack() {
    test_default_constructor();
    test_copy_constructor();
    test_move_constructor();
    test_push();
    test_pop();
    test_top();
    test_size();
    test_empty();
    test_not_equal_operator();
    test_equal_operator();
}

int main() {
    test_stack();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}

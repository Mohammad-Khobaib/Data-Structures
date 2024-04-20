#include <iostream>
#include <cassert>

#include "deque.hpp"

// Test pushing elements onto the back of the deque
void test_push_back() {
    deque<int> my_deque;
    my_deque.push_back(10);
    my_deque.push_back(20);
    my_deque.push_back(30);

    // Check size after pushing
    assert(my_deque.size() == 3);
    // Check capacity after pushing
    assert(my_deque.capacity() >= 3);
    // Check elements after pushing
    assert(my_deque[0] == 10);
    assert(my_deque[1] == 20);
    assert(my_deque[2] == 30);
}

// Test pushing elements onto the front of the deque
void test_push_front() {
    deque<int> my_deque;
    my_deque.push_front(10);
    my_deque.push_front(20);
    my_deque.push_front(30);

    // Check size after pushing
    assert(my_deque.size() == 3);
    // Check capacity after pushing
    assert(my_deque.capacity() >= 3);
    // Check elements after pushing
    assert(my_deque[0] == 30);
    assert(my_deque[1] == 20);
    assert(my_deque[2] == 10);
}

// Test popping elements from the front of the deque
void test_pop_front() {
    deque<int> my_deque;
    my_deque.push_back(10);
    my_deque.push_back(20);
    my_deque.push_back(30);
    my_deque.pop_front();

    // Check size after popping
    assert(my_deque.size() == 2);
    // Check elements after popping
    assert(my_deque[0] == 20);
    assert(my_deque[1] == 30);
}

// Test popping elements from the back of the deque
void test_pop_back() {
    deque<int> my_deque;
    my_deque.push_back(10);
    my_deque.push_back(20);
    my_deque.push_back(30);
    my_deque.pop_back();

    // Check size after popping
    assert(my_deque.size() == 2);
    // Check elements after popping
    assert(my_deque[0] == 10);
    assert(my_deque[1] == 20);
}

// Test if deque is empty
void test_empty() {
    deque<int> my_deque;
    assert(my_deque.empty()); // Check if deque is initially empty
    my_deque.push_back(10);
    assert(!my_deque.empty()); // Check if deque is not empty after pushing element
    my_deque.pop_back();
    assert(my_deque.empty()); // Check if deque is empty after popping element
}

// Test clearing the deque
void test_clear() {
    deque<int> my_deque;
    my_deque.push_back(10);
    my_deque.push_back(20);
    my_deque.push_back(30);
    my_deque.clear();

    // Check size after clearing
    assert(my_deque.size() == 0);
    // Check capacity after clearing
    assert(my_deque.capacity() == 0);
    // Check if deque is empty after clearing
    assert(my_deque.empty());
}

// Test accessing elements using subscript operator
void test_subscript_operator() {
    deque<int> my_deque;
    my_deque.push_back(10);
    my_deque.push_back(20);
    my_deque.push_back(30);

    // Check elements using subscript operator
    assert(my_deque[0] == 10);
    assert(my_deque[1] == 20);
    assert(my_deque[2] == 30);
}

// Test iterator functionality
void test_iterator() {
    deque<int> my_deque;
    my_deque.push_back(10);
    my_deque.push_back(20);
    my_deque.push_back(30);

    // Iterate over elements using iterators
    int expected_values[] = {10, 20, 30};
    int i = 0;
    for (auto it = my_deque.begin(); it != my_deque.end(); ++it) {
        assert(*it == expected_values[i++]);
    }
}

int main() {
    test_push_back();
    test_push_front();
    test_pop_front();
    test_pop_back();
    test_empty();
    test_clear();
    test_subscript_operator();
    test_iterator();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}

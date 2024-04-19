#include <cassert>
#include <iostream>

#include "list.hpp"

void test_constructor() {
    // Test case 1: Default constructor
    list<int> my_list;
    assert(my_list.size() == 0);
    assert(my_list.empty());

    // Test case 2: Constructor with initializer list
    list<int> init_list = {1, 2, 3, 4, 5};
    assert(init_list.size() == 5);
    assert(!init_list.empty());
}

void test_push_and_pop() {
    // Test case 1: Push elements and check size
    list<int> my_list;
    my_list.push_back(1);
    my_list.push_back(2);
    assert(my_list.size() == 2);
    assert(!my_list.empty());

    // Test case 2: Pop elements and check size
    my_list.pop_back();
    my_list.pop_front();
    assert(my_list.size() == 0);
    assert(my_list.empty());
}

void test_front_and_back() {
    // Test case 1: Access front and back elements
    list<int> my_list = {1, 2, 3, 4, 5};
    assert(my_list.front() == 1);
    assert(my_list.back() == 5);

    // Test case 2: Access front and back elements of an empty list (assert)
    list<int> empty_list;
    assert(empty_list.empty());
    assert(empty_list.size() == 0);
    // Front and back access on an empty list should be undefined behavior without exceptions
}

void test_insert_and_clear() {
    // Test case 1: Insert elements at specific position
    list<int> my_list = {1, 2, 3, 4, 5};
    auto it = my_list.begin();
    ++it;
    ++it;
    my_list.insert(it, 10, 99); // Insert 10 elements with value 99 after the third position
    assert(my_list.size() == 15);

    // Test case 2: Clear the list and check size
    my_list.clear();
    assert(my_list.size() == 0);
    assert(my_list.empty());
}

void run_all_tests() {
    test_constructor();
    test_push_and_pop();
    test_front_and_back();
    test_insert_and_clear();
}

int main() {
    run_all_tests();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}

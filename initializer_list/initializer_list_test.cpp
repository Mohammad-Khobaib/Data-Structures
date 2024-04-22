#include <cassert>
#include <iostream>

#include "initializer_list.hpp"

void test_default_constructor() {
    initializer_list<int> myList;
    assert(myList.size() == 0);
    assert(myList.begin() == myList.end());
}

void test_constructor_with_values() {
    initializer_list<int> myList {1, 2, 3, 4, 5};
    assert(myList.size() == 5);
    assert(*myList.begin() == 1);
    assert(*(myList.end() - 1) == 5);
}

void test_size_method() {
    initializer_list<char> myList {'a', 'b', 'c'};
    assert(myList.size() == 3);
}

void test_begin_and_end_methods() {
    initializer_list<double> myList {3.14, 2.71, 1.618};
    auto it = myList.begin();
    assert(*it == 3.14);
    assert(*(it + 2) == 1.618);
    assert(it + 3 == myList.end());
}

int main() {
    test_default_constructor();
    test_constructor_with_values();
    test_size_method();
    test_begin_and_end_methods();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}

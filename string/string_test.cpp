#include <iostream>
#include <cassert>
#include <cstring>

#include "string.hpp" 

void test_default_constructor() {
    my_stl::string str;
    assert(str.size() == 0);
    assert(str.capacity() == 15); // Default capacity
    assert(str.empty());
    assert(str.data()[0] == '\0'); // Empty string
}

void test_constructor_with_string_literal() {
    const char* testData = "Hello, world!";
    my_stl::string str(testData);
    assert(str.size() == 13);
    assert(std::strcmp(str.data(), testData) == 0);
}

void test_copy_constructor() {
    const char* testData = "Hello, world!";
    my_stl::string original(testData);
    my_stl::string copy(original);
    assert(copy.size() == original.size());
    assert(std::strcmp(copy.data(), original.data()) == 0);
}

void test_size() {
    const char* testData = "Hello, world!";
    my_stl::string str(testData);
    assert(str.size() == 13);
}

void test_append() {
    my_stl::string str("Hello");
    str.append(", world!");
    assert(str.size() == 13);
    assert(std::strcmp(str.data(), "Hello, world!") == 0);
}

int main() {
    test_default_constructor();
    test_constructor_with_string_literal();
    test_copy_constructor();
    test_size();
    test_append();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}

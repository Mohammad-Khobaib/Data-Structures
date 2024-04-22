#include "string.hpp"

#include <cstring>
#include <cassert>

void test_default_constructor() {
    string str;
    assert(str.size() == 0);
    assert(str.data() == nullptr);
}

void test_constructor_with_string_literal() {
    const char* testData = "Hello, world!";
    string str(testData);
    assert(str.size() == 13);
    assert(strcmp(str.data(), testData) == 0);
}

void test_copy_constructor() {
    const char* testData = "Hello, world!";
    string original(testData);
    string copy(original);
    assert(copy.size() == original.size());
    assert(strcmp(copy.data(), original.data()) == 0);
}

void test_size() {
    const char* testData = "Hello, world!";
    string str(testData);
    assert(str.size() == 13);
}

void test_push_back() {
    string str("Hello");
    str.push_back(", world!");
    assert(str.size() == 13);
    assert(strcmp(str.data(), "Hello, world!") == 0);
}

void test_concatenation() {
    string str1("Hello");
    string str2(", world!");
    string concatenated = str1 + str2;
    assert(concatenated.size() == 13);
    assert(strcmp(concatenated.data(), "Hello, world!") == 0);
}

void test_concatenation_assignment() {
    string str1("Hello");
    string str2(", world!");
    str1 += str2;
    assert(str1.size() == 13);
    assert(strcmp(str1.data(), "Hello, world!") == 0);
}

void test_assignment_operator() {
    const char* testData = "Hello, world!";
    string original(testData);
    string assigned;
    assigned = original;
    assert(assigned.size() == original.size());
    assert(strcmp(assigned.data(), original.data()) == 0);
}

int main() {
    test_default_constructor();
    test_constructor_with_string_literal();
    test_copy_constructor();
    test_size();
    test_push_back();
    test_concatenation();
    test_concatenation_assignment();
    test_assignment_operator();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}

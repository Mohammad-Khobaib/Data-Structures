#include <iostream>
#include <cassert>

#include "vector.hpp"

void test_default_constructor() {
    vector<int> vec;
    std::cout << "Testing default constructor:" << std::endl;
    assert(vec.size() == 0 && "Vector size should be 0");
    assert(vec.capacity() == 0 && "Vector capacity should be 0");
    std::cout << "Default constructor test passed!" << std::endl << std::endl;
}

void test_parameterized_constructor() {
    vector<int> vec(3, 5, 7);
    std::cout << "Testing parameterized constructor:" << std::endl;
    assert(vec.size() == 3 && "Vector size should be 3");
    assert(vec.capacity() == 3 && "Vector capacity should be 3");
    for (int i = 0; i < vec.size(); ++i) {
        assert(vec[i] == (i * 2 + 3) && "Incorrect element value");
    }
    std::cout << "Parameterized constructor test passed!" << std::endl << std::endl;
}

void test_push_back_and_emplace_back() {
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(5);
    vec.emplace_back(7);
    std::cout << "Testing push_back and emplace_back:" << std::endl;
    assert(vec.size() == 3 && "Vector size should be 3");
    assert(vec.capacity() >= 3 && "Vector capacity should be at least 3");
    for (int i = 0; i < vec.size(); ++i) {
        assert(vec[i] == (i * 2 + 3) && "Incorrect element value");
    }
    std::cout << "Push_back and emplace_back test passed!" << std::endl << std::endl;
}

void test_copy_constructor() {
    vector<int> vec1(3, 5, 7);
    vector<int> vec2 = vec1;
    std::cout << "Testing copy constructor:" << std::endl;
    assert(vec2.size() == vec1.size() && "Vector sizes should be equal");
    assert(vec2.capacity() == vec1.capacity() && "Vector capacities should be equal");
    for (int i = 0; i < vec2.size(); ++i) {
        assert(vec2[i] == vec1[i] && "Element values should be equal");
    }
    std::cout << "Copy constructor test passed!" << std::endl << std::endl;
}

void test_iteration() {
    vector<int> vec(3, 5, 7);
    std::cout << "Testing iteration:" << std::endl;
    int i = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it, ++i) {
        assert(*it == (i * 2 + 3) && "Incorrect element value");
    }
    std::cout << "Iteration test passed!" << std::endl << std::endl;
}

int main() {
    test_default_constructor();
    test_parameterized_constructor();
    test_push_back_and_emplace_back();
    test_copy_constructor();
    test_iteration();
    return 0;
}

#include <cassert>
#include <iostream>

#include "array.hpp"

// Test function for default constructor
void test_default_constructor() {
    my_stl::array<int, 5> arr;
    for (unsigned int i = 0; i < arr.size(); ++i) {
        assert(arr[i] == 0);
    }
}

// Test function for initialization
void test_initialization() {
    // Test integer array initialization
    my_stl::array<int, 3> arr1(1, 2, 3);
    assert(arr1[0] == 1);
    assert(arr1[1] == 2);
    assert(arr1[2] == 3);

    // Test double array initialization
    my_stl::array<double, 2> arr2(3.14, 2.718);
    assert(arr2[0] == 3.14);
    assert(arr2[1] == 2.718);
}

// Test function for accessing elements
void test_access() {
    my_stl::array<int, 4> arr = {10, 20, 30, 40};
    assert(arr[0] == 10);
    assert(arr[1] == 20);
    assert(arr[2] == 30);
    assert(arr[3] == 40);

    arr[1] = 50; // Modify element
    assert(arr[1] == 50);
}

// Test function for const access
void test_const_access() {
    const my_stl::array<int, 3> arr = {1, 2, 3};
    assert(arr[0] == 1);
    assert(arr[1] == 2);
    assert(arr[2] == 3);
}

// Test function for size
void test_size() {
    my_stl::array<int, 5> arr;
    assert(arr.size() == 5);
}

// Test function for fill
void test_fill() {
    my_stl::array<int, 4> arr;
    arr.fill(10);
    for (unsigned int i = 0; i < arr.size(); ++i) {
        assert(arr[i] == 10);
    }
}

// Test function for front and back
void test_front_back() {
    my_stl::array<int, 3> arr = {10, 20, 30};
    assert(arr.front() == 10);
    assert(arr.back() == 30);
}

// Test function for iterators
void test_iterators() {
    my_stl::array<int, 3> arr = {10, 20, 30};
    int sum = 0;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        sum += *it;
    }
    assert(sum == 60);

    sum = 0;
    for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
        sum += *it;
    }
    assert(sum == 60);
}

// Test function for swap
void test_swap() {
    my_stl::array<int, 3> arr1 = {1, 2, 3};
    my_stl::array<int, 3> arr2 = {4, 5, 6};
    arr1.swap(arr2);
    assert(arr1[0] == 4 && arr1[1] == 5 && arr1[2] == 6);
    assert(arr2[0] == 1 && arr2[1] == 2 && arr2[2] == 3);
}

// Main function to run all test cases
int main() {
    test_default_constructor();
    test_initialization();
    test_access();
    test_const_access();
    test_size();
    test_fill();
    test_front_back();
    test_iterators();
    test_swap();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}

#include "array.hpp"
#include <cassert>
#include <iostream>

// Test function for default constructor
void testDefaultConstructor() {
    array<int, 5> arr;
    for (unsigned int i = 0; i < arr.size(); ++i) {
        assert(arr[i] == 0);
    }
}

// Test function for initialization
void testInitialization() {
    array<int, 3> arr1(1, 2, 3);
    array<int, 3> expected1 = {1, 2, 3};
    assert(arr1 == expected1);

    array<double, 2> arr2(3.14, 2.718);
    array<double, 2> expected2 = {3.14, 2.718};
    assert(arr2 == expected2);
}

// Test function for accessing elements
void testAccess() {
    array<int, 4> arr = {10, 20, 30, 40};
    assert(arr[0] == 10);
    assert(arr[1] == 20);
    assert(arr[2] == 30);
    assert(arr[3] == 40);
}

// Test function for const access
void testConstAccess() {
    const array<int, 3> arr = {1, 2, 3};
    assert(arr[0] == 1);
    assert(arr[1] == 2);
    assert(arr[2] == 3);
}

// Test function for size
void testSize() {
    array<int, 5> arr;
    assert(arr.size() == 5);
}

// Main function to run all test cases
int main() {
    testDefaultConstructor();
    testInitialization();
    testAccess();
    testConstAccess();
    testSize();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}

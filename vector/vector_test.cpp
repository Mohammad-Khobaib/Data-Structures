#include <cassert>
#include <iostream>
#include <utility>

#include "vector.hpp"

void test_default_constructor() {
    my_stl::vector<int> vec;
    assert(vec.size() == 0 && "Vector size should be 0");
    assert(vec.capacity() == 0 && "Vector capacity should be 0");
}

void test_size_constructor() {
    my_stl::vector<int> vec(3);
    assert(vec.size() == 3 && "Vector size should be 3");
    assert(vec.capacity() == 3 && "Vector capacity should be 3");
    for (int i = 0; i < vec.size(); ++i) {
        assert(vec[i] == 0 && "Incorrect element value");
    }
}

void test_value_constructor() {
    my_stl::vector<int> vec(3, 5);
    assert(vec.size() == 3 && "Vector size should be 3");
    assert(vec.capacity() == 3 && "Vector capacity should be 3");
    for (int i = 0; i < vec.size(); ++i) {
        assert(vec[i] == 5 && "Incorrect element value");
    }
}

void test_copy_constructor() {
    my_stl::vector<int> vec1(3, 5);
    my_stl::vector<int> vec2 = vec1;
    assert(vec2.size() == vec1.size() && "Vector sizes should be equal");
    assert(vec2.capacity() == vec1.capacity() && "Vector capacities should be equal");
    for (int i = 0; i < vec2.size(); ++i) {
        assert(vec2[i] == vec1[i] && "Element values should be equal");
    }
}

void test_move_constructor() {
    my_stl::vector<int> vec1(3, 5);
    my_stl::vector<int> vec2 = std::move(vec1);
    assert(vec1.size() == 0 && "Moved-from vector should be empty");
    assert(vec1.capacity() == 0 && "Moved-from vector should have zero capacity");
    assert(vec2.size() == 3 && "Vector sizes should be equal");
    assert(vec2.capacity() == 3 && "Vector capacities should be equal");
    for (int i = 0; i < vec2.size(); ++i) {
        assert(vec2[i] == 5 && "Element values should be equal");
    }
}

void test_push_back_and_emplace_back() {
    my_stl::vector<int> vec;
    vec.push_back(3);
    vec.push_back(5);
    vec.emplace_back(7);
    assert(vec.size() == 3 && "Vector size should be 3");
    assert(vec.capacity() >= 3 && "Vector capacity should be at least 3");
    for (int i = 0; i < vec.size(); ++i) {
        assert(vec[i] == (i * 2 + 3) && "Incorrect element value");
    }
}

void test_copy_assignment_operator() {
    my_stl::vector<int> vec1(3, 5);
    my_stl::vector<int> vec2;
    vec2 = vec1;
    assert(vec2.size() == vec1.size() && "Vector sizes should be equal");
    assert(vec2.capacity() == vec1.capacity() && "Vector capacities should be equal");
    for (int i = 0; i < vec2.size(); ++i) {
        assert(vec2[i] == vec1[i] && "Element values should be equal");
    }
}

void test_move_assignment_operator() {
    my_stl::vector<int> vec1(3, 5);
    my_stl::vector<int> vec2 = std::move(vec1);
    assert(vec1.size() == 0 && "Moved-from vector should be empty");
    assert(vec1.capacity() == 0 && "Moved-from vector should have zero capacity");
    assert(vec2.size() == 3 && "Vector sizes should be equal");
    assert(vec2.capacity() == 3 && "Vector capacities should be equal");
    for (int i = 0; i < vec2.size(); ++i) {
        assert(vec2[i] == 5 && "Element values should be equal");
    }
}

void test_erase() {
    my_stl::vector<int> vec(3, 5);
    vec.erase(vec.begin() + 1);
    assert(vec.size() == 2 && "Vector size should be 2");
    assert(vec.capacity() == 3 && "Vector capacity should be 3");
    assert(vec[0] == 5 && "Incorrect element value after erasing");
    assert(vec[1] == 5 && "Incorrect element value after erasing");
}

void test_clear() {
    my_stl::vector<int> vec(3, 5);
    vec.clear();
    assert(vec.size() == 0 && "Vector size should be 0 after clearing");
    assert(vec.capacity() == 3 && "Vector capacity should remain unchanged after clearing");
}

void test_resize() {
    my_stl::vector<int> vec(3, 5);
    vec.resize(5);
    assert(vec.size() == 5 && "Vector size should be 5 after resizing");
    assert(vec.capacity() == 5 && "Vector capacity should be 5 after resizing");
    for (int i = 0; i < vec.size(); ++i) {
        assert(vec[i] == 5 && "Incorrect element value after resizing");
    }
}

void test_reserve() {
    my_stl::vector<int> vec;
    vec.reserve(10);
    assert(vec.size() == 0 && "Vector size should remain unchanged after reserve");
    assert(vec.capacity() == 10 && "Vector capacity should be 10 after reserve");
}

void test_shrink_to_fit() {
    my_stl::vector<int> vec(3, 5);
    vec.resize(1);
    vec.shrink_to_fit();
    assert(vec.size() == 1 && "Vector size should remain unchanged after shrink_to_fit");
    assert(vec.capacity() == 1 && "Vector capacity should be 1 after shrink_to_fit");
}

void test_empty() {
    my_stl::vector<int> vec;
    assert(vec.empty() && "Vector should be empty initially");
    vec.push_back(5);
    assert(!vec.empty() && "Vector should not be empty after push_back");
}

int main() {
    test_default_constructor();
    test_size_constructor();
    test_value_constructor();
    test_copy_constructor();
    test_move_constructor();
    test_push_back_and_emplace_back();
    test_copy_assignment_operator();
    test_move_assignment_operator();
    test_erase();
    test_clear();
    std::cout << "All tests passed successfully!" << std::endl;
}

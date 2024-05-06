#include <iostream>
#include <cassert>
#include "list.hpp" // Include your list class header file

void test_default_constructor() {
    my_stl::list<int> myList;
    assert(myList.size() == 0);
    assert(myList.empty());
}

void test_push_back() {
    my_stl::list<int> myList;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    assert(myList.size() == 3);
    assert(myList.back() == 30);
}

void test_push_front() {
    my_stl::list<int> myList;
    myList.push_front(10);
    myList.push_front(20);
    myList.push_front(30);
    assert(myList.size() == 3);
    assert(myList.front() == 30);
}

void test_pop_back() {
    my_stl::list<int> myList;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.pop_back();
    assert(myList.size() == 2);
    assert(myList.back() == 20);
}

void test_pop_front() {
    my_stl::list<int> myList;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.pop_front();
    assert(myList.size() == 2);
    assert(myList.front() == 20);
}

void test_iterator() {
    my_stl::list<int> myList;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    
    // Test forward iteration
    int expectedValue = 10;
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        assert(*it == expectedValue);
        expectedValue += 10;
    }

    // Test backward iteration
    expectedValue = 30;
    for (auto it = myList.rbegin(); it != myList.rend(); ++it) {
        assert(*it == expectedValue);
        expectedValue -= 10;
    }
}

void test_insert_erase() {
    my_stl::list<int> myList;
    myList.push_back(10);
    myList.push_back(30);

    auto it = myList.begin();
    ++it;
    myList.insert(it, 20);

    assert(myList.size() == 3);
    assert(*it == 20);

    it = myList.begin();
    ++it;
    myList.erase(it);
    assert(myList.size() == 2);
    assert(*it == 30);
}

void test_const_iterators() {
    // Create a list and populate it
    my_stl::list<int> myList;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);

    // Test const iterator
    const my_stl::list<int>& constList = myList;
    int expectedValue = 10;
    for (auto it = constList.cbegin(); it != constList.cend(); ++it) {
        assert(*it == expectedValue);
        expectedValue += 10;
    }

    // Test const reverse iterator
    expectedValue = 30;
    for (auto it = constList.crbegin(); it != constList.crend(); ++it) {
        assert(*it == expectedValue);
        expectedValue -= 10;
    }
}

int main() {
    test_default_constructor();
    test_push_back();
    test_push_front();
    test_pop_back();
    test_pop_front();
    test_iterator();
    test_insert_erase();
    test_const_iterators();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}

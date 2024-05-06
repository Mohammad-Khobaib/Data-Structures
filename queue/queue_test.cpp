#include <iostream>
#include <cassert>

#include "queue.hpp"

// Test the push method
void test_push() {
    my_stl::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    assert(q.size() == 3);
}

// Test the pop method
void test_pop() {
    my_stl::queue<int> q;
    q.push(10);
    q.push(20);
    q.pop();
    assert(q.size() == 1);
}

// Test the front method
void test_front() {
    my_stl::queue<int> q;
    q.push(10);
    q.push(20);
    assert(q.front() == 10);
}

// Test the back method
void test_back() {
    my_stl::queue<int> q;
    q.push(10);
    q.push(20);
    assert(q.back() == 20);
}

// Test the size method
void test_size() {
    my_stl::queue<int> q;
    q.push(10);
    q.push(20);
    assert(q.size() == 2);
}

// Test the empty method
void test_empty() {
    my_stl::queue<int> q;
    assert(q.empty());
    q.push(10);
    assert(!q.empty());
}

int main() {
    test_push();
    test_pop();
    test_front();
    test_back();
    test_size();
    test_empty();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}

#include <iostream>
#include <cassert>

#include "queue.hpp"

// Test pushing elements onto the queue
void test_push() {
    queue<int> my_queue;
    my_queue.push(10);
    my_queue.push(20);
    my_queue.push(30);

    // Check front element after pushing
    assert(my_queue.front() == 10);
    // Check back element after pushing
    assert(my_queue.back() == 30);
    // Check size after pushing
    assert(my_queue.size() == 3);
}

// Test popping elements from the queue
void test_pop() {
    queue<int> my_queue;
    my_queue.push(10);
    my_queue.push(20);
    my_queue.push(30);
    my_queue.pop();

    // Check front element after popping
    assert(my_queue.front() == 20);
    // Check size after popping
    assert(my_queue.size() == 2);
}

// Test front element retrieval without popping
void test_front() {
    queue<int> my_queue;
    my_queue.push(10);
    my_queue.push(20);

    // Check front element
    assert(my_queue.front() == 10);
}

// Test back element retrieval without popping
void test_back() {
    queue<int> my_queue;
    my_queue.push(10);
    my_queue.push(20);

    // Check back element
    assert(my_queue.back() == 20);
}

// Test size of the queue
void test_size() {
    queue<int> my_queue;
    assert(my_queue.size() == 0); // Check size of empty queue
    my_queue.push(10);
    my_queue.push(20);
    assert(my_queue.size() == 2); // Check size after pushing elements
    my_queue.pop();
    assert(my_queue.size() == 1); // Check size after popping element
}

// Test if queue is empty
void test_empty() {
    queue<int> my_queue;
    assert(my_queue.empty()); // Check if queue is initially empty
    my_queue.push(10);
    assert(!my_queue.empty()); // Check if queue is not empty after pushing element
    my_queue.pop();
    assert(my_queue.empty()); // Check if queue is empty after popping element
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

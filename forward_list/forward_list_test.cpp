#include<iostream>
#include <cassert>

#include "forward_list.hpp"

void test_constructor_and_push_front() {
    my_stl::forward_list<int> myList;
    assert(myList.empty());

    myList.push_front(3);
    assert(myList.front() == 3);
    assert(!myList.empty());

    myList.push_front(2);
    assert(myList.front() == 2);

    myList.push_front(1);
    assert(myList.front() == 1);
}

void test_pop_front() {
    my_stl::forward_list<int> myList {1, 2, 3};
    myList.pop_front();
    assert(myList.front() == 2);

    myList.pop_front();
    assert(myList.front() == 3);

    myList.pop_front();
    assert(myList.empty());
}

void test_remove() {
    my_stl::forward_list<int> myList {1, 2, 3, 2, 4, 2, 5};
    myList.remove(2);
    assert(myList.front() == 1);
    // After removing all occurrences of 2, the list should contain 3 elements
}

void test_clear() {
    my_stl::forward_list<int> myList {1, 2, 3};
    myList.clear();
    assert(myList.empty());
}

void test_assign_with_iterators() {
    my_stl::forward_list<int> myList1 {1, 2, 3};
    my_stl::forward_list<int> myList2 {4, 5};
    myList2.assign(myList1.begin(), myList1.end());
    assert(myList2.front() == 1);
    // After assigning, the size of myList2 should be the same as myList1
}

void test_assign_with_number_of_elements() {
    my_stl::forward_list<int> myList;
    myList.assign(3, 5);
    assert(myList.front() == 5);
    // After assigning, the list should contain 3 elements, all with value 5
}

void test_assign_with_initializer_list() {
    my_stl::forward_list<int> myList;
    myList.assign({1, 2, 3});
    assert(myList.front() == 1);
    // After assigning, the list should contain elements 1, 2, and 3
}

void test_iterator() {
    my_stl::forward_list<int> myList {1, 2, 3, 4, 5};
    int sum = 0;
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        sum += *it;
    }
    assert(sum == 15);
}

int main() {
    test_constructor_and_push_front();
    test_pop_front();
    test_remove();
    test_clear();
    test_assign_with_iterators();
    test_assign_with_number_of_elements();
    test_assign_with_initializer_list();
    test_iterator();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}

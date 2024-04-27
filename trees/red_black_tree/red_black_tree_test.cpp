#include <cassert>
#include <iostream>

#include "red_black_tree.hpp"

void test_insertion() {
    red_black_tree<int> tree;
    tree.insert_node(10);
    tree.insert_node(20);
    tree.insert_node(5);
    tree.insert_node(15);
    tree.insert_node(30);
    tree.insert_node(3);
    tree.insert_node(7);
    // Verify tree structure after insertion
    assert(tree.search_node(10) == 10);
    assert(tree.search_node(20) == 20);
    assert(tree.search_node(5) == 5);
    assert(tree.search_node(15) == 15);
    assert(tree.search_node(30) == 30);
    assert(tree.search_node(3) == 3);
    assert(tree.search_node(7) == 7);
}

void test_deletion() {
    red_black_tree<int> tree;
    tree.insert_node(10);
    tree.insert_node(20);
    tree.insert_node(5);
    tree.insert_node(15);
    tree.insert_node(30);
    tree.insert_node(3);
    tree.insert_node(7);

    tree.delete_node(15);
    tree.delete_node(5);
    tree.delete_node(7);

    // Verify tree structure after deletion
    assert(tree.search_node(10) == 10);
    assert(tree.search_node(20) == 20);
    assert(tree.search_node(15) == 0); // 15 should be deleted
    assert(tree.search_node(5) == 0);  // 5 should be deleted
    assert(tree.search_node(30) == 30);
    assert(tree.search_node(3) == 3);
    assert(tree.search_node(7) == 0);  // 7 should be deleted
}

void test_search() {
    red_black_tree<int> tree;
    tree.insert_node(10);
    tree.insert_node(20);
    tree.insert_node(5);
    tree.insert_node(15);
    tree.insert_node(30);
    tree.insert_node(3);
    tree.insert_node(7);

    // Verify search functionality
    assert(tree.search_node(15) == 15);
    assert(tree.search_node(5) == 5);
    assert(tree.search_node(7) == 7);
    assert(tree.search_node(25) == 0); // Node with value 25 doesn't exist
}

int main() {
    test_insertion();
    test_deletion();
    test_search();
    
    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}

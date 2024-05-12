#include <cassert>
#include <iostream>

#include "red_black_tree.hpp"
#include "../binary_tree_printer/binary_tree_printer.hpp"

void test_constructor() {
    // Initialize Red-Black Tree using initializer list
    my_stl::red_black_tree<int> tree = {5, 3, 8, 2, 4, 7, 9};

    // // Check the size of the tree
    // assert(tree.size() == 7);

    // Check the elements of the tree
    std::vector<int> expected = {2, 3, 4, 5, 7, 8, 9};
    int i = 0;
    for (auto it = tree.begin(); it != tree.end(); ++it) {
        assert(*it == expected[i]);
        ++i;
    }
}

void test_insert_node() {
    // Create a Red-Black Tree instance
    my_stl::red_black_tree<int> tree;

    // Insert elements into the tree
    tree.insert_node(10);
    tree.insert_node(20);
    tree.insert_node(5);
    tree.insert_node(15);

    // Verify that the elements have been inserted correctly
    assert(tree.search_node(10) == 10);
    assert(tree.search_node(20) == 20);
    assert(tree.search_node(5) == 5);
    assert(tree.search_node(15) == 15);
}

void test_delete_node() {
    // Create a Red-Black Tree instance
    my_stl::red_black_tree<int> tree;

    // Insert elements into the tree
    tree.insert_node(10);
    tree.insert_node(20);
    tree.insert_node(5);
    tree.insert_node(15);

    // Delete an element from the tree
    tree.delete_node(5);

    // Verify that the deleted element is not present in the tree
    try {
        tree.search_node(5);
        // If the search doesn't throw an exception, the element is still present, which is incorrect
        assert(false);
    } catch (const my_stl::runtime_error& e) {
        // If a runtime_error exception is thrown, it indicates that the element has been successfully deleted
        assert(true);
    }
}

void test_search_node() {
    // Create a Red-Black Tree instance
    my_stl::red_black_tree<int> tree;

    // Insert elements into the tree
    tree.insert_node(10);
    tree.insert_node(20);
    tree.insert_node(5);

    // Test search using reference
    {
        // Search for an existing element in the tree
        int& found_value_ref = tree.search_node(20);
        assert(found_value_ref == 20);

        // Modify the found value
        found_value_ref = 30;

        // Ensure modification reflects in the tree
        int new_value = tree.search_node(30);
        assert(new_value == 30);
    }

    // Test search using const_reference
    {
        // Search for an existing element in the tree
        const my_stl::red_black_tree<int>& const_tree = tree;
        const int& found_value_const_ref = const_tree.search_node(5);
        assert(found_value_const_ref == 5);

        // Ensure modification does not affect the tree
        int new_value = tree.search_node(5);
        assert(new_value == 5);
    }

    // Test search for non-existing element
    try {
        tree.search_node(100); // Element does not exist
        assert(false); // This line should not be executed
    } catch (const my_stl::runtime_error& e) {
        // Exception should be caught
        assert(std::string(e.what()) == "node not found");
    }
}

void test_begin() {
    my_stl::red_black_tree<int> rb_tree;
    rb_tree.insert_node(5);
    rb_tree.insert_node(3);
    rb_tree.insert_node(7);

    // Testing non-const begin()
    auto it = rb_tree.begin();
    assert(*it == 3); // Check if it points to the first element

    // Testing const begin()
    const my_stl::red_black_tree<int>& const_rb_tree = rb_tree;
    auto const_it = const_rb_tree.begin();
    assert(*const_it == 3); // Check if it points to the first element in const tree
}

void test_end() {
    my_stl::red_black_tree<int> tree;

    // Inserting elements into the tree
    for (int i = 1; i <= 1000; ++i) {
        tree.insert_node(i);
    }

    // Looping through the elements using iterators
    int expected_value = 1;
    for (auto it = tree.begin(); it != tree.end(); ++it) {
        assert(*it == expected_value++);
    }

    // Looping through the elements using const iterators
    const auto& const_tree = tree;
    expected_value = 1;
    for (auto it = const_tree.begin(); it != const_tree.end(); ++it) {
        assert(*it == expected_value++);
    }
}

void test_cbegin() {
    my_stl::red_black_tree<int> tree;

    // Insert some elements into the tree
    tree.insert_node(5);
    tree.insert_node(3);
    tree.insert_node(7);

    // Obtain a constant iterator pointing to the first element
    auto it = tree.cbegin();

    // Check if the first element is correct
    assert(*it == 3);
}

void test_cend() {
    my_stl::red_black_tree<int> tree;

    // Insert some elements into the tree
    tree.insert_node(5);
    tree.insert_node(3);
    tree.insert_node(7);
    tree.insert_node(1);
    tree.insert_node(4);

    // Expected values in ascending order
    std::vector<int> expected_values = {1, 3, 4, 5, 7};
    
    // Loop through the elements using a constant iterator
    int index = 0;
    for (auto it = tree.cbegin(); it != tree.cend(); ++it) {
        assert(*it == expected_values[index]);
        ++index;
    }
}

void test_rbegin() {
    // Create a Red-Black Tree with some elements
    my_stl::red_black_tree<int> tree;
    tree.insert_node(1);
    tree.insert_node(2);
    tree.insert_node(3);

    // Check the reverse iterator using the non-const version of rbegin()
    assert(*tree.rbegin() == 3);

    // Check the reverse iterator using the const version of rbegin()
    const my_stl::red_black_tree<int>& const_tree = tree;
    assert(*const_tree.rbegin() == 3);
}

void test_rend() {
    // Create a Red-Black Tree with some elements
    my_stl::red_black_tree<int> tree;
    tree.insert_node(1);
    tree.insert_node(2);
    tree.insert_node(3);

    // Iterate through the Red-Black Tree using reverse iterators and assert
    int expected = 3;
    for (auto rit = tree.rbegin(); rit != tree.rend(); ++rit) {
        assert(*rit == expected);
        --expected;
    }
}

void test_crbegin() {
    // Create a Red-Black Tree with some elements
    my_stl::red_black_tree<int> tree;
    tree.insert_node(1);
    tree.insert_node(2);
    tree.insert_node(3);

    // Check the const reverse iterator using crbegin()
    int expected = 3;
    for (auto crit = tree.crbegin(); crit != tree.crend(); ++crit) {
        assert(*crit == expected);
        --expected;
    }
}

void test_crend() {
    // Create a Red-Black Tree with some elements
    my_stl::red_black_tree<int> tree;
    tree.insert_node(1);
    tree.insert_node(2);
    tree.insert_node(3);

    // Check the const reverse iterator using crend()
    int expected = 3; // As crend points to position just before the first element
    for (auto crit = tree.crbegin(); crit != tree.crend(); ++crit) {
        assert(*crit == expected);
        --expected;
    }
}

void test_red_black_tree() {
    test_constructor();
    test_insert_node();
    test_delete_node();
    test_search_node();
    test_begin();
    test_end();
    test_cbegin();
    test_cend();
    test_rbegin();
    test_rend();
    test_crbegin();
    test_crend();
}

int main() {
    test_red_black_tree();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}

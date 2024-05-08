#include<iostream>
#include <cassert>

#include "forward_list.hpp" // Include the header file where forward_list implementation is defined.
#include "../utility/move.hpp" // Include the header file where move function implementation is defined.
#include "../utility/distance.hpp" // Include the header file where distance function implementation is defined.
#include "../utility/advance.hpp" // Include the header file where advance function implementation is defined.

void test_default_constructor() {
    my_stl::forward_list<int> my_list; // Create an empty forward_list using the default constructor
    assert(my_list.empty()); // Check if the list is empty
}

void test_initializer_list_constructor() {
    // Create an initializer list with some values
    std::initializer_list<int> values = {1, 2, 3, 4, 5};
    
    // Create a forward_list using the initializer list constructor
    my_stl::forward_list<int> my_list(values);

    // Loop through the values and check if they are present in the list
    for (int value : values) {
        assert(my_list.front() == value); // Check if the front element matches the expected value
        my_list.pop_front(); // Remove the checked element from the list
    }

    assert(my_list.empty()); // Check if the list is empty after removing all elements
}

void test_copy_constructor() {
    // Create a forward_list with some elements
    my_stl::forward_list<int> original_list;
    original_list.push_front(1);
    original_list.push_front(2);
    original_list.push_front(3);

    // Create a copy of the original list using the copy constructor
    my_stl::forward_list<int> copied_list(original_list);

    // Iterate through both lists and check if the elements match
    auto original_iter = original_list.begin();
    auto copied_iter = copied_list.begin();
    while (original_iter != original_list.end() && copied_iter != copied_list.end()) {
        assert(*original_iter == *copied_iter); // Check if corresponding elements match
        ++original_iter;
        ++copied_iter;
    }

    // Check if both iterators reached the end simultaneously, indicating the lists have the same length
    assert(original_iter == original_list.end() && copied_iter == copied_list.end());
}

void test_move_constructor() {
    // Create a forward_list with some elements
    my_stl::forward_list<int> original_list;
    original_list.push_front(1);
    original_list.push_front(2);
    original_list.push_front(3);

    // Move the original list into a new list using the move constructor
    my_stl::forward_list<int> moved_list(my_stl::move(original_list));

    // Check if the original list is now empty
    assert(original_list.empty());

    // Iterate through the moved list and check if the elements match the original list
    auto moved_iter = moved_list.begin();
    int expected_value = 3; // Start with the last element added to the original list
    while (moved_iter != moved_list.end()) {
        assert(*moved_iter == expected_value); // Check if the element matches the expected value
        --expected_value; // Move to the previous value in the original list
        ++moved_iter; // Move to the next element in the moved list
    }
}

void test_push_front() {
    // Create a forward_list
    my_stl::forward_list<int> my_list;

    // Test push_front(const_reference val)
    my_list.push_front(3);
    assert(my_list.front() == 3); // Check if the front element is 3

    // Test push_front(T&& val)
    int x = 5;
    my_list.push_front(my_stl::move(x)); // Move x into the list
    assert(my_list.front() == 5); // Check if the front element is 5
}

void test_pop_front() {
    // Create a forward_list with some elements
    my_stl::forward_list<int> my_list;
    my_list.push_front(3);
    my_list.push_front(2);
    my_list.push_front(1);

    // Remove the first element from the list
    my_list.pop_front();

    // Verify that the first element has been removed
    assert(my_list.front() == 2);

    // Remove another element
    my_list.pop_front();

    // Verify that the first element has been removed
    assert(my_list.front() == 3);

    // Remove the last element
    my_list.pop_front();

    // Verify that the list is now empty
    assert(my_list.empty());
}

void test_clear() {
    // Create a forward_list with some elements
    my_stl::forward_list<int> my_list;
    my_list.push_front(3);
    my_list.push_front(2);
    my_list.push_front(1);

    // Clear the list
    my_list.clear();

    // Verify that the list is empty after clearing
    assert(my_list.empty());
}

void test_assign() {
    // Test assign(iterator first, iterator last)
    my_stl::forward_list<int> my_list1;
    my_list1.push_front(1);
    my_list1.push_front(2);
    my_list1.push_front(3);

    my_stl::forward_list<int> my_list2;
    my_list2.assign(my_list1.begin(), my_list1.end());
    assert(my_list1 == my_list2);

    // Test assign(size_type count, const_reference val)
    my_stl::forward_list<int> my_list3;
    my_list3.assign(5, 10);
    assert(my_list3.front() == 10);

    // Test assign(const std::initializer_list<value_type>& values)
    my_stl::forward_list<int> my_list4;
    my_list4.assign({1, 2, 3, 4, 5});
    assert(my_list4.front() == 1);
}

void test_front() {
    // Create a forward_list with some elements
    my_stl::forward_list<int> my_list;
    my_list.push_front(3);
    my_list.push_front(2);
    my_list.push_front(1);

    // Test front() function
    assert(my_list.front() == 1); // Verify if the front element is correct

    // Test const front() function (for const objects)
    const my_stl::forward_list<int> const_list(my_list); // Create a const version of the list
    assert(const_list.front() == 1); // Verify if the const front element is correct
}

void test_begin() {
    // Create a forward_list with some elements
    my_stl::forward_list<int> my_list;
    my_list.push_front(1);
    my_list.push_front(2);
    my_list.push_front(3);

    // Test begin() function
    assert(*my_list.begin() == 3); // Verify if the first element is correct

    // Test const begin() function (for const objects)
    const my_stl::forward_list<int> const_list(my_list); // Create a const version of the list
    assert(*const_list.begin() == 3); // Verify if the const first element is correct
}

void test_cbegin() {
    // Create a forward_list with some elements
    my_stl::forward_list<int> my_list;
    my_list.push_front(1);
    my_list.push_front(2);
    my_list.push_front(3);

    // Test cbegin() function
    assert(*my_list.cbegin() == 3); // Verify if the first element is correct
}

void test_cend() {
    // Create a forward_list with some elements
    my_stl::forward_list<int> my_list;
    my_list.push_front(1);
    my_list.push_front(2);
    my_list.push_front(3);

    // Test cend() function
    assert(my_list.cend() == nullptr); // Verify if the past-the-end iterator is correct
}

void test_before_begin() {
    // Create a forward_list with some elements
    my_stl::forward_list<int> my_list;
    my_list.push_front(1);
    my_list.push_front(2);
    my_list.push_front(3);

    // Test const_iterator before_begin()
    my_stl::forward_list<int>::iterator non_const_iterator = my_list.before_begin();
    ++non_const_iterator;
    assert(*non_const_iterator == 3); // Verify if the before-beginning element is correct for const objects

    // Test before_begin() const
    const my_stl::forward_list<int>& const_list = my_list; // Create a const reference to the list
    my_stl::forward_list<int>::const_iterator const_iterator = const_list.before_begin();
    ++const_iterator;
    assert(*const_iterator == 3); // Verify if the before-beginning element is correct for non-const objects
}

void test_cbefore_begin() {
    // Create a forward_list with some elements
    my_stl::forward_list<int> my_list;
    my_list.push_front(1);
    my_list.push_front(2);
    my_list.push_front(3);

    // Test cbefore_begin() for const objects
    const my_stl::forward_list<int>& const_list = my_list; // Create a const reference to the list
    my_stl::forward_list<int>::const_iterator const_iterator = const_list.cbefore_begin();
    ++const_iterator;
    assert(*const_iterator == 3); // Verify if the before-beginning element is correct for const objects
}

void test_end() {
    // Create a forward_list with some elements
    my_stl::forward_list<int> my_list;
    my_list.push_front(1);
    my_list.push_front(2);
    my_list.push_front(3);

    // Test end() function
    my_stl::forward_list<int>::iterator it = my_list.end();
    assert(it == my_list.end()); // Verify if the iterator correctly points to the end of the list

    // Test end() const function
    const my_stl::forward_list<int>& const_list = my_list; // Create a const reference to the list
    my_stl::forward_list<int>::const_iterator const_it = const_list.end();
    assert(const_it == const_list.end()); // Verify if the const iterator correctly points to the end of the list
}

void test_empty() {
    // Create an empty forward_list
    my_stl::forward_list<int> empty_list;

    // Verify if empty() returns true for an empty list
    assert(empty_list.empty());

    // Create a forward_list with elements
    my_stl::forward_list<int> non_empty_list;
    non_empty_list.push_front(1);
    non_empty_list.push_front(2);
    non_empty_list.push_front(3);

    // Verify if empty() returns false for a non-empty list
    assert(!non_empty_list.empty());
}

void test_emplace_after() {
    // Create a forward_list with some elements
    my_stl::forward_list<int> my_list;
    my_list.push_front(1);
    my_list.push_front(2);
    my_list.push_front(3);

    // Insert a new element after the second position
    my_stl::forward_list<int>::iterator it = my_list.emplace_after(my_list.cbegin(), 4);

    // Verify if the list contains the newly inserted element
    assert(*it == 4);

    // Verify if the size of the list has increased by one
    assert(my_stl::distance(my_list.begin(), my_list.end()) == 4);
}

void test_emplace_front() {
    // Create a forward_list with some elements
    my_stl::forward_list<int> my_list;
    my_list.push_front(1);
    my_list.push_front(2);
    my_list.push_front(3);

    // Insert a new element at the front of the list
    my_list.emplace_front(0);

    // Verify if the list contains the newly inserted element at the front
    assert(my_list.front() == 0);

    // Verify if the size of the list has increased by one
    assert(my_stl::distance(my_list.begin(), my_list.end()) == 4);
}

void test_erase_after() {
    // Create a forward_list with some elements
    my_stl::forward_list<int> my_list;
    my_list.push_front(1);
    my_list.push_front(2);
    my_list.push_front(3);
    my_list.push_front(4);
    my_list.push_front(5);

    // Test erase_after(const_iterator position)
    // Erase the element following the second element (value 4)
    auto it1 = my_list.erase_after(my_list.cbegin());
    assert(*it1 == 3); // Verify if the iterator points to the correct element after erasing

    // Test erase_after(const_iterator first, const_iterator last)
    // Erase the elements after the second and third elements (values 4 and 3)
    auto it2 = my_list.erase_after(my_list.cbegin(), ++++my_list.cbegin());
    assert(*it2 == 2); // Verify if the iterator points to the correct element after erasing

    // Verify if the list is correctly modified after erasing
    assert(my_list.front() == 5);
    assert(my_stl::distance(my_list.begin(), my_list.end()) == 3); // Check if the list size is updated correctly
}

void test_insert_after() {
    // Create a forward_list with some elements
    my_stl::forward_list<int> my_list;
    my_list.push_front(1);
    my_list.push_front(2);

    // Test insert_after(const_iterator position, const_reference val)
    auto it1 = my_list.insert_after(my_list.cbegin(), 3); // Insert 3 after the first element
    assert(*it1 == 3); // Verify if the iterator points to the correct element after insertion

    // Test insert_after(const_iterator position, size_type count, const_reference val)
    my_list.insert_after(my_list.cbegin(), 2, 4); // Insert 4 after the first element twice
    assert(*++my_list.begin() == 4); // Verify if the second element is 4

    // Test insert_after(const_iterator position, const std::initializer_list<value_type>& values)
    my_list.insert_after(++my_list.cbegin(), {5, 6}); // Insert 5 and 6 after the second element
    auto it2 = my_list.begin();
    my_stl::advance(it2, 2);
    assert(*it2 == 5); // Verify if the third element is 5
    assert(*++it2 == 6); // Verify if the fourth element is 6

    // Test insert_after(const_iterator position, value_type&& val)
    my_list.insert_after(my_list.cbefore_begin(), 0); // Insert 0 before the first element
    assert(*my_list.begin() == 0); // Verify if the first element is 0
}

void test_remove() {
    // Create a forward_list with some elements
    my_stl::forward_list<int> my_list;
    my_list.push_front(1);
    my_list.push_front(2);
    my_list.push_front(3);
    my_list.push_front(2); // Add another '2' to test removal of duplicates

    // Remove element '2' from the list
    my_list.remove(2);

    // Check if the element '2' has been removed
    // It should only appear once after removal
    int count_of_2 = 0;
    for (auto it = my_list.begin(); it != my_list.end(); ++it) {
        if (*it == 2) {
            count_of_2++;
        }
    }
    assert(count_of_2 == 0);

    // Check if other elements are intact
    assert(my_list.front() == 3); // After removal, the first element should be '3'
}

void test_remove_if() {
    // Create a forward_list with some elements
    my_stl::forward_list<int> my_list;
    my_list.push_front(1);
    my_list.push_front(2);
    my_list.push_front(3);
    my_list.push_front(4);

    // Remove all even numbers from the list
    my_list.remove_if([](int x) { return x % 2 == 0; });

    // Check if even numbers have been removed
    for (auto it = my_list.begin(); it != my_list.end(); ++it) {
        assert(*it % 2 != 0);
    }
}

void test_reverse() {
    // Create a forward_list with some elements
    my_stl::forward_list<int> my_list;
    my_list.push_front(1);
    my_list.push_front(2);
    my_list.push_front(3);

    // Call the reverse function
    my_list.reverse();

    // Verify if the order of elements has been reversed correctly
    assert(my_list.front() == 1);  // After reversal, the last element becomes the first
    my_list.pop_front();           // Remove the first element
    assert(my_list.front() == 2);  // After removal, the next element should be the second
    my_list.pop_front();           // Remove the second element
    assert(my_list.front() == 3);  // After removal, the next element should be the third
    my_list.pop_front();           // Remove the last element
    assert(my_list.empty());       // After all removals, the list should be empty
}

void test_merge() {
    // Test merge(forward_list<value_type>& right)
    {
        // Create two forward_lists with some elements
        my_stl::forward_list<int> list1 = {1, 3, 5};
        my_stl::forward_list<int> list2 = {2, 4, 6};

        // Call the merge function
        list1.merge(list2);

        // Verify if the merge operation was successful
        assert(list1 == my_stl::forward_list<int>({1, 2, 3, 4, 5, 6})); // Merged list should be sorted
        assert(list2.empty());  // The second list should be empty after merging
    }

    // Test merge(forward_list<value_type>& right, Predicate predicate)
    {
        // Create two forward_lists with some elements
        my_stl::forward_list<int> list1 = {1, 3, 5};
        my_stl::forward_list<int> list2 = {2, 4, 6};

        // Define a custom predicate to merge lists in descending order
        auto compare_descending = [](int a, int b) { return a > b; };

        // Call the merge function with the custom predicate
        list1.merge(list2, compare_descending);

        // Verify if the merge operation was successful with the custom predicate
        assert(list1 == my_stl::forward_list<int>({2, 4, 6, 1, 3, 5})); // Merged list should be in descending order
        assert(list2.empty());  // The second list should be empty after merging
    }
}

void test_sort() {
    // Test case 1: Sorted List
    {
        my_stl::forward_list<int> list = {1, 2, 3, 4, 5};
        list.sort();
        assert(list == my_stl::forward_list<int>({1, 2, 3, 4, 5}));
    }

    // Test case 2: Reverse Sorted List
    {
        my_stl::forward_list<int> list = {5, 4, 3, 2, 1};
        list.sort();
        assert(list == my_stl::forward_list<int>({1, 2, 3, 4, 5}));
    }

    // Test case 3: Unsorted List
    {
        my_stl::forward_list<int> list = {9, 2, 7, 3, 1, 8, 5, 6, 4};
        list.sort();
        assert(list == my_stl::forward_list<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
    }

    // Test case 4: Empty List
    {
        my_stl::forward_list<int> list;
        list.sort();
        assert(list.empty());
    }

    // Test case 5: List with One Element
    {
        my_stl::forward_list<int> list = {1};
        list.sort();
        assert(list == my_stl::forward_list<int>({1}));
    }

    // Add more test cases as needed
}

void test_swap() {
    // Test case 1: Swap two non-empty lists
    {
        my_stl::forward_list<int> list1 = {1, 2, 3};
        my_stl::forward_list<int> list2 = {4, 5, 6};
        
        list1.swap(list2);

        assert(list1 == my_stl::forward_list<int>({4, 5, 6}));
        assert(list2 == my_stl::forward_list<int>({1, 2, 3}));
    }

    // Test case 2: Swap with an empty list
    {
        my_stl::forward_list<int> list1 = {1, 2, 3};
        my_stl::forward_list<int> list2;
        
        list1.swap(list2);

        assert(list1 == my_stl::forward_list<int>());
        assert(list2 == my_stl::forward_list<int>({1, 2, 3}));
    }

    // Test case 3: Swap with both empty lists
    {
        my_stl::forward_list<int> list1;
        my_stl::forward_list<int> list2;
        
        list1.swap(list2);

        assert(list1 == my_stl::forward_list<int>());
        assert(list2 == my_stl::forward_list<int>());
    }
}

void test_unique() {
    // Test case 1: Remove consecutive duplicate elements
    {
        my_stl::forward_list<int> list = {1, 1, 2, 2, 3, 3, 4, 5, 5};
        list.unique();
        assert(list == my_stl::forward_list<int>({1, 2, 3, 4, 5}));
    }

    // Test case 2: No duplicates to remove
    {
        my_stl::forward_list<int> list = {1, 2, 3, 4, 5};
        list.unique();
        assert(list == my_stl::forward_list<int>({1, 2, 3, 4, 5}));
    }

    // Test case 3: All elements are duplicates
    {
        my_stl::forward_list<int> list = {1, 1, 1, 1, 1};
        list.unique();
        assert(list == my_stl::forward_list<int>({1}));
    }

    // Test case 4: Empty list
    {
        my_stl::forward_list<int> list;
        list.unique();
        assert(list == my_stl::forward_list<int>());
    }
}

void test_resize() {
    // Test case 1: Resize to a smaller size
    {
        my_stl::forward_list<int> list = {1, 2, 3, 4, 5};
        list.resize(3);
        assert(list == my_stl::forward_list<int>({1, 2, 3}));
    }

    // Test case 2: Resize to a larger size with default value
    {
        my_stl::forward_list<int> list = {1, 2, 3};
        list.resize(5);
        assert(list == my_stl::forward_list<int>({1, 2, 3, 0, 0}));
    }

    // Test case 3: Resize to a larger size with specific value
    {
        my_stl::forward_list<int> list = {1, 2, 3};
        list.resize(5, 10);
        assert(list == my_stl::forward_list<int>({1, 2, 3, 10, 10}));
    }

    // Test case 4: Resize to the same size
    {
        my_stl::forward_list<int> list = {1, 2, 3};
        list.resize(3);
        assert(list == my_stl::forward_list<int>({1, 2, 3}));
    }

    // Test case 5: Resize to a smaller size than the current size
    {
        my_stl::forward_list<int> list = {1, 2, 3};
        list.resize(1);
        assert(list == my_stl::forward_list<int>({1}));
    }

    // Test case 6: Resize an empty list
    {
        my_stl::forward_list<int> list;
        list.resize(3, 5);
        assert(list == my_stl::forward_list<int>({5, 5, 5}));
    }
}

void test_assignment_operator() {
    // Test case 1: Assign a non-empty list to an empty list
    {
        my_stl::forward_list<int> list1;
        my_stl::forward_list<int> list2 = {1, 2, 3, 4, 5};
        list1 = list2;
        assert(list1 == list2);
    }

    // Test case 2: Self-assignment
    {
        my_stl::forward_list<int> list = {1, 2, 3};
        list = list; // Self-assignment
        assert(list == my_stl::forward_list<int>({1, 2, 3})); // No change expected
    }

    // Test case 3: Assign an empty list to a non-empty list
    {
        my_stl::forward_list<int> list1 = {1, 2, 3, 4, 5};
        my_stl::forward_list<int> list2;
        list1 = list2;
        assert(list1 == my_stl::forward_list<int>()); // Empty list expected
    }

    // Test case 4: Assign a list to itself with different elements
    {
        my_stl::forward_list<int> list = {1, 2, 3};
        my_stl::forward_list<int> originalList = list;
        list = {4, 5, 6}; // Assigning different elements
        assert(list != originalList); // Should not be equal after assignment
    }
}

void test_move_assignment_operator() {
    // Test case 1: Move assignment from a non-empty list to an empty list
    {
        my_stl::forward_list<int> list1;
        my_stl::forward_list<int> list2 = {1, 2, 3, 4, 5};
        list1 = my_stl::move(list2);
        assert(list1 == my_stl::forward_list<int>({1, 2, 3, 4, 5}));
        assert(list2.empty()); // After move assignment, list2 should be empty
    }

    // Test case 2: Self-move assignment
    {
        my_stl::forward_list<int> list = {1, 2, 3};
        list = my_stl::move(list); // Self-move assignment
        assert(list == my_stl::forward_list<int>({1, 2, 3})); // No change expected
    }

    // Test case 3: Move assignment from a non-empty list to a non-empty list
    {
        my_stl::forward_list<int> list1 = {1, 2, 3};
        my_stl::forward_list<int> list2 = {4, 5, 6};
        list1 = my_stl::move(list2);
        assert(list1 == my_stl::forward_list<int>({4, 5, 6}));
        assert(list2.empty()); // After move assignment, list2 should be empty
    }

    // Test case 4: Move assignment from an empty list to a non-empty list
    {
        my_stl::forward_list<int> list1 = {1, 2, 3};
        my_stl::forward_list<int> list2;
        list1 = my_stl::move(list2);
        assert(list1 == my_stl::forward_list<int>()); // list1 should become empty
        assert(list2.empty()); // list2 is already empty
    }
}

void test_equality_operator() {
    // Test case 1: Equality between two empty lists
    {
        my_stl::forward_list<int> list1;
        my_stl::forward_list<int> list2;
        assert(list1 == list2);
    }

    // Test case 2: Equality between two non-empty lists with the same elements
    {
        my_stl::forward_list<int> list1 = {1, 2, 3};
        my_stl::forward_list<int> list2 = {1, 2, 3};
        assert(list1 == list2);
    }
}

void test_inequality_operator() {
    // Test case 1: Inequality between an empty list and a non-empty list
    {
        my_stl::forward_list<int> list1;
        my_stl::forward_list<int> list2 = {1, 2, 3};
        assert(list1 != list2);
    }

    // Test case 2: Inequality between two non-empty lists with different elements
    {
        my_stl::forward_list<int> list1 = {1, 2, 3};
        my_stl::forward_list<int> list2 = {4, 5, 6};
        assert(list1 != list2);
    }
}

void test_operator_less_than() {
    // Test case 1: Lists with same elements but different lengths
    {
        my_stl::forward_list<int> list1 = {1, 2, 3};
        my_stl::forward_list<int> list2 = {1, 2, 3, 4};
        assert(list1 < list2);
        assert(!(list2 < list1));
    }

    // Test case 2: Lists with same elements in different order
    {
        my_stl::forward_list<int> list1 = {1, 2, 3};
        my_stl::forward_list<int> list2 = {3, 2, 1};
        assert(list1 < list2);
        assert(!(list2 < list1));
    }

    // Test case 3: Empty list compared to non-empty list
    {
        my_stl::forward_list<int> list1;
        my_stl::forward_list<int> list2 = {1, 2, 3};
        assert(list1 < list2);
        assert(!(list2 < list1));
    }

    // Test case 4: Two empty lists
    {
        my_stl::forward_list<int> list1;
        my_stl::forward_list<int> list2;
        assert(!(list1 < list2));
        assert(!(list2 < list1));
    }
}

void test_operator_greater_than() {
    // Test case 1: Lists with same elements but different lengths
    {
        my_stl::forward_list<int> list1 = {1, 2, 3};
        my_stl::forward_list<int> list2 = {1, 2, 3, 4};
        assert(list2 > list1); // list2 is considered greater than list1
        assert(!(list1 > list2)); // list1 is not greater than list2
    }

    // Test case 2: Lists with same elements in different order
    {
        my_stl::forward_list<int> list1 = {1, 2, 3};
        my_stl::forward_list<int> list2 = {3, 2, 1};
        assert(list2 > list1); // list2 is considered greater than list1
        assert(!(list1 > list2)); // list1 is not greater than list2
    }

    // Test case 3: Empty list compared to non-empty list
    {
        my_stl::forward_list<int> list1;
        my_stl::forward_list<int> list2 = {1, 2, 3};
        assert(list2 > list1); // Non-empty list is considered greater than empty list
        assert(!(list1 > list2)); // Empty list is not greater than non-empty list
    }

    // Test case 4: Two empty lists
    {
        my_stl::forward_list<int> list1;
        my_stl::forward_list<int> list2;
        assert(!(list1 > list2)); // Empty lists are not greater than each other
        assert(!(list2 > list1)); // Empty lists are not greater than each other
    }
}

void test_operator_greater_than_or_equal() {
    // Test case 1: Lists with same elements but different lengths
    {
        my_stl::forward_list<int> list1 = {1, 2, 3};
        my_stl::forward_list<int> list2 = {1, 2, 3, 4};
        assert(!(list1 >= list2)); // list1 is not greater than or equal to list2
        assert(list2 >= list1); // list2 is greater than or equal to list1
    }

    // Test case 2: Lists with same elements in different order
    {
        my_stl::forward_list<int> list1 = {1, 2, 3};
        my_stl::forward_list<int> list2 = {3, 2, 1};
        assert(!(list1 >= list2)); // list1 is not greater than or equal to list2
        assert(list2 >= list1); // list2 is greater than or equal to list1
    }

    // Test case 3: Empty list compared to non-empty list
    {
        my_stl::forward_list<int> list1;
        my_stl::forward_list<int> list2 = {1, 2, 3};
        assert(!(list1 >= list2)); // Empty list is not greater than or equal to non-empty list
        assert(list2 >= list1); // Non-empty list is greater than or equal to empty list
    }

    // Test case 4: Two empty lists
    {
        my_stl::forward_list<int> list1;
        my_stl::forward_list<int> list2;
        assert(list1 >= list2); // Empty lists are greater than or equal to each other
        assert(list2 >= list1); // Empty lists are greater than or equal to each other
    }

    // Test case 5: Lists with equal elements
    {
        my_stl::forward_list<int> list1 = {1, 2, 3};
        my_stl::forward_list<int> list2 = {1, 2, 3};
        assert(list1 >= list2); // list1 is greater than or equal to list2
        assert(list2 >= list1); // list2 is greater than or equal to list1
    }
}

void test_operator_less_than_or_equal() {
    // Test case 1: Lists with same elements but different lengths
    {
        my_stl::forward_list<int> list1 = {1, 2, 3};
        my_stl::forward_list<int> list2 = {1, 2, 3, 4};
        assert(list1 <= list2); // list1 is less than or equal to list2
        assert(!(list2 <= list1)); // list2 is not less than or equal to list1
    }

    // Test case 2: Lists with same elements in different order
    {
        my_stl::forward_list<int> list1 = {1, 2, 3};
        my_stl::forward_list<int> list2 = {3, 2, 1};
        assert(list1 <= list2); // list1 is less than or equal to list2
        assert(!(list2 <= list1)); // list2 is not less than or equal to list1
    }

    // Test case 3: Empty list compared to non-empty list
    {
        my_stl::forward_list<int> list1;
        my_stl::forward_list<int> list2 = {1, 2, 3};
        assert(list1 <= list2); // Empty list is less than or equal to non-empty list
        assert(!(list2 <= list1)); // Non-empty list is not less than or equal to empty list
    }

    // Test case 4: Two empty lists
    {
        my_stl::forward_list<int> list1;
        my_stl::forward_list<int> list2;
        assert(list1 <= list2); // Empty lists are less than or equal to each other
        assert(list2 <= list1); // Empty lists are less than or equal to each other
    }

    // Test case 5: Lists with equal elements
    {
        my_stl::forward_list<int> list1 = {1, 2, 3};
        my_stl::forward_list<int> list2 = {1, 2, 3};
        assert(list1 <= list2); // list1 is less than or equal to list2
        assert(list2 <= list1); // list2 is less than or equal to list1
    }
}

void test_splice_after() {
    // Test case 1: Splicing a non-empty list into an empty list at the beginning
    {
        my_stl::forward_list<int> list1;
        my_stl::forward_list<int> list2 = {1, 2, 3};
        auto it = list1.cbefore_begin();
        list1.splice_after(it, list2);
        assert(list1 == my_stl::forward_list<int>({1, 2, 3}));
        assert(list2.empty());
    }

    // Test case 2: Splicing a non-empty list into another non-empty list in the middle
    {
        my_stl::forward_list<int> list1 = {1, 2, 3};
        my_stl::forward_list<int> list2 = {4, 5, 6};
        auto it = list1.cbegin();
        ++it; // pointing to the second element
        list1.splice_after(it, list2);
        assert(list1 == my_stl::forward_list<int>({1, 2, 4, 5, 6, 3}));
        assert(list2.empty());
    }

    // Test case 3: Splicing an empty list into another list
    {
        my_stl::forward_list<int> list1 = {1, 2, 3};
        my_stl::forward_list<int> list2;
        auto it = list1.cbefore_begin();
        list1.splice_after(it, list2);
        assert(list1 == my_stl::forward_list<int>({1, 2, 3}));
        assert(list2.empty());
    }
}

void test_forward_list() {
    test_default_constructor();
    test_initializer_list_constructor();
    test_copy_constructor();
    test_move_constructor();
    test_push_front();
    test_pop_front();
    test_clear();
    test_assign();
    test_front();
    test_begin();
    test_cbegin();
    test_cend();
    test_before_begin();
    test_cbefore_begin();
    test_end();
    test_empty();
    test_emplace_after();
    test_emplace_front();
    test_erase_after();
    test_insert_after();
    test_remove();
    test_remove_if();
    test_reverse();
    test_merge();
    test_sort();
    test_swap();
    test_unique();
    test_resize();
    test_assignment_operator();
    test_move_assignment_operator();
    test_equality_operator();
    test_inequality_operator();
    test_operator_less_than();
    test_operator_greater_than();
    test_operator_greater_than_or_equal();
    test_operator_less_than_or_equal();
    test_splice_after();
}

int main() {
    test_forward_list();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}

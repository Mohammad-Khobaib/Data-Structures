#include <cassert>
#include <iostream>
#include <string>

#include "vector.hpp"
#include "../utility/move.hpp"
#include "../exceptions/out_of_range/out_of_range.hpp"

void test_constructor() {
    // Test case for default constructor
    {
        my_stl::vector<int> vec;
        assert(vec.size() == 0 && "Size mismatch for default constructor");
        assert(vec.capacity() == 0 && "Capacity mismatch for default constructor");
        assert(vec.empty() && "Vector should be empty after default construction");
    }

    // Test case for constructor with initializer list
    {
        my_stl::vector<int> vec = {1, 2, 3};
        assert(vec.size() == 3 && "Size mismatch for initializer list constructor");
        assert(vec.capacity() >= 3 && "Capacity mismatch for initializer list constructor");
        assert(vec[0] == 1 && vec[1] == 2 && vec[2] == 3 && "Initializer list values mismatch");
    }

    // Test case for constructor with initializer list (using only one value)
    {
        my_stl::vector<int> vec = {42};
        assert(vec.size() == 1 && "Size mismatch for initializer list constructor with single value");
        assert(vec.capacity() >= 1 && "Capacity mismatch for initializer list constructor with single value");
        assert(vec[0] == 42 && "Initializer list single value mismatch");
    }

    // Test case for constructor with size argument
    {
        my_stl::vector<int> my_vector(5);
        assert(my_vector.size() == 5 && "Size mismatch for constructor with size argument");
        assert(my_vector.capacity() >= 5 && "Capacity mismatch for constructor with size argument");
        for (size_t i = 0; i < my_vector.size(); ++i) {
            assert(my_vector[i] == 0 && "Default value mismatch for constructor with size argument");
        }
    }

    // Test case for constructor with size and value arguments
    {
        my_stl::vector<int> my_vector(5, 42);
        assert(my_vector.size() == 5 && "Size mismatch for constructor with size and value arguments");
        assert(my_vector.capacity() >= 5 && "Capacity mismatch for constructor with size and value arguments");
        for (size_t i = 0; i < my_vector.size(); ++i) {
            assert(my_vector[i] == 42 && "Value mismatch for constructor with size and value arguments");
        }
    }
}

void test_copy_constructor() {
    // Test case for copy constructor
    {
        // Create a vector with some initial values
        my_stl::vector<int> original_vector = {1, 2, 3, 4, 5};

        // Create a new vector by copying the original vector
        my_stl::vector<int> copied_vector(original_vector);

        // Check if the size of the copied vector matches the original
        assert(copied_vector.size() == original_vector.size() && "Size mismatch for copy constructor");

        // Check if the capacity of the copied vector matches the original
        assert(copied_vector.capacity() >= original_vector.size() && "Capacity mismatch for copy constructor");

        // Check if the values of the copied vector match the original
        for (size_t i = 0; i < original_vector.size(); ++i) {
            assert(copied_vector[i] == original_vector[i] && "Value mismatch for copy constructor");
        }
    }
}

void test_move_constructor() {
    // Test case for move constructor
    {
        // Create a vector with some initial values
        my_stl::vector<int> original_vector = {1, 2, 3, 4, 5};

        // Move construct a new vector from the original vector
        my_stl::vector<int> moved_vector(my_stl::move(original_vector));

        // Check if the size of the moved vector matches the original
        assert(moved_vector.size() == 5 && "Size mismatch for move constructor");

        // Check if the capacity of the moved vector matches the original
        assert(moved_vector.capacity() >= 5 && "Capacity mismatch for move constructor");

        // Check if the original vector has been moved (empty)
        assert(original_vector.size() == 0 && "Original vector should be empty after move");
        assert(original_vector.capacity() == 0 && "Original vector should have capacity 0 after move");
        assert(original_vector.data() == nullptr && "Original vector data pointer should be null after move");
    }
}

void test_at() {
    // Test case for reference at(size_type off) function (non-const)
    {
        my_stl::vector<int> my_vector = {1, 2, 3, 4, 5};

        // Accessing elements within valid range
        for (size_t i = 0; i < my_vector.size(); ++i) {
            assert(my_vector.at(i) == i + 1 && "Incorrect value retrieved using non-const at()");
        }

        // Accessing element out of range
        bool out_of_range_exception_thrown = false;
        try {
            int value = my_vector.at(my_vector.size());  // Accessing element out of range
        } catch (const my_stl::out_of_range& e) {
            out_of_range_exception_thrown = true;
        }
        assert(out_of_range_exception_thrown && "Failed to catch out_of_range exception for non-const at()");

        // Accessing element with negative index
        out_of_range_exception_thrown = false;
        try {
            int value = my_vector.at(-1);  // Accessing element with negative index
        } catch (const my_stl::out_of_range& e) {
            out_of_range_exception_thrown = true;
        }
        assert(out_of_range_exception_thrown && "Failed to catch out_of_range exception for non-const at()");
    }

    // Test case for const at() function
    {
        const my_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};

        // Accessing elements within valid range
        for (size_t i = 0; i < my_const_vector.size(); ++i) {
            assert(my_const_vector.at(i) == i + 1 && "Incorrect value retrieved using const at()");
        }

        // Accessing element out of range
        bool out_of_range_exception_thrown = false;
        try {
            int value = my_const_vector.at(my_const_vector.size());  // Accessing element out of range
        } catch (const my_stl::out_of_range& e) {
            out_of_range_exception_thrown = true;
        }
        assert(out_of_range_exception_thrown && "Failed to catch out_of_range exception for const at()");

        // Accessing element with negative index
        out_of_range_exception_thrown = false;
        try {
            int value = my_const_vector.at(-1);  // Accessing element with negative index
        } catch (const my_stl::out_of_range& e) {
            out_of_range_exception_thrown = true;
        }
        assert(out_of_range_exception_thrown && "Failed to catch out_of_range exception for const at()");
    }
}

void test_back() {
    // Test case for non-const back() function
    {
        my_stl::vector<int> my_vector = {1, 2, 3, 4, 5};

        // Check if the value returned by back() matches the last element of the vector
        assert(my_vector.back() == 5 && "Incorrect value retrieved using non-const back()");
    }

    // Test case for const back() function
    {
        const my_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};

        // Check if the value returned by back() matches the last element of the vector
        assert(my_const_vector.back() == 5 && "Incorrect value retrieved using const back()");
    }
}

void test_begin() {
    // Test case for non-const begin() function
    {
        my_stl::vector<int> my_vector = {1, 2, 3, 4, 5};

        // Check if the iterator points to the first element of the vector
        assert(*my_vector.begin() == 1 && "Incorrect value retrieved using non-const begin()");
    }

    // Test case for const begin() function
    {
        const my_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};

        // Check if the const iterator points to the first element of the vector
        assert(*my_const_vector.begin() == 1 && "Incorrect value retrieved using const begin()");
    }
}

void test_cbegin() {
    // Test case for cbegin() function
    {
        const my_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};
        // Check if the const iterator points to the first element of the vector
        assert(*my_const_vector.cbegin() == 1 && "Incorrect value retrieved using cbegin()");
    }
}

void test_rbegin() {
    // Test case for non-const rbegin() function
    {
        my_stl::vector<int> my_vector = {1, 2, 3, 4, 5};

        // Check if the reverse iterator points to the last element of the vector
        assert(*my_vector.rbegin() == 5 && "Incorrect value retrieved using non-const rbegin()");
    }

    // Test case for const rbegin() function
    {
        const my_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};

        // Check if the const reverse iterator points to the last element of the vector
        assert(*my_const_vector.rbegin() == 5 && "Incorrect value retrieved using const rbegin()");
    }
}

void test_crbegin() {
    // Test case for crbegin() function
    {
        const my_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};

        // Check if the const reverse iterator points to the last element of the vector
        assert(*my_const_vector.crbegin() == 5 && "Incorrect value retrieved using crbegin()");
    }
}

void test_end() {
    // Test case for non-const end() function
    {
        my_stl::vector<int> my_vector = {1, 2, 3, 4, 5};

        // Check if the iterator points to the past-the-end element of the vector
        assert(my_vector.end() == my_vector.data() + my_vector.size() && "Incorrect value retrieved using non-const end()");
    }

    // Test case for const end() function
    {
        const my_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};

        // Check if the const iterator points to the past-the-end element of the vector
        assert(my_const_vector.end() == my_const_vector.data() + my_const_vector.size() && "Incorrect value retrieved using const end()");
    }
}

void test_cend() {
    // Test case for cend() function
    {
        const my_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};

        // Check if the const iterator points to the past-the-end element of the vector
        assert(my_const_vector.cend() == my_const_vector.data() + my_const_vector.size() && "Incorrect value retrieved using cend()");
    }
}

void test_rend() {
    // Test case for rend() function
    {
        my_stl::vector<int> my_vector = {1, 2, 3, 4, 5};

        // Check if the reverse iterator points to the element before the first element of the vector
        assert(my_vector.rend() == my_stl::vector<int>::reverse_iterator(&my_vector[0] - 1) && "Incorrect value retrieved using rend()");
    }

    // Test case for const rend() function
    {
        const my_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};

        // Check if the const reverse iterator points to the element before the first element of the vector
        assert(my_const_vector.rend() == my_stl::vector<int>::const_reverse_iterator(&my_const_vector[0] - 1) && "Incorrect value retrieved using rend() const");
    }
}

void test_crend() {
    // Test case for crend() function
    {
        const my_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};

        // Check if the const reverse iterator points to the element before the first element of the vector
        assert(my_const_vector.crend() == my_stl::vector<int>::const_reverse_iterator(&my_const_vector[0] - 1) && "Incorrect value retrieved using crend() const");
    }
}

void test_data() {
    // Test case for data() function (non-const version)
    {
        my_stl::vector<int> my_vector = {1, 2, 3, 4, 5};

        // Check if the non-const data pointer points to the first element of the vector
        assert(my_vector.data() == &my_vector[0] && "Incorrect value retrieved using data()");
    }

    // Test case for data() function (const version)
    {
        const my_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};

        // Check if the const data pointer points to the first element of the vector
        assert(my_const_vector.data() == &my_const_vector[0] && "Incorrect value retrieved using data() const");
    }
}

void test_front() {
    // Test case for front() function (non-const version)
    {
        my_stl::vector<int> my_vector = {1, 2, 3, 4, 5};

        // Check if front() returns the correct reference to the first element of the vector
        assert(my_vector.front() == my_vector[0] && "Incorrect value retrieved using front()");
    }

    // Test case for front() function (const version)
    {
        const my_stl::vector<int> my_const_vector = {1, 2, 3, 4, 5};

        // Check if front() returns the correct const reference to the first element of the vector
        assert(my_const_vector.front() == my_const_vector[0] && "Incorrect value retrieved using front() const");
    }
}

void test_size() {
    // Test case 1: When vector is empty
    {
        my_stl::vector<int> empty_vector;
        assert(empty_vector.size() == 0 && "Incorrect size for an empty vector");
    }

    // Test case 2: When vector is partially filled
    {
        const size_t initial_size = 5;
        my_stl::vector<int> partially_filled_vector(initial_size);
        assert(partially_filled_vector.size() == initial_size && "Incorrect size for a partially filled vector");
    }

    // Test case 3: When vector is fully filled
    {
        const size_t max_capacity = 100; // Assuming a maximum capacity of 100
        my_stl::vector<int> fully_filled_vector(max_capacity);
        assert(fully_filled_vector.size() == max_capacity && "Incorrect size for a fully filled vector");
    }
}

void test_capacity() {
    // Test case 1: When vector is empty
    {
        my_stl::vector<int> empty_vector;
        assert(empty_vector.capacity() == 0 && "Incorrect capacity for an empty vector");
    }

    // Test case 2: When vector is partially filled
    {
        const size_t initial_size = 5;
        my_stl::vector<int> partially_filled_vector(initial_size);
        assert(partially_filled_vector.capacity() == initial_size && "Incorrect capacity for a partially filled vector");
    }

    // Test case 3: When vector is fully filled
    {
        const size_t max_capacity = 100; // Assuming a maximum capacity of 100
        my_stl::vector<int> fully_filled_vector(max_capacity);
        assert(fully_filled_vector.capacity() == max_capacity && "Incorrect capacity for a fully filled vector");
    }
}

void test_empty() {
    // Test case when vector is empty
    {
        my_stl::vector<int> empty_vector;
        assert(empty_vector.empty() && "Vector should be empty");
    }

    // Test case when vector is not empty
    {
        my_stl::vector<int> non_empty_vector = {1, 2, 3};
        assert(!non_empty_vector.empty() && "Vector should not be empty");
    }
}

void test_clear() {
    // Test case when vector is empty
    {
        my_stl::vector<int> empty_vector;
        empty_vector.clear();
        assert(empty_vector.empty() && "Vector should be empty after clear");
    }

    // Test case when vector is not empty
    {
        my_stl::vector<int> non_empty_vector = {1, 2, 3};
        non_empty_vector.clear();
        assert(non_empty_vector.empty() && "Vector should be empty after clear");
    }

    // Test case to check if size becomes 0 after clear
    {
        my_stl::vector<int> vector = {1, 2, 3};
        vector.clear();
        assert(vector.empty() && "Vector should be empty after clear");
        assert(vector.size() == 0 && "Size should be 0 after clear");
    }
}

void test_reserve() {
    // Test case when count is less than current capacity
    {
        my_stl::vector<int> vector = {1, 2, 3};
        auto old_capacity = vector.capacity();
        vector.reserve(old_capacity - 1);
        assert(vector.capacity() == old_capacity && "Capacity should not change if count is less than current capacity");
    }

    // Test case when count is greater than current capacity
    {
        my_stl::vector<int> vector = {1, 2, 3};
        auto old_capacity = vector.capacity();
        vector.reserve(old_capacity + 1);
        assert(vector.capacity() > old_capacity && "Capacity should increase if count is greater than current capacity");
    }

    // Test case when count is equal to current capacity
    {
        my_stl::vector<int> vector = {1, 2, 3};
        auto old_capacity = vector.capacity();
        vector.reserve(old_capacity);
        assert(vector.capacity() == old_capacity && "Capacity should remain unchanged if count is equal to current capacity");
    }
}

void test_resize() {
    // Test case when new size is less than current size
    {
        my_stl::vector<int> vector = {1, 2, 3};
        vector.resize(2);
        assert(vector.size() == 2 && "Size should be equal to the new size");
        assert(vector[0] == 1 && "First element should remain unchanged");
        assert(vector[1] == 2 && "Second element should remain unchanged");
    }

    // Test case when new size is greater than current size and less than capacity
    {
        my_stl::vector<int> vector = {1, 2, 3};
        vector.resize(5);
        assert(vector.size() == 5 && "Size should be equal to the new size");
        assert(vector[0] == 1 && "First element should remain unchanged");
        assert(vector[1] == 2 && "Second element should remain unchanged");
        assert(vector[2] == 3 && "Third element should remain unchanged");
        assert(vector[3] == 0 && "Newly added elements should be default initialized");
        assert(vector[4] == 0 && "Newly added elements should be default initialized");
    }

    // Test case when new size is greater than current capacity
    {
        my_stl::vector<int> vector = {1, 2, 3};
        vector.resize(10);
        assert(vector.size() == 10 && "Size should be equal to the new size");
        assert(vector[0] == 1 && "First element should remain unchanged");
        assert(vector[1] == 2 && "Second element should remain unchanged");
        assert(vector[2] == 3 && "Third element should remain unchanged");
        assert(vector[3] == 0 && "Newly added elements should be default initialized");
        assert(vector[4] == 0 && "Newly added elements should be default initialized");
        // Additional assertions for other elements being default initialized
    }
}

void test_shrink_to_fit() {
    // Test case when capacity is greater than size
    {
        my_stl::vector<int> vector = {1, 2, 3};
        auto old_capacity = vector.capacity();
        vector.shrink_to_fit();
        assert(vector.capacity() == vector.size() && "Capacity should be equal to size after shrinking");
        assert(vector.capacity() == old_capacity && "Capacity should remain unchanged if already less than or equal to size");
    }

    // Test case when capacity is equal to size
    {
        my_stl::vector<int> vector = {1, 2, 3};
        vector.reserve(10); // Increase capacity
        auto old_capacity = vector.capacity();
        vector.shrink_to_fit();
        assert(vector.capacity() == vector.size() && "Capacity should be equal to size after shrinking");
        assert(vector.capacity() < old_capacity && "Capacity should decrease after shrinking");
    }
}

void test_push_back() {
    // Test case for lvalue push_back()
    {
        my_stl::vector<int> vector = {1, 2, 3};
        vector.push_back(4);
        assert(vector.size() == 4 && "Size should be incremented after push_back()");
        assert(vector.back() == 4 && "Last element should be equal to the pushed value");
    }

    // Test case for rvalue push_back()
    {
        my_stl::vector<std::string> vector;
        std::string str = "hello";
        vector.push_back(std::move(str));
        assert(vector.size() == 1 && "Size should be incremented after push_back()");
        assert(vector.back() == "hello" && "Last element should be equal to the moved value");
        assert(str.empty() && "Original value should be moved from");
    }
}

void test_pop_back() {
    my_stl::vector<int> vector = {1, 2, 3};
    vector.pop_back();
    assert(vector.size() == 2 && "Size should be decremented after pop_back()");
    assert(vector.back() == 2 && "Last element should be the one before the popped element");
}

void test_emplace_back() {
    // Test case for emplacing an element with constructor arguments
    {
        my_stl::vector<std::string> vector;
        vector.emplace_back("hello");
        assert(vector.size() == 1 && "Size should be incremented after emplace_back()");
        assert(vector.back() == "hello" && "Last element should be constructed with provided arguments");
    }
}

void test_emplace() {
    // Test case for emplacing into an empty vector
    {
        my_stl::vector<int> vector;
        auto it = vector.emplace(vector.begin(), 42);
        assert(vector.size() == 1 && "Size should be incremented after emplacing into an empty vector");
        assert(*it == 42 && "Emplaced element should match the provided value");
    }

    // Test case for emplacing at the beginning of the vector
    {
        my_stl::vector<int> vector = {2, 3};
        auto it = vector.emplace(vector.begin(), 1);
        assert(vector.size() == 3 && "Size should be incremented after emplacing at the beginning");
        assert(*it == 1 && "Emplaced element should match the provided value");
        assert(vector.front() == 1 && "First element should be the emplaced value");
    }

    // Test case for emplacing at the middle of the vector
    {
        my_stl::vector<int> vector = {1, 3};
        auto it = vector.emplace(vector.begin() + 1, 2);
        assert(vector.size() == 3 && "Size should be incremented after emplacing at the middle");
        assert(*it == 2 && "Emplaced element should match the provided value");
        assert(vector[1] == 2 && "Element at the emplaced position should match the provided value");
    }
}

void test_subscript_operator() {
    // Test case for accessing elements using operator[] in a non-const vector
    {
        my_stl::vector<int> vector = {1, 2, 3, 4, 5};
        assert(vector[0] == 1 && "Accessing first element using operator[]");
        assert(vector[2] == 3 && "Accessing middle element using operator[]");
        assert(vector[4] == 5 && "Accessing last element using operator[]");

        vector[1] = 10;
        assert(vector[1] == 10 && "Modifying element using operator[]");
    }

    // Test case for accessing elements using operator[] in a const vector
    {
        const my_stl::vector<int> vector = {1, 2, 3, 4, 5};
        assert(vector[0] == 1 && "Accessing first element using const operator[]");
        assert(vector[2] == 3 && "Accessing middle element using const operator[]");
        assert(vector[4] == 5 && "Accessing last element using const operator[]");

        // Ensure that attempting to modify elements in a const vector fails to compile
        // vector[1] = 10; // This line should result in a compilation error
    }
}

void test_erase() {
    // Test case for erasing an element at the beginning of the vector
    {
        my_stl::vector<int> vector = {1, 2, 3, 4, 5};
        auto it = vector.erase(vector.begin());
        assert(vector.size() == 4 && "Size should be decremented after erasing an element");
        assert(*it == 2 && "Iterator returned by erase should point to the element after the erased one");
        assert(vector.front() == 2 && "First element should be updated after erasing");
    }

    // Test case for erasing an element in the middle of the vector
    {
        my_stl::vector<int> vector = {1, 2, 3, 4, 5};
        auto it = vector.erase(vector.begin() + 2);
        assert(vector.size() == 4 && "Size should be decremented after erasing an element");
        assert(*it == 4 && "Iterator returned by erase should point to the element after the erased one");
        assert(vector[2] == 4 && "Element at the erased position should be updated");
    }

    // Test case for erasing the last element of the vector
    {
        my_stl::vector<int> vector = {1, 2, 3, 4, 5};
        auto it = vector.erase(vector.end() - 1);
        assert(vector.size() == 4 && "Size should be decremented after erasing the last element");
        assert(it == vector.end() && "Iterator returned by erase should be end()");
    }

    // Test case for erasing a range of elements from the vector
    {
        my_stl::vector<int> vector = {1, 2, 3, 4, 5};
        auto it = vector.erase(vector.begin() + 1, vector.begin() + 3);
        assert(vector.size() == 3 && "Size should be decremented after erasing a range of elements");
        assert(*it == 4 && "Iterator returned by erase should point to the element after the erased range");
        assert(vector[1] == 4 && "Element after the erased range should be updated");
    }

    // Test case for erasing all elements from the vector
    {
        my_stl::vector<int> vector = {1, 2, 3, 4, 5};
        auto it = vector.erase(vector.begin(), vector.end());
        assert(vector.empty() && "Vector should be empty after erasing all elements");
        assert(it == vector.end() && "Iterator returned by erase should be end()");
    }
}

void test_assignment_operator() {
    // Test case for assigning a vector to another vector
    {
        my_stl::vector<int> original = {1, 2, 3, 4, 5};
        my_stl::vector<int> assigned;
        assigned = original;

        // Verify that the size and capacity of the assigned vector match the original
        assert(assigned.size() == original.size() && "Size of assigned vector should match original");
        assert(assigned.capacity() == original.capacity() && "Capacity of assigned vector should match original");

        // Verify that the elements of the assigned vector match the elements of the original vector
        for (size_t i = 0; i < original.size(); ++i) {
            assert(assigned[i] == original[i] && "Elements of assigned vector should match original");
        }
    }
    // Test case for move assigning a vector to another vector
    {
        my_stl::vector<int> original = {1, 2, 3, 4, 5};
        my_stl::vector<int> moved;
        moved = my_stl::move(original);

        // Verify that the moved vector has taken ownership of the original vector's resources
        assert(moved.size() == 5 && "Size of moved vector should match original");
        assert(moved.capacity() >= 5 && "Capacity of moved vector should be at least original size");

        // Verify that the original vector is in a valid but unspecified state
        assert(original.size() == 0 && "Size of original vector should be 0 after move assignment");
        assert(original.capacity() == 0 && "Capacity of original vector should be 0 after move assignment");
        assert(original.data() == nullptr && "Data pointer of original vector should be nullptr after move assignment");
    }
}

void test_equality_operator() {
    // Test case for comparing two equal vectors
    {
        my_stl::vector<int> vector1 = {1, 2, 3, 4, 5};
        my_stl::vector<int> vector2 = {1, 2, 3, 4, 5};
        assert(vector1 == vector2 && "Equal vectors should return true");
    }

    // Test case for comparing two unequal vectors
    {
        my_stl::vector<int> vector1 = {1, 2, 3};
        my_stl::vector<int> vector2 = {1, 2, 4};
        assert(!(vector1 == vector2) && "Unequal vectors should return false");
    }

    // Test case for comparing vectors with different sizes
    {
        my_stl::vector<int> vector1 = {1, 2, 3};
        my_stl::vector<int> vector2 = {1, 2, 3, 4, 5};
        assert(!(vector1 == vector2) && "Vectors with different sizes should return false");
    }
}

void test_inequality_operator() {
    // Test case for comparing two equal vectors
    {
        my_stl::vector<int> vector1 = {1, 2, 3, 4, 5};
        my_stl::vector<int> vector2 = {1, 2, 3, 4, 5};
        assert(!(vector1 != vector2) && "Equal vectors should return false for operator!=");
    }

    // Test case for comparing two unequal vectors
    {
        my_stl::vector<int> vector1 = {1, 2, 3};
        my_stl::vector<int> vector2 = {1, 2, 4};
        assert(vector1 != vector2 && "Unequal vectors should return true for operator!=");
    }

    // Test case for comparing vectors with different sizes
    {
        my_stl::vector<int> vector1 = {1, 2, 3};
        my_stl::vector<int> vector2 = {1, 2, 3, 4, 5};
        assert(vector1 != vector2 && "Vectors with different sizes should return true for operator!=");
    }
}

void test_less_than_operator() {
    // Test case for comparing two vectors where the first is less than the second
    {
        my_stl::vector<int> vector1 = {1, 2, 3};
        my_stl::vector<int> vector2 = {1, 2, 4};
        assert(vector1 < vector2 && "First vector should be less than the second");
    }

    // Test case for comparing two vectors where the first is greater than the second
    {
        my_stl::vector<int> vector1 = {1, 2, 4};
        my_stl::vector<int> vector2 = {1, 2, 3};
        assert(!(vector1 < vector2) && "First vector should not be less than the second");
    }

    // Test case for comparing two vectors where the first is equal to the second
    {
        my_stl::vector<int> vector1 = {1, 2, 3};
        my_stl::vector<int> vector2 = {1, 2, 3};
        assert(!(vector1 < vector2) && "Equal vectors should not return true for operator<");
    }
}

void test_greater_than_operator() {
    // Test case for comparing two vectors where the first is greater than the second
    {
        my_stl::vector<int> vector1 = {1, 2, 4};
        my_stl::vector<int> vector2 = {1, 2, 3};
        assert(vector1 > vector2 && "First vector should be greater than the second");
    }

    // Test case for comparing two vectors where the first is less than the second
    {
        my_stl::vector<int> vector1 = {1, 2, 3};
        my_stl::vector<int> vector2 = {1, 2, 4};
        assert(!(vector1 > vector2) && "First vector should not be greater than the second");
    }

    // Test case for comparing two vectors where the first is equal to the second
    {
        my_stl::vector<int> vector1 = {1, 2, 3};
        my_stl::vector<int> vector2 = {1, 2, 3};
        assert(!(vector1 > vector2) && "Equal vectors should not return true for operator>");
    }
}

void test_operator_less_than_or_equal_operator() {
    // Test case for comparing two vectors where the first is less than the second
    {
        my_stl::vector<int> vector1 = {1, 2, 3};
        my_stl::vector<int> vector2 = {1, 2, 4};
        assert(vector1 <= vector2 && "First vector should be less than or equal to the second");
    }

    // Test case for comparing two vectors where the first is greater than the second
    {
        my_stl::vector<int> vector1 = {1, 2, 4};
        my_stl::vector<int> vector2 = {1, 2, 3};
        assert(!(vector1 <= vector2) && "First vector should not be less than or equal to the second");
    }

    // Test case for comparing two vectors where the first is equal to the second
    {
        my_stl::vector<int> vector1 = {1, 2, 3};
        my_stl::vector<int> vector2 = {1, 2, 3};
        assert(vector1 <= vector2 && "Equal vectors should return true for operator<=");
    }
}

void test_greater_than_or_equal_operator() {
    // Test case for comparing two vectors where the first is greater than the second
    {
        my_stl::vector<int> vector1 = {1, 2, 4};
        my_stl::vector<int> vector2 = {1, 2, 3};
        assert(vector1 >= vector2 && "First vector should be greater than or equal to the second");
    }

    // Test case for comparing two vectors where the first is less than the second
    {
        my_stl::vector<int> vector1 = {1, 2, 3};
        my_stl::vector<int> vector2 = {1, 2, 4};
        assert(!(vector1 >= vector2) && "First vector should not be greater than or equal to the second");
    }

    // Test case for comparing two vectors where the first is equal to the second
    {
        my_stl::vector<int> vector1 = {1, 2, 3};
        my_stl::vector<int> vector2 = {1, 2, 3};
        assert(vector1 >= vector2 && "Equal vectors should return true for operator>=");
    }
}

void test_vector() {
    test_constructor();
    test_copy_constructor();
    test_move_constructor();
    test_at();
    test_back();
    test_begin();
    test_cbegin();
    test_rbegin();
    test_crbegin();
    test_end();
    test_cend();
    test_rend();
    test_crend();
    test_data();
    test_front();
    test_size();
    test_capacity();
    test_empty();
    test_clear();
    test_reserve();
    test_resize();
    test_shrink_to_fit();
    test_push_back();
    test_pop_back();
    test_emplace_back();
    test_emplace();
    test_subscript_operator();
    test_erase();
    test_assignment_operator();
    test_equality_operator();
    test_inequality_operator();
    test_less_than_operator();
    test_greater_than_operator();
    test_operator_less_than_or_equal_operator();
    test_greater_than_or_equal_operator();
}

int main() {
    test_vector();
    std::cout << "All tests passed!" << std::endl;
}

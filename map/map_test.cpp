#include <iostream>
#include <cassert>
#include <string>

#include "map.hpp"

void test_constructor() {
    // Test default constructor
    {
        my_stl::map<int, std::string> my_map;
        assert(my_map.size() == 0); // Ensure map is empty after default construction
    }

    // Test initializer list constructor
    {
        my_stl::map<int, std::string> my_map = {{1, "one"}, {2, "two"}, {3, "three"}};
        assert(my_map.size() == 3); // Ensure correct size after initialization
        assert(my_map[1] == "one"); // Ensure correct key-value pairs
        assert(my_map[2] == "two");
        assert(my_map[3] == "three");
    }
}

void test_insert() {
    // Test insert(const value_type& val)
    {
        my_stl::map<int, std::string> my_map;

        // Insert a single element
        my_map.insert({1, "one"});

        // Check if the element is inserted correctly
        assert(my_map.size() == 1);
        assert(my_map[1] == "one");
    }

    // Test insert(const std::initializer_list<value_type>& values)
    {
        my_stl::map<int, std::string> my_map;

        // Insert multiple elements using initializer list
        my_map.insert({{1, "one"}, {2, "two"}, {3, "three"}});

        // Check if all elements are inserted correctly
        assert(my_map.size() == 3);
        assert(my_map[1] == "one");
        assert(my_map[2] == "two");
        assert(my_map[3] == "three");
    }
}

void test_erase() {
    // Test erase with existing key
    {
        my_stl::map<int, std::string> my_map = {{1, "one"}, {2, "two"}, {3, "three"}};

        // Erase an existing key
        my_map.erase(2);

        // Check if the element is erased correctly
        assert(my_map.size() == 2);
        try {
            std::string value = my_map[2];
            assert(false); // Should not reach here
        } catch (const my_stl::runtime_error& err) {
            // Expected exception, do nothing
        }
    }

    // Test erase with non-existing key
    {
        my_stl::map<int, std::string> my_map = {{1, "one"}, {2, "two"}, {3, "three"}};

        // Erase a non-existing key
        my_map.erase(4);

        // Check if the map remains unchanged
        assert(my_map.size() == 3);
        try {
            std::string value = my_map[4];
            assert(false); // Should not reach here
        } catch (const my_stl::runtime_error& err) {
            // Expected exception, do nothing
        }
    }
}

void test_iterators() {
    // Test iterator and const_iterator
    {
        my_stl::map<int, std::string> my_map = {{1, "one"}, {2, "two"}, {3, "three"}};

        // Test iterator
        int expected_key = 1;
        for (auto it = my_map.begin(); it != my_map.end(); ++it) {
            assert((*it).m_key == expected_key);
            assert((*it).m_value  == my_map[expected_key]);
            ++expected_key;
        }
    }
}

int main() {
    test_constructor();
    test_insert();
    test_erase();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}

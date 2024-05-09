#include <cassert>
#include <iostream>
#include <array>

#include "array.hpp"
#include "../utility/move.hpp"
#include "../utility/typedefs.hpp"
#include "../exceptions/out_of_range/out_of_range.hpp"

void test_constructor() {
    // Test case for default constructor
    {
        my_stl::array<int, 5> arr;
        assert(arr.size() == 5 && "Size mismatch for default constructor");
        for (int i = 0; i < 5; ++i) {
            assert(arr[i] == 0 && "Default value mismatch");
        }
    }
    // Test case for constructor with initializer list
    {
        my_stl::array<int, 3> arr = {1, 2, 3};
        assert(arr.size() == 3 && "Size mismatch for initializer list constructor");
        assert(arr[0] == 1 && arr[1] == 2 && arr[2] == 3 && "Initializer list values mismatch");
    }

    // Test case for constructor with initializer list (using only one value)
    {
        my_stl::array<int, 5> arr = {42};
        assert(arr.size() == 5 && "Size mismatch for initializer list constructor with single value");
        assert(arr[0] == 42 && "Initializer list single value mismatch");
    }
}

void test_copy_constructor() {
    // Create a source array
    const my_stl::array<int, 5> source = {1, 2, 3, 4, 5};
    
    // Create a destination array using the copy constructor
    const my_stl::array<int, 5> destination(source);
    
    // Verify that the destination array has the same values as the source array
    for (my_stl::size_type i = 0; i < source.size(); ++i) {
        assert(destination[i] == source[i] && "Copy constructor failed to copy elements");
    }
}

void test_move_constructor() {
    // Create a source array
    my_stl::array<int, 5> source = {1, 2, 3, 4, 5};
    
    // Move from source to destination
    my_stl::array<int, 5> destination(move(source));
    
    // Verify that destination has the correct values
    for (my_stl::size_type i = 0; i < destination.size(); ++i) {
        assert(destination[i] == (i + 1) && "Move constructor failed to move elements");
    }

    // Verify that source is in a valid but unspecified state
    for (my_stl::size_type i = 0; i < source.size(); ++i) {
        assert(source[i] == 0 && "Source array is not in a valid state after move");
    }
}

void test_at() {
    // Test case for accessing elements within bounds
    {
        my_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
        try {
            for (int i = 0; i < 5; ++i) {
                assert(arr.at(i) == i + 1 && "Element access within bounds mismatch");
            }
        } catch (const std::out_of_range& e) {
            assert(false && "Exception thrown for valid index access");
        }
    }

    // Test case for accessing elements with negative index
    {
        my_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
        try {
            arr.at(-1);
            assert(false && "No exception thrown for negative index access");
        } catch (const my_stl::out_of_range& e) {
            assert(true && "Exception thrown for negative index access");
        }
    }

    // Test case for accessing elements beyond bounds
    {
        my_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
        try {
            arr.at(5);
            assert(false && "No exception thrown for index out of bounds access");
        } catch (const my_stl::out_of_range& e) {
            assert(true && "Exception thrown for index out of bounds access");
        }
    }
}

void test_back() {
    // Test case for accessing the last element in a non-empty array
    {
        my_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
        assert(arr.back() == 5 && "Last element access mismatch in non-empty array");
    }

    // Test case for accessing the last element in a non-empty const array
    {
        const my_stl::array<int, 3> arr = {10, 20, 30};
        assert(arr.back() == 30 && "Last element access mismatch in non-empty const array");
    }

    // Test case for accessing the last element in an array with one element
    {
        my_stl::array<int, 1> arr = {42};
        assert(arr.back() == 42 && "Last element access mismatch in array with one element");
    }

    // Test case for accessing the last element in a const array with one element
    {
        const my_stl::array<int, 1> arr = {99};
        assert(arr.back() == 99 && "Last element access mismatch in const array with one element");
    }
}

void test_begin() {
    // Test case for iterator begin()
    {
        my_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
        auto it = arr.begin();
        assert(*it == 1 && "Begin iterator points to the wrong element");
    }

    // Test case for const_iterator begin() const
    {
        const my_stl::array<int, 5> arr = {10, 20, 30, 40, 50};
        auto it = arr.begin();
        assert(*it == 10 && "Const begin iterator points to the wrong element");
    }
}

void test_cbegin() {
    // Test case for cbegin() - const_iterator pointing to the first element
    const my_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
    auto it = arr.cbegin();
    assert(*it == 1 && "cbegin() points to the wrong element");
}

void test_crbegin() {
    // Test case for crbegin() - const_reverse_iterator pointing to the last element
    const my_stl::array<int, 5> arr = {10, 20, 30, 40, 50};
    auto it = arr.crbegin();
    assert(*it == 50 && "crbegin() points to the wrong element");
}

void test_cend() {
    // Test case for cend() - const_iterator pointing to the element following the last element
    const my_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
    auto it = arr.cend();
    assert(it == &arr[5] && "cend() points to the wrong element");
}

void test_crend() {
    // Test case for crend() - const_reverse_iterator pointing to the element preceding the first element
    const my_stl::array<int, 5> arr = {1, 2, 3, 4, 5};
    auto it = arr.crend();
    --it;
    assert(*it == 1 && "crend() points to the wrong element");
}

void test_data() {
    // Test case for non-const data() method
    {
        my_stl::array<int, 3> arr = {1, 2, 3};
        my_stl::array<int, 3>::pointer ptr = arr.data();
        assert(ptr == &arr[0] && "Non-const data() method returned incorrect pointer");
    }

    // Test case for const data() method
    {
        const my_stl::array<int, 3> arr = {1, 2, 3};
        my_stl::array<int, 3>::const_pointer const_ptr = arr.data();
        assert(const_ptr == &arr[0] && "Const data() method returned incorrect pointer");
    }
}

void test_end() {
    // Test case for non-const end() method
    {
        my_stl::array<int, 3> arr = {1, 2, 3};
        auto it = arr.end();
        assert(it == &arr[3] && "Non-const end() method returned incorrect iterator");
    }

    // Test case for const end() method
    {
        const my_stl::array<int, 3> arr = {1, 2, 3};
        auto it = arr.end();
        assert(it == &arr[3] && "Const end() method returned incorrect iterator");
    }
}

void test_empty() {
    // Test case for non-empty array
    {
        my_stl::array<int, 3> arr = {1, 2, 3};
        assert(!arr.empty() && "Non-empty array wrongly identified as empty");
    }

    // Test case for empty array
    {
        my_stl::array<int, 0> arr;
        assert(arr.empty() && "Empty array wrongly identified as non-empty");
    }
}

void test_front() {
    // Test case for non-const front() method
    {
        my_stl::array<int, 3> arr = {1, 2, 3};
        assert(arr.front() == 1 && "Non-const front() method returned incorrect value");
    }

    // Test case for const front() method
    {
        const my_stl::array<int, 3> arr = {1, 2, 3};
        assert(arr.front() == 1 && "Const front() method returned incorrect value");
    }
}

void test_max_size() {
    // Test case for max_size() method
    {
        constexpr size_t N = 10;
        my_stl::array<int, N> arr;
        assert(arr.max_size() == N && "max_size() returned incorrect value");
    }
}

void test_rbegin() {
    // Test case for non-const rbegin() method
    {
        my_stl::array<int, 3> arr = {1, 2, 3};
        auto rit = arr.rbegin();
        assert(*rit == 3 && "Non-const rbegin() method returned incorrect iterator");
    }

    // Test case for const rbegin() method
    {
        const my_stl::array<int, 3> arr = {1, 2, 3};
        auto rit = arr.rbegin();
        assert(*rit == 3 && "Const rbegin() method returned incorrect iterator");
    }
}

void test_rend() {
    // Test case for non-const rend() method
    {
        my_stl::array<int, 3> arr = {1, 2, 3};
        auto rit = arr.rend();
        assert(rit != arr.rbegin() && "Non-const rend() method returned incorrect iterator");
    }

    // Test case for const rend() method
    {
        const my_stl::array<int, 3> arr = {1, 2, 3};
        auto rit = arr.rend();
        assert(rit != arr.rbegin() && "Const rend() method returned incorrect iterator");
    }
}

void test_size() {
    // Test case for size() method
    {
        constexpr size_t N = 5;
        my_stl::array<int, N> arr;
        assert(arr.size() == N && "size() method returned incorrect value");
    }
}

void test_fill() {
    // Test case for fill() method
    {
        constexpr size_t N = 5;
        my_stl::array<int, N> arr;
        arr.fill(42);
        for (size_t i = 0; i < N; ++i) {
            assert(arr[i] == 42 && "fill() method did not assign correct value to all elements");
        }
    }
}

void test_swap() {
    // Test case for swap() method
    {
        constexpr size_t N = 5;
        my_stl::array<int, N> arr1 = {1, 2, 3, 4, 5};
        my_stl::array<int, N> arr2 = {6, 7, 8, 9, 10};

        arr1.swap(arr2);

        for (size_t i = 0; i < N; ++i) {
            assert(arr1[i] == (int)(i + 6) && "swap() method did not swap elements correctly");
            assert(arr2[i] == (int)(i + 1) && "swap() method did not swap elements correctly");
        }
    }
}

void test_subscript_operator() {
    // Test case for non-const operator[] method
    {
        my_stl::array<int, 3> arr = {1, 2, 3};
        assert(arr[1] == 2 && "Non-const operator[] method returned incorrect value");
    }

    // Test case for const operator[] method
    {
        const my_stl::array<int, 3> arr = {1, 2, 3};
        assert(arr[1] == 2 && "Const operator[] method returned incorrect value");
    }
}

void test_assignment_operator() {
    // Test case for assignment operator
    {
        constexpr size_t N = 5;
        my_stl::array<int, N> arr1 = {1, 2, 3, 4, 5};
        my_stl::array<int, N> arr2 = {6, 7, 8, 9, 10};

        arr1 = arr2;

        for (size_t i = 0; i < N; ++i) {
            assert(arr1[i] == arr2[i] && "Assignment operator did not assign elements correctly");
        }
    }
}

void test_move_assignment_operator() {
    // Test case for move assignment operator
    {
        constexpr size_t N = 5;
        my_stl::array<int, N> arr1 = {1, 2, 3, 4, 5};
        my_stl::array<int, N> arr2 = {6, 7, 8, 9, 10};

        arr1 = move(arr2);

        for (size_t i = 0; i < N; ++i) {
            assert(arr1[i] == (int)(i + 6) && "Move assignment operator did not move elements correctly");
        }
    }
}

void test_equality_operator() {
    // Test case for equality operator
    {
        constexpr size_t N = 5;
        my_stl::array<int, N> arr1 = {1, 2, 3, 4, 5};
        my_stl::array<int, N> arr2 = {1, 2, 3, 4, 5};
        my_stl::array<int, N> arr3 = {6, 7, 8, 9, 10};

        assert(arr1 == arr2 && "Equality operator did not compare arrays correctly");
        assert(!(arr1 == arr3) && "Equality operator did not compare arrays correctly");
    }
}

void test_inequality_operator() {
    // Test case for inequality operator
    {
        constexpr size_t N = 5;
        my_stl::array<int, N> arr1 = {1, 2, 3, 4, 5};
        my_stl::array<int, N> arr2 = {1, 2, 3, 4, 5};
        my_stl::array<int, N> arr3 = {6, 7, 8, 9, 10};

        assert(!(arr1 != arr2) && "Inequality operator did not compare arrays correctly");
        assert(arr1 != arr3 && "Inequality operator did not compare arrays correctly");
    }
}

void test_less_than_operator() {
    // Test case for less than operator with arrays of same values but different sizes
    {
        constexpr size_t N = 5;
        my_stl::array<int, N> arr1 = {1, 2, 3, 4, 5};
        my_stl::array<int, N> arr2 = {1, 2, 3};
        assert(!(arr1 < arr2) && "Less than operator did not compare arrays correctly");
    }

    // Test case for less than operator with arrays of different values and same sizes
    {
        constexpr size_t N = 5;
        my_stl::array<int, N> arr1 = {1, 2, 3, 4, 5};
        my_stl::array<int, N> arr2 = {1, 2, 3, 4, 6};

        assert(arr1 < arr2 && "Less than operator did not compare arrays correctly");
    }

    // Test case for less than operator with arrays having common prefix
    {
        constexpr size_t N = 5;
        my_stl::array<int, N> arr1 = {1, 2, 3, 4, 5};
        my_stl::array<int, N> arr2 = {1, 2, 3, 5, 6};

        assert(arr1 < arr2 && "Less than operator did not compare arrays correctly");
    }

    // Test case for less than operator with arrays of equal values
    {
        constexpr size_t N = 5;
        my_stl::array<int, N> arr1 = {1, 2, 3, 4, 5};
        my_stl::array<int, N> arr2 = {1, 2, 3, 4, 5};

        assert(!(arr1 < arr2) && "Less than operator did not compare arrays correctly");
    }
}

void test_greater_than_operator() {
    // Test case for greater than operator with arrays of same values but different sizes
    {
        constexpr size_t N = 5;
        my_stl::array<int, N> arr1 = {1, 2, 3, 4, 5};
        my_stl::array<int, N> arr2 = {1, 2, 3};

        assert(arr1 > arr2 && "Greater than operator did not compare arrays correctly");
    }

    // Test case for greater than operator with arrays of different values and same sizes
    {
        constexpr size_t N = 5;
        my_stl::array<int, N> arr1 = {1, 2, 3, 4, 5};
        my_stl::array<int, N> arr2 = {1, 2, 3, 4, 6};

        assert(!(arr1 > arr2) && "Greater than operator did not compare arrays correctly");
    }

    // Test case for greater than operator with arrays having common prefix
    {
        constexpr size_t N = 5;
        my_stl::array<int, N> arr1 = {1, 2, 3, 4, 5};
        my_stl::array<int, N> arr2 = {1, 2, 3, 5, 6};

        assert(!(arr1 > arr2) && "Greater than operator did not compare arrays correctly");
    }

    // Test case for greater than operator with arrays of equal values
    {
        constexpr size_t N = 5;
        my_stl::array<int, N> arr1 = {1, 2, 3, 4, 5};
        my_stl::array<int, N> arr2 = {1, 2, 3, 4, 5};

        assert(!(arr1 > arr2) && "Greater than operator did not compare arrays correctly");
    }
}

void test_less_than_or_equal_to_operator() {
    // Test case for less than or equal to operator with arrays of same values but different sizes
    {
        constexpr size_t N = 5;
        my_stl::array<int, N> arr1 = {1, 2, 3, 4, 5};
        my_stl::array<int, N> arr2 = {1, 2, 3};

        assert(!(arr1 <= arr2) && "Less than or equal to operator did not compare arrays correctly");
    }

    // Test case for less than or equal to operator with arrays of different values and same sizes
    {
        constexpr size_t N = 5;
        my_stl::array<int, N> arr1 = {1, 2, 3, 4, 5};
        my_stl::array<int, N> arr2 = {1, 2, 3, 4, 6};

        assert(arr1 <= arr2 && "Less than or equal to operator did not compare arrays correctly");
    }

    // Test case for less than or equal to operator with arrays having common prefix
    {
        constexpr size_t N = 5;
        my_stl::array<int, N> arr1 = {1, 2, 3, 4, 5};
        my_stl::array<int, N> arr2 = {1, 2, 3, 5, 6};

        assert(arr1 <= arr2 && "Less than or equal to operator did not compare arrays correctly");
    }

    // Test case for less than or equal to operator with arrays of equal values
    {
        constexpr size_t N = 5;
        my_stl::array<int, N> arr1 = {1, 2, 3, 4, 5};
        my_stl::array<int, N> arr2 = {1, 2, 3, 4, 5};

        assert(arr1 <= arr2 && "Less than or equal to operator did not compare arrays correctly");
    }
}

void test_greater_than_or_equal_to_operator() {
    // Test case for greater than or equal to operator with arrays of same values but different sizes
    {
        constexpr size_t N = 5;
        my_stl::array<int, N> arr1 = {1, 2, 3, 4, 5};
        my_stl::array<int, N> arr2 = {1, 2, 3};

        assert(arr1 >= arr2 && "Greater than or equal to operator did not compare arrays correctly");
    }

    // Test case for greater than or equal to operator with arrays of different values and same sizes
    {
        constexpr size_t N = 5;
        my_stl::array<int, N> arr1 = {1, 2, 3, 4, 5};
        my_stl::array<int, N> arr2 = {1, 2, 3, 4, 6};

        assert(!(arr1 >= arr2) && "Greater than or equal to operator did not compare arrays correctly");
    }

    // Test case for greater than or equal to operator with arrays having common prefix
    {
        constexpr size_t N = 5;
        my_stl::array<int, N> arr1 = {1, 2, 3, 4, 5};
        my_stl::array<int, N> arr2 = {1, 2, 3, 5, 6};

        assert(!(arr1 >= arr2) && "Greater than or equal to operator did not compare arrays correctly");
    }

    // Test case for greater than or equal to operator with arrays of equal values
    {
        constexpr size_t N = 5;
        my_stl::array<int, N> arr1 = {1, 2, 3, 4, 5};
        my_stl::array<int, N> arr2 = {1, 2, 3, 4, 5};

        assert(arr1 >= arr2 && "Greater than or equal to operator did not compare arrays correctly");
    }
}

void test_array() {
    test_constructor();
    test_copy_constructor();
    test_move_constructor();
    test_at();
    test_back();
    test_begin();
    test_cbegin();
    test_crbegin();
    test_cend();
    test_crend();
    test_data();
    test_end();
    test_empty();
    test_front();
    test_max_size();
    test_rbegin();
    test_rend();
    test_size();
    test_fill();
    test_swap();
    test_subscript_operator();
    test_assignment_operator();
    test_move_assignment_operator();
    test_equality_operator();
    test_inequality_operator();
    test_less_than_operator();
    test_greater_than_operator();
    test_less_than_or_equal_to_operator();
    test_greater_than_or_equal_to_operator();
}

int main() {
    test_array();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}

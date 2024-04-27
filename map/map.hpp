#include <iostream>
#include <cassert>

int main() {
    // Create an instance of your map
    map<int, std::string> myMap;

    // Insert some key-value pairs
    myMap.insert(1, "One");
    myMap.insert(2, "Two");
    myMap.insert(3, "Three");

    // Verify insertion
    assert(myMap[1] == "One");
    assert(myMap[2] == "Two");
    assert(myMap[3] == "Three");

    // Erase a key-value pair
    myMap.erase(2);

    // Verify deletion
    assert(myMap[2] == ""); // Assuming VALUE_TYPE is string, so default-constructed value is an empty string

    // Try to access a non-existent key
    // This should throw an assertion failure
    // Uncomment the line below to see the assertion failure
    // assert(myMap[2] == "Two");

    std::cout << "All assertions passed!\n";

    return 0;
}

#pragma once

#include "../utility/move.hpp"

namespace my_stl
{
// Forward declaration of forward_list and forward_list_iterator classes
template<typename T>
class forward_list;

template<typename Forward_list>
class forward_list_iterator;

// Class template for forward_list_node
template<typename T>
class forward_list_node {
public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    
    // Default constructor: Initializes data with default value and next pointer to nullptr
    forward_list_node<value_type>() : 
        data(value_type()),
        next(nullptr) 
    {}

    // Constructor with data: Initializes data with the provided value and next pointer to nullptr
    forward_list_node<value_type>(const_reference data) : 
        data(data), 
        next(nullptr) 
    {}

    // Move constructor: Initializes data by moving the provided value and next pointer to nullptr
    forward_list_node<value_type>(value_type&& data) : 
        data(move(data)), 
        next(nullptr) 
    {}

    // Constructor with data and next node pointer: Initializes data with the provided value and next pointer with the provided node
    forward_list_node<value_type>(const_reference data, forward_list_node<value_type>* next) : 
        data(data), 
        next(next) 
    {}

    // Move constructor with data and next node pointer: Initializes data by moving the provided value and next pointer with the provided node
    forward_list_node<value_type>(value_type&& data, forward_list_node<value_type>* next) : 
        data(move(data)), 
        next(next) 
    {}

    // Friendship declarations to allow access to private members by forward_list and forward_list_iterator classes
    friend class forward_list<value_type>;
    friend class forward_list_iterator<forward_list<value_type>>;
    friend class forward_list_iterator<const forward_list<value_type>>;
private:
    value_type data;
    forward_list_node<value_type>* next;
};
} // namespace my_stl
